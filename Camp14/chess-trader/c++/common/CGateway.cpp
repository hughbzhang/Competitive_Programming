#include <CGateway.h>

int CGateway::position() const
{
  return position_;
}

const std::vector<COrder>& CGateway::ordersPending() const
{
  return ordersPending_;
}

const std::vector<COrder>& CGateway::ordersLive() const
{
  return ordersLive_;
}

const std::vector<COrder>& CGateway::ordersCanceling() const
{
  return ordersCanceling_;
}

void CGateway::addOrder(const std::string& gameid, unsigned price, unsigned quantity, int side)
{
  outboundAdds_.push_back(COrder(gameid, 0, price, quantity, side));
}

void CGateway::cancelOrder(const std::string& gameid, unsigned orderid)
{
  outboundCancels_.push_back(COrder(gameid, orderid, 0, 0, 0));
}

CGateway::CGateway()
{
  reset();
}

void CGateway::reset()
{
  position_ = 0;
  ordersPending_.clear();
  ordersLive_.clear();
  ordersCanceling_.clear();
  outboundAdds_.clear();
  outboundCancels_.clear();
}

void CGateway::setPosition(int pos)
{
  position_ = pos;
}

void CGateway::setOrdersPending(const std::vector<COrder>& orders)
{
  ordersPending_ = orders;
}

void CGateway::setOrdersLive(const std::vector<COrder>& orders)
{
  ordersLive_ = orders;
}

void CGateway::setOrdersCanceling(const std::vector<COrder>& orders)
{
  ordersCanceling_ = orders;
}

const std::vector<COrder>& CGateway::outboundAdds() const
{
  return outboundAdds_;
}

const std::vector<COrder>& CGateway::outboundCancels() const
{
  return outboundCancels_;
}

