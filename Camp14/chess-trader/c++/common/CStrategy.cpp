#include <CStrategy.h>

const CGateway& CStrategy::gateway() const
{
  return gateway_;
}

const CBook& CStrategy::book() const
{
  return book_;
}

const CBoard& CStrategy::board() const
{
  return board_;
}

const CStockfish& CStrategy::stockfish() const
{
  return stockfish_;
}

CGateway& CStrategy::gateway()
{
  return gateway_;
}

CBook& CStrategy::book()
{
  return book_;
}

CBoard& CStrategy::board()
{
  return board_;
}

CStockfish& CStrategy::stockfish()
{
  return stockfish_;
}

