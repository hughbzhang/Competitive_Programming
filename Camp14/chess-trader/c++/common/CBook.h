#ifndef __CBOOK_H__
#define __CBOOK_H__

class CBook
{
public:
  // Methods for C++ strategy classes.

  // Accessors for book price, quantity, and num orders information.
  unsigned bidLevels() const;
  unsigned askLevels() const;

  unsigned bidPrice(unsigned i) const;
  unsigned askPrice(unsigned i) const;

  unsigned bidQuantity(unsigned i) const;
  unsigned askQuantity(unsigned i) const;

  unsigned bidOrders(unsigned i) const;
  unsigned askOrders(unsigned i) const;

  static const unsigned MAX_LEVELS = 5;

private:
  struct Level
  {
    unsigned price;
    unsigned quantity;
    unsigned orders;
  };

  unsigned bidLevels_;
  unsigned askLevels_;
  Level bids_[MAX_LEVELS];
  Level asks_[MAX_LEVELS];

public:
  // Accessors for python controller.
  CBook();
  void reset();
  void setBid(unsigned i, unsigned price, unsigned quantity, unsigned orders);
  void setAsk(unsigned i, unsigned price, unsigned quantity, unsigned orders);
};

#endif
