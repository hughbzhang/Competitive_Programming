#ifndef __CSTRATEGY_H__
#define __CSTRATEGY_H__

#include <CMessage.h>
#include <CGateway.h>
#include <CBook.h>
#include <CBoard.h>
#include <CStockfish.h>

////////////////////////////////////////////////////////////
// All specific strategies must subclass from CStrategy
// and implement onExchangeMessage() and onChessMessage().
// All relevant state is accessible through the gateway,
// book, board, and stockfish objects.
//
// onExchangeMessage(): you get this callback whenever a new
//   event happens at the exchange, such as someone adding
//   or canceling an order, or a trade occuring
//
// onChessMessage(): you get this callabck whenever a chess
//   game broadcasts a new move, the ChessMessage object
//   will give you the current move and the entire history
//   of moves
//
// gateway: provides getters for all live, pending, and
//  canceling orders, also methods for submitting your own
//  new orders and canceling your existing orders
//
// book: provides a 5-level view on each of the buy and sell
//   sides of passive orders that are live and available to
//   trade against
//
// board: simple representation of the chessboard, up to
//   date with history of the current game
//
// stockfish: provides metrics/scores computed by the open-
//   source stockfish chess engine, might be useful in
//   building your own strategies
////////////////////////////////////////////////////////////

class CStrategy
{
public:
  // Callbacks to be implemented by subclasses.
  virtual void onExchangeMessage(const CExchangeMessage& em) = 0;
  virtual void onChessMessage(const CChessMessage& cm) = 0;

  // Methods for C++ strategy classes.
  CGateway& gateway();
  const CGateway& gateway() const;
  const CBook& book() const;
  const CBoard& board() const;
  const CStockfish& stockfish() const;

private:
  CGateway gateway_;
  CBook book_;
  CBoard board_;
  CStockfish stockfish_;

public:
  // Accessors for python controller.
  CStrategy() {}
  virtual ~CStrategy() {}
  CBook& book();
  CBoard& board();
  CStockfish& stockfish();
};

#endif
