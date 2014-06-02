#ifndef __CBOARD_H__
#define __CBOARD_H__

#define CHESS_BOARD_DIM 8

class CBoard
{
public:
  // Methods for C++ strategy classes.

  // '.' indicates no piece
  // Upper case indicates white piece
  // Lower case indicates black piece
  // Possible pieces are:
  // 'p' = pawn
  // 'n' = night
  // 'b' = bishop
  // 'r' = rook
  // 'q' = queen
  // 'k' = king
  char getPiece(unsigned row, unsigned col) const;

private:
  char board_[CHESS_BOARD_DIM][CHESS_BOARD_DIM];

public:
  // Accessors for python controller.
  CBoard();
  void setPiece(unsigned row, unsigned col, char piece);
};

#endif
