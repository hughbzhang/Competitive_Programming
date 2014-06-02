import socket
import struct
import threading
from messages import *
from log import log

class Listener:
    """
    Anyone wishing to listen to a Feed should implement this interface by inheriting from it.
    If Feed is constructed with listeners, it checks that they all inherit from this class.
    """
    def onFeedMessage(rawMessage, seq, drop, message):
        """
        Called by the Feed's client thread for each message (or once per submessage of a
        compound message). The raw message will contain the exact message received, including
        sequence number, and all elements of a compound message, still as a string. The seq
        value is the sequence number, parsed out as an int. If the sequence number indicates
        a gap, the drop flag will be set to True. Finally, the message parameter will be the
        parsed content of the received (sub)message.
        """
        pass

class Feed:
    """
    Manage the receiving or (for the matching engine only) sending of the UDP multicast messages
    that convey all information from the market, including chess moves and order book activity.
    Note that this does not include private Gateway traffic between a strategy and the exchange,
    which is handled in the TCP-based Gateway class.
    """
    MCAST_GRP = '224.1.1.1'
    MCAST_PORT = 5007
    MAX_SIZE = 2048

    def __init__(self, listeners=None, send=False):
        self.sendSocket    = None
        self.receiveSocket = None
        self.sendSeq = 0
        self.receiveSeq = None
        self.listeners = listeners if listeners is not None else []
        for L in self.listeners:
            assert isinstance(L, Listener)

        if send:
            self.sendSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
            self.sendSocket.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_TTL, 2)
        else:
            ## similar to sending, but need to do the group membership setup
            self.receiveSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
            self.receiveSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            self.receiveSocket.bind(('', Feed.MCAST_PORT))
            mreq = struct.pack("4sl", socket.inet_aton(Feed.MCAST_GRP), socket.INADDR_ANY)
            self.receiveSocket.setsockopt(socket.IPPROTO_IP, socket.IP_ADD_MEMBERSHIP, mreq)
            self.receiveSocket.setsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF, 256*1024) ## see /proc/sys/net/core/rmem_*
            ##print "receiveBuf = ", self.receiveSocket.getsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF)

            ## start the thread to handle any listeners through the callback mechanism
            if len(self.listeners):
                self.thread = threading.Thread(target=self.run, name="Feed")
                self.thread.daemon = True
                self.thread.start()

    def send(self, msg):
        """Send the indicated message over the UDP socket. Not receiver paced like TCP, so no need for thread."""
        msg = "%08d %s" % (self.sendSeq, msg)
        assert len(msg) < Feed.MAX_SIZE
        log.info(msg)
        self.sendSeq += 1
        self.sendSocket.sendto(msg, (Feed.MCAST_GRP, Feed.MCAST_PORT))

    def recv(self):
        """Block until a message is received. Useful for things like the GUI that are driven by feed messages."""
        msg = self.receiveSocket.recv(Feed.MAX_SIZE)

        ## check for drops
        seq, m = msg.split(" ", 1)
        seq = int(seq)
        drop = self.receiveSeq is not None and (seq > self.receiveSeq+1)
        self.receiveSeq = seq

        return msg, seq, drop, m

    def run(self):
        """Receive in a loop and deliver callbacks to all listeners. Should only be called by Feed.__init__."""
        while True:
            msg, seq, drop, m = self.recv()

            if   m.startswith("C"): msgs = [   ChessMessage.fromstr(m)                      ]
            elif m.startswith("X"): msgs = [ExchangeMessage.fromstr(m) for m in m.split(";")]
            else:                   msgs = [m]

            for m in msgs:
                for L in self.listeners:
                    L.onFeedMessage(msg, seq, drop, m)
