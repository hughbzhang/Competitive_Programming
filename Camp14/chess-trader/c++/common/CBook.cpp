#include <CBook.h>
#include <stdexcept>

CBook::CBook()
{
  reset();
}

unsigned CBook::bidLevels() const
{
  return bidLevels_;
}

unsigned CBook::askLevels() const
{
  return askLevels_;
}

unsigned CBook::bidPrice(unsigned i) const
{
  if (i >= bidLevels_)
    throw std::runtime_error("accessing bid out of bounds");
  return bids_[i].price;
}

unsigned CBook::askPrice(unsigned i) const
{
  if (i >= askLevels_)
    throw std::runtime_error("accessing ask out of bounds");
  return asks_[i].price;
}

unsigned CBook::bidQuantity(unsigned i) const
{
  if (i >= bidLevels_)
    throw std::runtime_error("accessing bid out of bounds");
  return bids_[i].quantity;
}

unsigned CBook::askQuantity(unsigned i) const
{
  if (i >= askLevels_)
    throw std::runtime_error("accessing ask out of bounds");
  return asks_[i].quantity;
}

unsigned CBook::bidOrders(unsigned i) const
{
  if (i >= bidLevels_)
    throw std::runtime_error("accessing bid out of bounds");
  return bids_[i].orders;
}

unsigned CBook::askOrders(unsigned i) const
{
  if (i >= askLevels_)
    throw std::runtime_error("accessing ask out of bounds");
  return asks_[i].orders;
}

void CBook::reset()
{
  bidLevels_ = askLevels_ = 0;
}

void CBook::setBid(
  unsigned i, unsigned price, unsigned quantity, unsigned orders)
{
  if (i >= 5)
    throw std::runtime_error("book has max 5 levels");
  if (bidLevels_ <= i)
    bidLevels_ = i+1;
  bids_[i].price = price;
  bids_[i].quantity = quantity;
  bids_[i].orders = orders;
}

void CBook::setAsk(
  unsigned i, unsigned price, unsigned quantity, unsigned orders)
{
  if (i >= 5)
    throw std::runtime_error("book has max 5 levels");
  if (askLevels_ <= i)
    askLevels_ = i+1;
  asks_[i].price = price;
  asks_[i].quantity = quantity;
  asks_[i].orders = orders;
}

