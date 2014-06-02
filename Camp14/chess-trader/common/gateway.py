import threading
import socket
import Queue
import time
import os

from order import Order
from messages import *
import book
from log import log

class Messenger:
    """
    Allow basic messaging over TCP, which is stream based. When we recv() from the
    socket, we may not get a complete message, so we need to buffer and keep issuing
    recv() until we get one whole message to return, keeping any remainder in the buffer.

    For simplicity, this class uses fixed-size messages.
    """
    SIZE = 64
    def __init__(self, socket):
        self.socket     = socket
        self.recvBuffer = ""

    def recvMessage(self):
        """Block and return one message of size Message.SIZE, with trailing whitespace stripped."""
        while len(self.recvBuffer) < Messenger.SIZE:
            data = self.socket.recv(1024)
            log.info("data: " + data)
            if data == "": return None
            self.recvBuffer += data
        if len(self.recvBuffer) >= Messenger.SIZE:
            m = self.recvBuffer[:Messenger.SIZE]
            self.recvBuffer = self.recvBuffer[Messenger.SIZE:]
            return m.rstrip()

    def sendMessage(self, msg):
        """
        Send one message, fragmenting if needed. Note that TCP is receiver-paced, so this
        function could block for a long time when the other-side receiver is slow. The
        Gateway class handles this with a queue and a separate thread.
        """
        assert len(msg) <= Messenger.SIZE
        msg = ("%-" + str(Messenger.SIZE) + "s") % msg
        assert len(msg) == Messenger.SIZE
        totalSent = 0
        while totalSent < Messenger.SIZE:
            sent = self.socket.send(msg[totalSent:])
            log.info("sent: %d" % sent)
            if sent == 0: return False
            totalSent += sent
        return True

    def close(self):
        """Shutdown and close the socket being used for messaging."""
        try:
            self.socket.shutdown(socket.SHUT_RDWR)
            self.socket.close()
        except socket.error:
            pass

class Listener:
    """
    Anyone wishing to listen to a Gateway should implement this interface by inheriting from it.
    If Gateway is constructed with listeners, it checks that they all inherit from this class.
    """
    def onGatewayMessage(self, gateway, message):
        """
        When the Gateway receives a message, it will generate this callback to any listeners.
        The information passed includes the gateway itself, and the (parsed) message.
        """
        pass

class Gateway:
    """
    Handle all private communications between a strategy and the exchange, including order send,
    rejection, acknowledgement, trade, cancel, and cancel acknowledgement messages. Relies on
    the CHESS_GATEWAY environment variable to be set correctly when running in client mode.
    """
    HOST = os.getenv("CHESS_GATEWAY", "localhost")
    PORT = 9999
    def __init__(self, name=None, sock=None, listeners=None):
        self.clientMode = (sock is None)
        self.name       = name
        self.liveOrders = None
        self.pos        = None

        ## keep track of pending orders
        self.pendingLock    = threading.Lock()
        self.pendingOrders  = dict()
        self.pendingCancels = set()

        ## verify that listeners are of the correct class
        self.listeners = listeners if listeners is not None else []
        for L in self.listeners:
            assert isinstance(L, Listener)

        ## only need thread if we have listeners
        thread = len(self.listeners) > 0

        if self.clientMode:
            assert self.name is not None
            self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.socket.connect((Gateway.HOST, Gateway.PORT))
            self.liveOrders = book.Book()
            self.liveOrders.needRecovery = False
            self.pos = 0
            self.goid = 99000
        else:
            self.socket = sock
            assert not thread

        ## handle fragmented TCP messaging as documented in Messenger class
        self.messenger = Messenger(self.socket)

        ## need queues to handle inbound and outbound messaging because TCP is
        ## receiver-paced, and we would otherwise risk holding up ourselves on
        ## outbound messages, or the other side on inbound messages
        self.inboundQueue  = Queue.Queue()
        self.outboundQueue = Queue.Queue()

        self.inboundThread  = threading.Thread(target=self.handleInboundMessages )
        self.outboundThread = threading.Thread(target=self.handleOutboundMessages)

        self.inboundThread.daemon = True
        self.outboundThread.daemon = True

        if thread:
            ## client thread will deliver callbacks
            assert self.clientMode
            self.thread = threading.Thread(target=self.runClient)
            self.thread.daemon = True
        else:
            self.thread = None

        ## the client will specify a name, but the server will expect a name at login
        if self.name is not None:
            self.setName(name)

        self.inboundThread.start()
        self.outboundThread.start()
        if thread: self.thread.start()

        ## now identify ourselves if we are the client
        if self.clientMode:
            self.outboundQueue.put(LoginMessage(self.name))

    def setName(self, name):
        self.name = name
        ## these thread names are used in the logging class
        self. inboundThread.name = "%-5s:%s" % ("GWIn" , self.name)
        self.outboundThread.name = "%-5s:%s" % ("GWOut", self.name)
        if self.thread is not None:
            self.thread.name = "%-5s:%s" % ("GWCli", self.name)

    ## client side
    def addOrder(self, gameId, qty, side, price):
        """Add a new order to the book for the given gameId. Note that this order can be passive or aggressive."""
        self.goid += 1
        m = GatewaySubmitOrderMessage(gameId, self.goid, qty, side, price)
        with self.pendingLock:
            self.pendingOrders[self.goid] = m
        self.outboundQueue.put(m)

    def cancelOrder(self, gameId, oid):
        """Request a cancel for the indicated order id."""
        assert gameId is not None
        with self.pendingLock:
            self.pendingCancels.add(oid)
        self.outboundQueue.put(GatewayCancelOrderMessage(gameId, oid))

    def orders(self):
        """
        Return three lists of orders: those that are pending but not yet live at the exchange, those that have been
        accepted and are now alive, and those that are now alive, but have had cancels requested.
        """
        ordersPending   = [Order(0, m.qty, m.side, m.price, goid=m.goid) for m in self.pendingOrders.values()]
        ordersLive      = [o for L in self.liveOrders.bids + self.liveOrders.asks for o in L.orders]
        ordersCanceling = [o for L in self.liveOrders.bids + self.liveOrders.asks for o in L.orders if o.goid in self.pendingCancels]
        return ordersPending, ordersLive, ordersCanceling

    ## server side (used by matching engine)
    def send(self, m):
        self.outboundQueue.put(str(m))

    ## internals
    def handleInboundMessages(self):
        """Handle all inbound messages in a loop. Called only by the inbound thread in Gateway.__init__."""
        if self.name is None: ## TODO: make more robust
            m = self.messenger.recvMessage() ## wait for login message
            self.setName(LoginMessage.fromstr(m).name)
        while True:
            m = self.messenger.recvMessage()
            log.info("%s.handleInboundMessages() got message '%s'" % (self.name, m))
            if m is None:
                self.close()
                break
            else:
                try:
                    m = GatewayMessage.fromstr(m)
                except ValueError as e:
                    log.warning("conversion problem parsing message '%s'" % m)
                else:
                    self.inboundQueue.put(m)

    def handleOutboundMessages(self):
        """Handle all outbound messages in a loop. Called only by the outbound thread in Gateway.__init__."""
        while True:
            m = self.outboundQueue.get()
            log.info("%s.handleOutboundMessages() sending message '%s'" % (self.name, m))
            if self.messenger is None: break
            success = self.messenger.sendMessage(str(m))
            if not success:
                self.close()
                break

    def close(self):
        """Close connections in the event of a gateway error."""
        log.info("closing gateway %s" % self.name)
        self.messenger.close()
        del self.messenger
        self.messenger = None
        ## shut down receiver
        ## send all pending notifications
        ## shut down remaining sockets
        pass

    def runClient(self):
        """Handle delivery of callbacks to any listeners. Only called by the client therad in Gateway.__init__."""
        while True:
            m = self.inboundQueue.get()

            ## keep track of position
            if isinstance(m, GatewayTradeMessage):
                self.pos += m.qty * int(m.side)
            elif isinstance(m, GatewaySettleMessage):
                self.pos = 0

            ## keep track of pending, live, and pending cancel
            with self.pendingLock:
                if isinstance(m, GatewayAddOrderMessage) or isinstance(m, GatewayRejectMessage) or isinstance(m, GatewayTradeMessage):
                    if m.goid in self.pendingOrders:
                        del self.pendingOrders[m.goid]
                elif isinstance(m, GatewayDeleteOrderMessage):
                    self.pendingCancels.discard(m.goid)
                elif isinstance(m, GatewaySettleMessage):
                    self.pendingOrders.clear()
                    self.pendingCancels.clear()

                ## keep track of live orders
                self.liveOrders.processMessage(m)

                ## trade can also remove pending cancels
                if isinstance(m, GatewayTradeMessage):
                    if m.oid in self.liveOrders.oidToPriceLevel:
                        L = self.liveOrders.oidToPriceLevel[m.oid]
                        if all(o.oid != m.oid for o in L.orders):
                            self.pendingCancels.discard(m.goid)

            ## now that internal state is correct, notify listeners
            for L in self.listeners:
                L.onGatewayMessage(self, m)

