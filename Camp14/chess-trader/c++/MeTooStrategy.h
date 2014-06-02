#ifndef __ME_TOO_STRATEGY_H__
#define __ME_TOO_STRATEGY_H__

#include <CStrategy.h>

////////////////////////////////////////////////////////////
// Example C++ strategy that simply looks at the best bid
// and offer prices in the book, and places orders at those
// prices too. Like all C++ strategies, this is a subclass
// of CStrategy and implements onExchangeMessage() and onChessMessage().
////////////////////////////////////////////////////////////

class MeTooStrategy : public CStrategy
{
public:
  MeTooStrategy();
  virtual ~MeTooStrategy();

  ////////////////////////////////////////////////////////// 
  // All CStrategy subclass must implement these methods.
  ////////////////////////////////////////////////////////// 
  void onExchangeMessage(const CExchangeMessage& em);
  void onChessMessage(const CChessMessage& cm);

private:
  void cancelAllOrders();

  const unsigned maxPosition_;
  const unsigned maxOrderQuantity_;
};

#endif
