import re
from order import Order

class ExchangeMessage:
    """
    Message from the exchange to convey public data about activity in the order book.
    Specific types of exchange messages are subclasses below. The NewGame message is
    important to the book because we need to clear any existing orders.
    """
    def __init__(self, gameId, oid, qty, side, price):
        raise NotImplementedError("cannot instantiate ExchangeMessage base class")

    @classmethod
    def fromstr(cls, s):
        """Convert from a string to the appropriate subclass of ExchangeMessage."""
        code, rest = s.split(",", 1)
        if   code ==     ExchangeNewGameMessage.code: return     ExchangeNewGameMessage.fromstr(s)
        elif code ==    ExchangeAddOrderMessage.code: return    ExchangeAddOrderMessage.fromstr(s)
        elif code == ExchangeCancelOrderMessage.code: return ExchangeCancelOrderMessage.fromstr(s)
        elif code ==       ExchangeTradeMessage.code: return       ExchangeTradeMessage.fromstr(s)
        else:
            raise ValueError("no ExchangeMessage type has code '%s'" % s)

class ExchangeNewGameMessage(ExchangeMessage):
    code = "XN"
    def __init__(self, gameId):
        self.gameId  = gameId

    @classmethod
    def fromstr(cls, s):
        msgType, gameId = s.split(",")
        assert msgType == cls.code
        return cls(gameId)

    def __str__(self):
        return "%s,%s" % (self.code, self.gameId)

class ExchangeBookMessage(ExchangeMessage):
    """Handle the (identical) work for Add, Cancel, and Trade messages. Subclasses just have own codes."""
    def __init__(self, gameId, oid, qty, side, price):
        assert hasattr(self,'code'), "you cannot instantiate ExchangeBookMessage directly"
        self.gameId = gameId
        self.oid    = oid
        self.qty    = qty
        self.side   = side
        self.price  = price

    @classmethod
    def fromstr(cls, s):
        code, gameId, oid, qty, side, price = s.split(",")
        assert code == cls.code
        oid    = int(oid)
        qty    = int(qty)
        side   = {"B":Order.BUY,"S":Order.SELL}[side]
        price  = int(price)
        return cls(gameId, oid, qty, side, price)

    def __str__(self):
        return "%s,%s,%d,%d,%s,%d" % (self.code, self.gameId, self.oid, self.qty, {Order.BUY:"B",Order.SELL:"S"}[self.side], self.price)

class ExchangeAddOrderMessage(ExchangeBookMessage):
    code = "XA"

class ExchangeCancelOrderMessage(ExchangeBookMessage):
    code = "XC"

class ExchangeTradeMessage(ExchangeBookMessage):
    code = "XT"



class ChessMessage:
    """
    Message from the exchange that pertains to the state of the chess game, including
    when a new game starts, a move is made, or the result is announced.
    """
    def __init__(self):
        raise NotImplementedError("cannot instantiate ChessMessage base class")

    @classmethod
    def fromstr(cls, s):
        code, rest = s.split(",", 1)
        if   code == ChessNewGameMessage.code: return ChessNewGameMessage.fromstr(s)
        elif code ==    ChessMoveMessage.code: return    ChessMoveMessage.fromstr(s)
        elif code ==  ChessResultMessage.code: return  ChessResultMessage.fromstr(s)
        else:
            raise ValueError("no ChessMessage type has code '%s'" % s)

class ChessNewGameMessage(ChessMessage):
    code = "CN"
    def __init__(self, gameId):
        self.gameId  = gameId

    @classmethod
    def fromstr(cls, s):
        msgType, gameId = s.split(",")
        assert msgType == cls.code
        return cls(gameId)

    def __str__(self):
        return "%s,%s" % (self.code, self.gameId)

class ChessMoveMessage(ChessMessage):
    code = "CM"
    def __init__(self, gameId, move, history):
        self.gameId  = gameId
        self.move    = move
        self.history = history

    @classmethod
    def fromstr(cls, s):
        msgType, gameId, move, history = s.split(",")
        assert msgType == cls.code
        history = history.split(" ")
        return cls(gameId, move, history)

    def __str__(self):
        return "%s,%s,%s,%s" % (self.code, self.gameId, self.move, " ".join(self.history))


class ChessResultMessage(ChessMessage):
    code = "CR"
    def __init__(self, gameId, result):
        self.gameId  = gameId
        self.result  = result

    def whiteWins(self):
        return self.result == "1-0"

    @classmethod
    def fromstr(cls, s):
        msgType, gameId, result = s.split(",")
        assert msgType == cls.code
        return cls(gameId, result)

    def __str__(self):
        return "%s,%s,%s" % (self.code, self.gameId, self.result)





class GatewayMessage:
    """
    Private traffic communnicated between a strategy and the exchange, including requests for
    new orders (or cancels of old orders), as well as the private exchange acknowledgement of
    an order, and the private fill information (non anonymized as in the public feed).
    """
    def __init__(self):
        raise NotImplementedError("cannot instantiate GatewayMessage base class")

    @classmethod
    def fromstr(cls, s):
        code, rest = s.split(",", 1)
        if   code ==              LoginMessage.code: return              LoginMessage.fromstr(s)
        elif code == GatewaySubmitOrderMessage.code: return GatewaySubmitOrderMessage.fromstr(s)
        elif code == GatewayCancelOrderMessage.code: return GatewayCancelOrderMessage.fromstr(s)
        elif code ==    GatewayAddOrderMessage.code: return    GatewayAddOrderMessage.fromstr(s)
        elif code == GatewayDeleteOrderMessage.code: return GatewayDeleteOrderMessage.fromstr(s)
        elif code ==       GatewayTradeMessage.code: return       GatewayTradeMessage.fromstr(s)
        elif code ==      GatewaySettleMessage.code: return      GatewaySettleMessage.fromstr(s)
        elif code ==      GatewayRejectMessage.code: return      GatewayRejectMessage.fromstr(s)
        else:
            raise ValueError("no message type has code '%s'" % s)

class GatewaySubmitOrderMessage(GatewayMessage):
    code = "GS"
    def __init__(self, gameId, goid, qty, side, price):
        self.gameId = gameId
        self.goid   = goid
        self.qty    = qty
        self.side   = side
        self.price  = price

    @classmethod
    def fromstr(cls, s):
        add, gameId, goid, qty, side, price = s.split(",")
        assert add == cls.code
        goid   = int(goid)
        qty    = int(qty)
        side   = {"B":Order.BUY,"S":Order.SELL}[side]
        price  = int(price)
        return cls(gameId, goid, qty, side, price)

    def __str__(self):
        return "%s,%s,%d,%d,%s,%d" % (GatewaySubmitOrderMessage.code, self.gameId, self.goid, self.qty, {Order.BUY:"B",Order.SELL:"S"}[self.side], self.price)

class GatewayCancelOrderMessage(GatewayMessage):
    code = "GC"
    def __init__(self, gameId, oid):
        self.gameId = gameId
        self.oid    = oid

    @classmethod
    def fromstr(cls, s):
        cancel, gameId, oid = s.split(",")
        assert cancel == cls.code
        oid = int(oid)
        return cls(gameId, oid)

    def __str__(self):
        return "%s,%s,%d" % (GatewayCancelOrderMessage.code, self.gameId, self.oid)

class LoginMessage(GatewayMessage):
    code = "GN"
    def __init__(self, name):
        assert re.match("^[0-9A-Za-z]{3,8}$", name), "names must consist of between 3 and 8 characters from [0-9A-Za-z], not '%s'" % name
        self.name = name

    @classmethod
    def fromstr(cls, s):
        login, name = s.split(",")
        assert login == cls.code
        return cls(name)

    def __str__(self):
        return "%s,%s" % (LoginMessage.code, self.name)

class GatewayResponseMessage(GatewayMessage):
    """Internal class used to save on the identical work needed for Add, Delete, and Trade messages. Use subclasses, not this class."""
    def __init__(self, owner, gameId, goid, oid, qty, side, price):
        assert hasattr(self,'code'), "you cannot instantiate GatewayResponseMessage directly"
        self.owner  = owner
        self.gameId = gameId
        self.goid   = goid
        self.oid    = oid
        self.qty    = qty
        self.side   = side
        self.price  = price

    @classmethod
    def fromstr(cls, s):
        code, owner, gameId, goid, oid, qty, side, price = s.split(",")
        assert code == cls.code
        goid   = int(goid)
        oid    = int(oid)
        qty    = int(qty)
        side   = {"B":Order.BUY,"S":Order.SELL}[side]
        price  = int(price)
        return cls(owner, gameId, goid, oid, qty, side, price)

    def __str__(self):
        return "%s,%s,%s,%d,%d,%d,%s,%d" % (self.code, self.owner, self.gameId, self.goid, self.oid, self.qty, {Order.BUY:"B",Order.SELL:"S"}[self.side], self.price)

class GatewayAddOrderMessage(GatewayResponseMessage):
    code = "GA"

class GatewayDeleteOrderMessage(GatewayResponseMessage):
    code = "GD"

class GatewayTradeMessage(GatewayResponseMessage):
    code = "GT"

class GatewaySettleMessage(GatewayResponseMessage):
    """Message indicating that a game has completed, and giving the price at which the contract settled."""
    code = "GX"
    def __init__(self, gameId, price):
        self.gameId = gameId
        self.price  = price

    @classmethod
    def fromstr(cls, s):
        code, gameId, price = s.split(",")
        assert code == cls.code
        price  = int(price)
        return cls(gameId, price)

    def __str__(self):
        return "%s,%s,%d" % (self.code, self.gameId, self.price)

class GatewayRejectMessage(GatewayResponseMessage):
    code = "GR"
    def __init__(self, owner, gameId, goid, reason=""):
        assert "," not in reason
        self.owner  = owner
        self.gameId = gameId
        self.goid   = goid
        self.reason = reason

    @classmethod
    def fromstr(cls, s):
        code, owner, gameId, goid, reason = s.split(",")
        assert code == cls.code
        goid = int(goid)
        return cls(owner, gameId, goid, reason)

    def __str__(self):
        return "%s,%s,%s,%d,%s" % (self.code, self.owner, self.gameId, self.goid, self.reason)
