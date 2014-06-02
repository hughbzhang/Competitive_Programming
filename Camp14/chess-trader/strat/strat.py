import gateway, feed, book
import ChessBoard
from messages import *
from log import log

class Strategy(object, gateway.Listener, feed.Listener):
    def __init__(self, name):
        self.gateway = gateway.Gateway(name=name, listeners=[self])
        self.feed    = feed.Feed(listeners=[self])
        self.book    = book.Book()
        self.board   = ChessBoard.ChessBoard()
        self.gameId  = None

    def onGatewayMessage(self, gateway, message):
        log.info("Strategy.onGatewayMessage('%s')" % message)
        pass

    def onFeedMessage(self, rawMessage, seq, drop, message):
        """
        Get feed message, decide whether it is a book update or a chess message,
        and pass to the appropriate callback.
        """

        log.info(rawMessage)
        if isinstance(message, ExchangeMessage) or (isinstance(message, str) and message.startswith("B")):
            log.info("  => ExchangeMessage: %s" % message)
            self.onExchangeMessage(message)
        elif isinstance(message, ChessMessage):
            log.info("  => ChessMessage: %s" % message)
            self.onChessMessage(message)

    def onChessMessage(self, chessMessage):
        log.info("Strategy.onChessMessage('%s')" % chessMessage)
        pass

    def onExchangeMessage(self, exchangeMessage):
        log.info("Strategy.onExchangeMessage('%s')" % exchangeMessage)
        pass
