import sys
import getopt

import model
import strat
import stockfish
import time
import math

from order import Order
from log import log
from ChessBoard import ChessBoard

from messages import *

from cstrat import *

class CStrategyWrapper(strat.Strategy):
  def __init__(self, name, cname):
    super(CStrategyWrapper, self).__init__(name)
    self.strategy = CFactory.makeStrategy(cname)
    self.stockfish = stockfish.Stockfish()

  def onChessMessage(self,m):
    self.syncGateway()
    self.syncBoard(m)
    self.syncStockfish(m)
    cm = self.makeChessMessage(m)
    self.strategy.onChessMessage(cm)
    self.commitOrders()

  def onExchangeMessage(self,m):
    self.syncGateway()
    self.syncBook(m)
    if not isinstance(m, ExchangeMessage):
      return
    em = self.makeExchangeMessage(m)
    self.strategy.onExchangeMessage(em)
    self.commitOrders()

  def makeOrderVector(self, orders):
    ovec = vector_o()
    for o in orders:
      gameid = o.gameId if o.gameId else ""
      corder = COrder(gameid, int(o.oid), int(o.price), int(o.qty), int(o.side))
      ovec.push_back(corder)
    return ovec

  def syncGateway(self):
    gw = self.strategy.gateway()
    gw.reset()

    gw.setPosition(self.gateway.pos)

    ordersPending, ordersLive, ordersCanceling = self.gateway.orders()
    gw.setOrdersPending(self.makeOrderVector(ordersPending))
    gw.setOrdersLive(self.makeOrderVector(ordersLive))
    gw.setOrdersCanceling(self.makeOrderVector(ordersCanceling))

  def syncBook(self, m):
    self.book.processMessage(m)
    cbook = self.strategy.book()
    cbook.reset()
    for i in xrange(0,CBook.MAX_LEVELS):
      bidLevel = self.book.bidLevel(i)
      askLevel = self.book.askLevel(i)
      if bidLevel:
        qty = 0
        for o in bidLevel.orders: qty += o.qty
        numo = len(bidLevel.orders)
        cbook.setBid(i, bidLevel.price, qty, numo)
      if askLevel:
        qty = 0
        for o in askLevel.orders: qty += o.qty
        numo = len(askLevel.orders)
        cbook.setAsk(i, askLevel.price, qty, numo)

  def syncBoard(self, m):
    if not isinstance(m, ChessMoveMessage):
      return

    chess = ChessBoard()
    if isinstance(m, ChessMoveMessage):
      for move in m.history:
        chess.addTextMove(move)

    board = chess.getBoard()
    cboard = self.strategy.board()

    for row,rank in enumerate(board):
      for col,square in enumerate(rank):
        cboard.setPiece(row, col, square)

  def syncStockfish(self, m):
    if not isinstance(m, ChessMoveMessage) or not self.stockfish:
      return

    chess = ChessBoard()
    algebraicNotationMoves = []
    for move in m.history:
      chess.addTextMove(move)
      algebraicNotationMoves.append(chess.getLastTextMove(ChessBoard.AN))

    fen, legalMoves, scores, pctM, pctE1, pctE2, total = self.stockfish.eval(algebraicNotationMoves)

    sf = self.strategy.stockfish()
    sf.reset()
    sf.setFEN(fen)
    sf.setLegalMoves(legalMoves)
    sf.setTotal(pctM, pctE1, pctE2, total)

    for scoreType, scoreList in scores.iteritems():
      for scoreSubtype, score in scoreList.iteritems():
        if not math.isnan(score):
          sf.setScore(scoreType, scoreSubtype, score)

  def makeChessMessage(self, m):
    if isinstance(m, ChessNewGameMessage):
      cm = CChessMessage(m.code, m.gameId, "", vector_s(), "")
    elif isinstance(m, ChessMoveMessage):
      history = vector_s()
      for h in m.history:
        history.push_back(h)
      cm = CChessMessage(m.code, m.gameId, m.move, history, "")
    elif isinstance(m, ChessResultMessage):
      cm = CChessMessage(m.code, m.gameId, "", vector_s(), m.result)
    return cm

  def makeExchangeMessage(self, m):
    if isinstance(m, ExchangeBookMessage):
      order = COrder(m.gameId, int(m.oid), int(m.price), int(m.qty), int(m.side))
    else:
      order = COrder(m.gameId, 0, 0, 0, COrder.BUY);
    em = CExchangeMessage(m.code, order)
    return em

  def commitOrders(self):
    gw = self.strategy.gateway()
    addOrderVec = gw.outboundAdds()
    cancelOrderVec = gw.outboundCancels()
    for o in addOrderVec:
      self.gateway.addOrder(o.gameid(), o.quantity(), o.side(), o.price())
    for o in cancelOrderVec:
      self.gateway.cancelOrder(o.gameid(), o.orderid())

def exitWithUsage():
  print >>sys.stderr
  print >>sys.stderr, '  usage:'
  print >>sys.stderr, '    %s --strategy <strategy_name> --id <strategy_id>' % sys.argv[0]
  print >>sys.stderr
  print >>sys.stderr, '      -s/--strategy <strategy_name>    name of C++ strategy class'
  print >>sys.stderr, '      -i/--id <strategy_id>            short string id for strategy'
  print >>sys.stderr, '      -h/--help                        print this useful message'
  print >>sys.stderr
  sys.exit(0)

if __name__ == "__main__":
  try:
    opts, args = getopt.getopt(sys.argv[1:], 's:i:h', ['strategy=', 'id=', 'help'])
  except getopt.GetoptError, err:
    print >>sys.stderr, err
    exitWithUsage()

  strategyName = None
  strategyId = None

  for o,a in opts:
    if o == '-s' or o == '--strategy':
      strategyName = a
    elif o == '-i' or o == '--id':
      strategyId = a
    elif o == '-h' or o == '--help':
      exitWithUsage()

  if not strategyName or not strategyId:
    print >>sys.stderr, "Must specify both strategy and id"
    exitWithUsage()

  x = CStrategyWrapper(strategyId, strategyName)

  while True:
    time.sleep(1)
    pass

