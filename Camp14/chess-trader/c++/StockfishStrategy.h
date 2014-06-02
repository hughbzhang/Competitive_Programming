#ifndef __STOCKFISH_STRATEGY_H__
#define __STOCKFISH_STRATEGY_H__

#include <CStrategy.h>

////////////////////////////////////////////////////////////
// Example C++ strategy that estimates the probability that
// white will win by using the stockfish metrics. Like all
// C++ strategies, this is a subclass of CStrategy and
// implements onExchangeMessage() and onChessMessage().
////////////////////////////////////////////////////////////

class StockfishStrategy : public CStrategy
{
public:
  StockfishStrategy();
  virtual ~StockfishStrategy();

  ////////////////////////////////////////////////////////// 
  // All CStrategy subclass must implement these methods.
  ////////////////////////////////////////////////////////// 
  void onExchangeMessage(const CExchangeMessage& em);
  void onChessMessage(const CChessMessage& cm);

private:
  void cancelAllOrders();
  unsigned computeFairPrice() const;

  const unsigned maxPosition_;
  const unsigned maxOrderQuantity_;
};

#endif
