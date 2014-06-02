#include <CBoard.h>
#include <stdexcept>

char CBoard::getPiece(unsigned row, unsigned col) const
{
  if (row >= CHESS_BOARD_DIM || col >= CHESS_BOARD_DIM)
    throw std::runtime_error("Chess board is 8x8, cannot access out of bounds");
  return board_[row][col];
}

CBoard::CBoard()
{
  for (unsigned r=0; r < CHESS_BOARD_DIM; ++r) {
    for (unsigned c=0; c < CHESS_BOARD_DIM; ++c)
      board_[r][c] = '.';
  }
}

void CBoard::setPiece(unsigned row, unsigned col, char piece)
{
  if (row >= CHESS_BOARD_DIM || col >= CHESS_BOARD_DIM)
    throw std::runtime_error("Chess board is 8x8, cannot access out of bounds");
  board_[row][col] = piece;
}

