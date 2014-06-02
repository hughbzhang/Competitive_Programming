#include "StockfishStrategy.h"

StockfishStrategy::StockfishStrategy()
  : maxPosition_(100)
  , maxOrderQuantity_(10)
{
  // nothing
}

StockfishStrategy::~StockfishStrategy()
{
  // nothing
}

void StockfishStrategy::onExchangeMessage(const CExchangeMessage& em)
{
  // This strategy does nothing with exchange messages.
}

void StockfishStrategy::onChessMessage(const CChessMessage& cm)
{
  // If unknown message type, do nothing.
  if (cm.type() == CChessMessage::CHESS_UNKNOWN)
    return;

  // If not move (is new game or result) cancel all outstanding orders.
  if (cm.type() != CChessMessage::CHESS_MOVE) {
    cancelAllOrders();
    return;
  }

  // Otherwise we have a chess move.

  // If pending orders, do nothing.
  CGateway& gw = this->gateway();
  if (gw.ordersPending().size() > 0)
    return;

  // No pending orders. Let's compute a fair price.
  unsigned fairPrice = computeFairPrice();

  // We want to market make 2 ticks around fair price.
  unsigned buyPrice = std::max(fairPrice - 2, (unsigned)1);
  unsigned sellPrice = std::min(fairPrice + 2, (unsigned)99);

  const std::vector<COrder> ordersLive = gw.ordersLive();
  unsigned position = gw.position();

  unsigned activeBuyQuantity = 0;
  unsigned activeSellQuantity = 0;

  // Cancel live orders at wrong prices.
  // Record active quanity at desired prices.
  for (size_t i=0; i < ordersLive.size(); ++i) {
    const COrder& o = ordersLive[i];
    if (o.side() == COrder::BUY && o.price() == buyPrice)
      activeBuyQuantity += o.quantity();
    else if (o.side() == COrder::SELL && o.price() == sellPrice)
      activeSellQuantity += o.quantity();
    else
      gw.cancelOrder(cm.gameid(), o.orderid());
  }

  // Buy and sell subject to maxOrderQuantity_ and maxPosition_ constraints.
  int buyQuantity = maxOrderQuantity_ - activeBuyQuantity;
  int sellQuantity = maxOrderQuantity_ - activeSellQuantity;
  if (buyQuantity > 0 && position + buyQuantity <= maxPosition_)
    gw.addOrder(cm.gameid(), buyPrice, buyQuantity, COrder::BUY);
  if (sellQuantity > 0 && position - sellQuantity >= -maxPosition_)
    gw.addOrder(cm.gameid(), sellPrice, sellQuantity, COrder::SELL);
}

void StockfishStrategy::cancelAllOrders()
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

unsigned StockfishStrategy::computeFairPrice() const
{
  const CStockfish& sf = stockfish();

  float score = sf.totalScore();
  score = std::min(score, (float)2.5);
  score = std::max(score, (float)-2.5);

  // These coefficients are the result of a linear regression.
  unsigned fairPrice = (0.4337105 + 0.1247885 * score) * 100;

  fairPrice = std::min(fairPrice, (unsigned)100);
  fairPrice = std::max(fairPrice, (unsigned)0);
  return fairPrice;
}


