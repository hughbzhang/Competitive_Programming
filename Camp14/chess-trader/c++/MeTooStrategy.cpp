#include "MeTooStrategy.h"
#include <iostream>

MeTooStrategy::MeTooStrategy()
  : maxPosition_(100)
  , maxOrderQuantity_(10)
{
  // nothing
}

MeTooStrategy::~MeTooStrategy()
{
  // nothing
}

void MeTooStrategy::onChessMessage(const CChessMessage& cm)
{
  // This strategy does nothing with chess messages.
}

void MeTooStrategy::onExchangeMessage(const CExchangeMessage& em)
{
  CGateway& gw = gateway();
  const CBook& b = book();

  // Don't do anything unless the book has other orders in it.
  if (b.bidLevels() == 0 || b.askLevels() == 0) {
    cancelAllOrders();
    return;
  }

  unsigned buyPrice = b.bidPrice(0);
  unsigned sellPrice = b.askPrice(0);

  // A long position is positive, short position is negative.
  // Figure out if we are long or short and make positive.
  unsigned qtyLong = std::max(gw.position(), 0);
  unsigned qtyShort = -std::min(gw.position(), 0);

  bool haveOrderAtBid = false;
  bool haveOrderAtAsk = false;

  // Cancel live orders at wrong prices.
  // Record whether we have active orders at desired prices.
  const std::vector<COrder> ordersLive = gw.ordersLive();
  for (size_t i=0; i < ordersLive.size(); ++i) {
    const COrder& o = ordersLive[i];
    if (o.side() == COrder::BUY && o.price() == buyPrice)
      haveOrderAtBid = true;
    else if (o.side() == COrder::SELL && o.price() == sellPrice)
      haveOrderAtAsk = true;
    else
      gw.cancelOrder(em.order().gameid(), o.orderid());
  }

  // Buy and sell subject to maxOrderQuantity_ and maxPosition_ constraints.
  if (!haveOrderAtBid && qtyLong + maxOrderQuantity_ <= maxPosition_)
    gw.addOrder(em.order().gameid(), buyPrice, maxOrderQuantity_, COrder::BUY);
  if (!haveOrderAtAsk && qtyShort + maxOrderQuantity_ <= maxPosition_)
    gw.addOrder(em.order().gameid(), sellPrice, maxOrderQuantity_, COrder::SELL);
}

void MeTooStrategy::cancelAllOrders()
{
  // Cancel all outstanding orders. First get the
  // list of live orders from the gateway, then
  // tell the gateway to cancel each of them.
  CGateway& gw = this->gateway();
  const std::vector<COrder> ordersLive = gw.ordersLive();
  for (size_t i=0; i < ordersLive.size(); ++i) {
    const COrder order = ordersLive[i];
    gw.cancelOrder(order.gameid(), order.orderid());
  }
}

