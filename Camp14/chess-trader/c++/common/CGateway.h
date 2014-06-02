#ifndef __CGATEWAY_H__
#define __CGATEWAY_H__

#include <COrder.h>
#include <vector>

class CGateway
{
public:
  // Methods for C++ strategy classes.

  //////////////////////////////////////////////////////////
  // Accessors for position and orders.
  //////////////////////////////////////////////////////////

  // Our current open position, in terms of number of contracts/shares.
  int position() const;

  // A list of orders that we have sent to the gateway,
  // but have not yet been acknowledged.
  const std::vector<COrder>& ordersPending() const;

  // A list of live orders that are resting the book. These orders
  // are available for other people to trade against.
  const std::vector<COrder>& ordersLive() const;

  // A list of orders that we have requested to be canceled,
  // but have not yet been canceled.
  const std::vector<COrder>& ordersCanceling() const;

  //////////////////////////////////////////////////////////
  // Methods to add and cancel orders.
  //////////////////////////////////////////////////////////
  void addOrder(const std::string& gameid, unsigned price, unsigned quantity, int side);
  void cancelOrder(const std::string& gameid, unsigned orderid);

private:
  int position_;
  std::vector<COrder> ordersPending_;
  std::vector<COrder> ordersLive_;
  std::vector<COrder> ordersCanceling_;

  std::vector<COrder> outboundAdds_;
  std::vector<COrder> outboundCancels_;

public:
  // Accessors for python controller.
  CGateway();
  void reset();
  void setPosition(int pos);
  void setOrdersPending(const std::vector<COrder>& orders);
  void setOrdersLive(const std::vector<COrder>& orders);
  void setOrdersCanceling(const std::vector<COrder>& orders);
  const std::vector<COrder>& outboundAdds() const;
  const std::vector<COrder>& outboundCancels() const;
};

#endif
