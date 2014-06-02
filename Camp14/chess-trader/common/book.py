import time
import sys
from order import Order
from messages import *
from log import log

class PriceLevel:
    """Collection of Order objects at a given price level on a given side of a book."""
    def __init__(self, side, price):
        assert side in (Order.BUY, Order.SELL)
        self.side   = side
        self.price  = price
        self.orders = []

    def __str__(self):
        if self.side == Order.BUY:
            return " ".join(str(o) for o in reversed(self.orders))
        else:
            return " ".join(str(o) for o in          self.orders )

class Book:
    """
    Collection of all Orders at various PriceLevels. Includes logic to process Feed messages
    and update the book accordingly, adding new orders, filling resting orders, and canceling
    old orders. Also handles recovery messages from the Feed on startup or dropped packets.
    Contains accessors for getting the bid and ask prices at various levels relative to the
    inside price, as well as a pretty-printing method to display a price ladder.

    Note that this book is not used to do the actual matching of orders. See MatchingBook.
    """
    def __init__(self):
        self.prices = range(0,101)
        self.N      = len(self.prices)
        self.needRecovery = True
        self.inRecovery   = False

        ## bids and asks, ordered lowest to highest price
        self.bids = [PriceLevel(Order.BUY,  p) for p in self.prices]
        self.asks = [PriceLevel(Order.SELL, p) for p in self.prices]

        ## to speed up cancels
        self.oidToPriceLevel = dict()

    def bidLevel(self, level=0):
        """Return the level-th best (highest) bid price from the inside. The default level=0 gives the inside bid."""
        n = -1
        for i in reversed(xrange(self.N)):
            if len(self.bids[i].orders): n += 1
            if n == level:
                return self.bids[i]
        return None

    def askLevel(self, level=0):
        """Return the level-th best (lowest) ask price from the inside. The default level=0 gives the inside ask."""
        n = -1
        for i in xrange(self.N):
            if len(self.asks[i].orders): n += 1
            if n == level:
                return self.asks[i]
        return None

    def bid(self, level=0):
        """Return the inside (highest) bid price, or None if there are no bids."""
        b = self.bidLevel(level)
        if b is None: return None
        return b.price

    def ask(self, level=0):
        """Return the inside (lowest) ask price, or None if there are no asks."""
        a = self.askLevel(level)
        if a is None: return None
        return a.price


    def processMessage(self, m):
        """Apply a message to the book, returning True if this message affected the book (including completing a recovery or clearing the book)."""

        ## allow str or message for now by normalizing to string
        m = str(m)
        log.info(m)

        ## when a game starts, we don't need recovery, but we have to clear old orders
        if m.startswith("CR") or m.startswith("CN"):
            self.clear()

        ## only handle recovery messages if we need them
        if self.needRecovery:
            if m == "BS":
                ## start recovery
                self.inRecovery = True
                self.clear()
            elif m.startswith("BR") and self.inRecovery:
                ## add all messages from recovery
                header, recoveryMessages = m.split(",",1)
                for msg in recoveryMessages.split(";"):
                    xm = ExchangeAddOrderMessage.fromstr(msg)
                    o = Order(xm.oid, xm.qty, xm.side, xm.price)
                    self.addOrder(o)
            elif m == "BE" and self.inRecovery:
                ## end recovery
                self.needRecovery = False
                self.inRecovery   = False
                return True
        elif m.startswith("X"):
            ## exchange messages, which can be compound ;-separated messages
            for subm in m.split(";"):
                code, rest = subm.split(",", 1)
                if code == ExchangeAddOrderMessage.code:
                    xm = ExchangeAddOrderMessage.fromstr(subm)
                    o = Order(xm.oid, xm.qty, xm.side, xm.price)
                    self.addOrder(o)
                elif code == ExchangeCancelOrderMessage.code:
                    xm = ExchangeCancelOrderMessage.fromstr(subm)
                    self.removeOrder(xm.oid)
                elif code == ExchangeTradeMessage.code:
                    xm = ExchangeTradeMessage.fromstr(subm)
                    self.applyTrade(xm.oid, xm.qty)
                elif code == ExchangeNewGameMessage.code:
                    xm = ExchangeNewGameMessage.fromstr(subm)
                    self.clear()
            return True
        elif m.startswith("G"):
            ## gateway messages, which are never compound
            code, rest = m.split(",", 1)
            log.info("  code = " + code)
            if code == GatewayAddOrderMessage.code:
                gm = GatewayAddOrderMessage.fromstr(m)
                o = Order(gm.oid, gm.qty, gm.side, gm.price)
                self.addOrder(o)
            elif code == GatewayDeleteOrderMessage.code:
                gm = GatewayDeleteOrderMessage.fromstr(m)
                self.removeOrder(gm.oid)
            elif code == GatewayTradeMessage.code:
                gm = GatewayTradeMessage.fromstr(m)
                self.applyTrade(gm.oid, gm.qty)
            elif code == GatewaySettleMessage.code:
                self.clear()
            else:
                return False
            return True
        return False

    def addOrder(self, o):
        """Add the supplied Order to the book. Does not do matching, so throws exception if book crosses."""
        L = (self.bids if o.side == Order.BUY else self.asks)[o.price]
        bid = self.bid()
        ask = self.ask()
        if bid is not None and ask is not None and bid >= ask:
            s = "book just became crossed because of addOrder with oid %d:\n" % o.oid
            s += str(self)
            raise RuntimeError(s)
        L.orders.append(o)

        ## track for easy cancels later
        self.oidToPriceLevel[o.oid] = L

    def removeOrder(self, oid):
        """Remove the Order having the indicated order id from the book, if present."""
        if oid in self.oidToPriceLevel:
            restingOrders = self.oidToPriceLevel[oid].orders
            for ro in restingOrders:
                if ro.oid == oid:
                    restingOrders.remove(ro)
                    del self.oidToPriceLevel[oid]
                    break

    def applyTrade(self, oid, qty):
        """
        Apply a trade of the specified quantity to the resting Order with the indicated order id.
        May simply reduce the quantity of said order, or remove it entirely.
        """
        ## this should only happen for gateway trades, since the passive
        ## and the aggressive side both get a report, and the aggressor
        ## will have no order to remove
        if oid not in self.oidToPriceLevel:
            return

        restingOrders = self.oidToPriceLevel[oid].orders
        for ro in restingOrders:
            if ro.oid == oid:
                assert qty <= ro.qty
                if qty == ro.qty:
                    self.removeOrder(oid)
                else:
                    ro.qty -= qty
                break

    def clear(self):
        """Clear all orders from the book, and indicate that we no longer need recovery."""
        self.needRecovery = False
        self.inRecovery   = False
        self.oidToPriceLevel = dict()
        for L in self.bids + self.asks:
            L.orders = []

    def __str__(self):
        """Return pretty ladder representation."""
        bs = [str(l) for l in self.bids]
        ss = [str(l) for l in self.asks]
        W = 30
        fmt = "%%%ds %%03d %%-%ds" % (W, W)
        s = ""
        for i in reversed(xrange(self.N)):
            s += fmt % (bs[i][:W], self.prices[i], ss[i][:W]) + "\n"
        return s

