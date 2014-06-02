import model
import strat
import time
import math

from order import Order
from log import log

from messages import *

from example_models import *

class SimpleChessMoveExecutor(strat.Strategy):
    def __init__(self, name, model, addQty=10):
        super(SimpleChessMoveExecutor, self).__init__(name)
        self.model = model
        self.maxPos = 100
        self.addQty = addQty

    def onChessMessage(self,m):
        ## pass through to model
        self.model.onChessMessage(m)

        ## decide my bid price and ask price
        fairPrice = self.model.fairPrice()
        if fairPrice is None or math.isnan(fairPrice):
            ordersPending, ordersLive, ordersCanceling = self.gateway.orders()
            for o in ordersLive:
                self.gateway.cancelOrder(m.gameId, o.oid)
            return

        buyPrice  = int(round(fairPrice-2))
        sellPrice = int(round(fairPrice+2))
        log.info("fairPrice = %f buyPrice = %d sellPrice = %d" % (fairPrice, buyPrice, sellPrice))

        ## keep desired quantity showing at indicated price
        alreadyHaveBuy  = False
        alreadyHaveSell = False
        ordersPending, ordersLive, ordersCanceling = self.gateway.orders()
        if len(ordersPending):
            log.info("already have %d pending orders: %s" % (len(ordersPending), [(o.owner, o.oid) for o in ordersPending]))
            return

        for o in ordersLive:
            log.info("oid=%d qty=%d side=%d price=%d" % (o.oid, o.qty, o.side, o.price))
            if o.side == Order.BUY:
                if o.price == buyPrice:
                    alreadyHaveBuy = True
                elif True or o.price > buyPrice:
                    self.gateway.cancelOrder(m.gameId, o.oid)
            else:
                if o.price == sellPrice:
                    alreadyHaveSell = True
                elif True or o.price < sellPrice:
                    self.gateway.cancelOrder(m.gameId, o.oid)

        if not alreadyHaveBuy  and self.gateway.pos + self.addQty <  self.maxPos: self.gateway.addOrder(m.gameId, self.addQty, Order.BUY , buyPrice)
        if not alreadyHaveSell and self.gateway.pos - self.addQty > -self.maxPos: self.gateway.addOrder(m.gameId, self.addQty, Order.SELL, sellPrice)


class SimpleInventoryMarketMaker(strat.Strategy):
    def __init__(self, name):
        super(SimpleInventoryMarketMaker, self).__init__(name)

        self.maxPos = 30
        self.addQty = 5
        self.cooldown = 2

    def onExchangeMessage(self, exchangeMessage):
        log.info("onExchangeMessage('%s')" % exchangeMessage)
        ## apply to book (note you could check oid, see if it's yours, and not apply if you don't want to see own orders)
        self.book.processMessage(exchangeMessage)

        if hasattr(exchangeMessage, "gameId") and exchangeMessage.gameId is not None:
            self.gameId = exchangeMessage.gameId

        if self.book.needRecovery or self.gameId is None: return

        ## cooldown
        if not hasattr(self, "nextTime"): self.nextTime = time.time() + self.cooldown
        if time.time() > self.nextTime:
            self.nextTime = time.time() + self.cooldown
        else:
            return

        bid = self.book.bid()
        ask = self.book.ask()

        if bid is None and ask is not None and ask > 0:
            bid = ask-1
        elif ask is None and bid is not None and bid < 100:
            ask = bid+1
        elif bid is None and ask is None:
            return

        qtyLong  =     max(self.gateway.pos,0)
        qtyShort = abs(min(self.gateway.pos,0))

        ## move desired price away from inside price as inventory builds up
        bidPrice = bid - qtyLong
        askPrice = ask + qtyShort

        log.info("ask = %(ask)3d qtyShort = %(qtyShort)3d askPrice = %(askPrice)3d" % locals())
        log.info("bid = %(bid)3d qtyLong  = %(qtyLong)3d bidPrice = %(bidPrice)3d" % locals())

        ## check existing orders that haven't been canceled
        restingBuyQty, restingSellQty = 0,0
        levelsAlreadyPresent = set()
        ordersPending, ordersLive, ordersCanceling = self.gateway.orders()
        for o in ordersLive:
            levelsAlreadyPresent.add((o.side, o.price))

            ## orders that we think are too aggressive
            buyTooHigh = (o.side == Order.BUY  and o.price > bidPrice)
            sellTooLow = (o.side == Order.SELL and o.price < askPrice)

            ## clean up some orders that maybe aren't aggressive enough
            buyTooLow   = (o.side == Order.BUY  and o.price < bidPrice-10)
            sellTooHigh = (o.side == Order.SELL and o.price > askPrice+10)

            log.info("oid=%d qty=%d side=%d price=%d bad=%d%d%d%d" % (o.oid, o.qty, o.side, o.price, buyTooHigh, sellTooLow, buyTooLow, sellTooHigh))
            if buyTooHigh or sellTooLow or buyTooLow or sellTooHigh:
                self.gateway.cancelOrder(self.gameId, o.oid)
            else:
                ## for orders we want to leave, count up the total quantity
                if o.side == Order.BUY:
                    restingBuyQty  += o.qty
                else:
                    restingSellQty += o.qty

        ## also count pending orders
        for o in ordersPending:
            levelsAlreadyPresent.add((o.side, o.price))
            if o.side == Order.BUY:
                restingBuyQty  += o.qty
            else:
                restingSellQty += o.qty

        ## place new orders
        log.info("qtyLong + restingBuyQty + self.addQty = %d + %d + %d with self.maxPos = %d %s" % (qtyLong, restingBuyQty, self.addQty, self.maxPos, "NEW" if (Order.BUY, bidPrice) not in levelsAlreadyPresent else ""))
        if qtyLong + restingBuyQty + self.addQty <= self.maxPos and (Order.BUY, bidPrice) not in levelsAlreadyPresent:
            self.gateway.addOrder(self.gameId, self.addQty, Order.BUY, price=bidPrice)
        log.info("qtyShort + restingSellQty + self.addQty = %d + %d + %d with self.maxPos = %d %s" % (qtyShort, restingSellQty, self.addQty, self.maxPos, "NEW" if (Order.SELL, askPrice) not in levelsAlreadyPresent else ""))
        if qtyShort + restingSellQty + self.addQty <= self.maxPos and (Order.SELL, askPrice) not in levelsAlreadyPresent:
            self.gateway.addOrder(self.gameId, self.addQty, Order.SELL, price=askPrice)

class MeTooMarketMaker(strat.Strategy):
    def __init__(self, name):
        super(MeTooMarketMaker, self).__init__(name)

        self.maxPos = 20
        self.addQty = 5
        self.cooldown = 5

    def onExchangeMessage(self, exchangeMessage):
        log.info("onExchangeMessage('%s')" % exchangeMessage)
        ## apply to book
        self.book.processMessage(exchangeMessage)

        if hasattr(exchangeMessage, "gameId") and exchangeMessage.gameId is not None:
            self.gameId = exchangeMessage.gameId

        if self.book.needRecovery or self.gameId is None: return

        ## cooldown
        if not hasattr(self, "nextTime"): self.nextTime = time.time() + self.cooldown
        if time.time() > self.nextTime:
            self.nextTime = time.time() + self.cooldown
        else:
            return

        bid = self.book.bid()
        ask = self.book.ask()

        qtyLong  =     max(self.gateway.pos,0)
        qtyShort = abs(min(self.gateway.pos,0))

        log.info("ask = %(ask)4s qtyShort = %(qtyShort)3d" % locals())
        log.info("bid = %(bid)4s qtyLong  = %(qtyLong)3d"  % locals())

        ## check existing orders that haven't been canceled
        haveOrderAtBid, haveOrderAtAsk = False, False
        ordersPending, ordersLive, ordersCanceling = self.gateway.orders()
        for o in ordersLive:
            cancel = False
            if   bid is not None and o.side == "B" and o.price == bid: haveOrderAtBid = True
            elif ask is not None and o.side == "S" and o.price == ask: haveOrderAtAsk = True
            else:
                cancel = True
                self.gateway.cancelOrder(self.gameId, o.oid)

            log.info("oid=%d qty=%d side=%d price=%d cancel=%d" % (o.oid, o.qty, o.side, o.price, cancel))

        ## place new orders
        if qtyLong  + self.addQty <= self.maxPos and not haveOrderAtBid and bid is not None:
            self.gateway.addOrder(self.gameId, self.addQty, Order.BUY, price=bid)
        if qtyShort + self.addQty <= self.maxPos and not haveOrderAtAsk and ask is not None:
            self.gateway.addOrder(self.gameId, self.addQty, Order.SELL, price=ask)

class BrokenMarketMaker(strat.Strategy):
    def __init__(self, name):
        super(BrokenMarketMaker, self).__init__(name)

        self.maxPos = 10
        self.addQty = 1

    def onExchangeMessage(self, exchangeMessage):
        log.info("onExchangeMessage('%s')" % exchangeMessage)
        ## apply to book
        self.book.processMessage(exchangeMessage)

        if hasattr(exchangeMessage, "gameId") and exchangeMessage.gameId is not None:
            self.gameId = exchangeMessage.gameId

        if self.book.needRecovery or self.gameId is None: return

        bid = self.book.bid()
        ask = self.book.ask()

        ordersPending, ordersLive, ordersCanceling = self.gateway.orders()
        for o in ordersLive:
            self.gateway.cancelOrder(self.gameId, o.oid)

        for i in xrange(30):
            if bid is not None: self.gateway.addOrder(self.gameId, self.addQty, Order.BUY , price=bid)
            if ask is not None: self.gateway.addOrder(self.gameId, self.addQty, Order.SELL, price=ask)

if __name__ == "__main__":
    import sys
    if "SCO"  in sys.argv: SCO  = SimpleChessMoveExecutor("SCO", OpeningChessModel("OpeningChessModel"))
    if "SCM"  in sys.argv: SCM  = SimpleChessMoveExecutor("SCM", SimpleMaterialCountChessModel("SimpleMaterialCountChessModel"), addQty=7)
    if "SCS"  in sys.argv: SCS  = SimpleChessMoveExecutor("SCS", StockfishChessModel("StockfishChessModel"), addQty=8)
    if "SIMM" in sys.argv: SIMM = SimpleInventoryMarketMaker("SIMM")
    if "M2M"  in sys.argv: M2M  = MeTooMarketMaker("M2M")
    if "BMM"  in sys.argv: BMM  = BrokenMarketMaker("BMM")
    while True:
        time.sleep(1)
        pass
