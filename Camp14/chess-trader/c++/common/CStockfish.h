#ifndef __CSTOCKFISH_H__
#define __CSTOCKFISH_H__

#include <string>
#include <vector>

////////////////////////////////////////////////////////////
// Stockfish is an open source chess engine that computes
// various metrics given the chess board state. There is
// no great documentation for the various scores, but
// they are interesting values and have some predictive
// power.
////////////////////////////////////////////////////////////

class CStockfish
{
public:
  // Enums and methods for C++ strategy classes.

  enum ScoreType {
    MATERIAL_PST_TEMPO = 0,
    MATERIAL_IMBALANCE,
    PAWNS,
    KNIGHTS,
    BISHOPS,
    ROOKS,
    QUEENS,
    MOBILITY,
    KING_SAFETY,
    THREATS,
    PASSED_PAWNS,
    SPACE,
    TOTAL,

    NUM_SCORE_TYPES
  };

  enum ScoreSubtype {
    WHITE_MID_GAME = 0,
    WHITE_END_GAME,
    BLACK_MID_GAME,
    BLACK_END_GAME,
    TOTAL_MID_GAME,
    TOTAL_END_GAME,

    NUM_SCORE_SUBTYPES
  };

  // The Forsyth-Edwards Notation for describing the chess board. See wikipedia.
  const std::string& getFEN() const;

  // A list of legal moves that the next player can make.
  const std::vector<std::string>& legalMoves() const;

  // A metric estimating the probability we are mid-game (not end-game).
  float percentMidGame() const;

  // Two metrics estimating the probability that we are end-game (soon to finish).
  float percentEndGame1() const;
  float percentEndGame2() const;

  // The ultimate stockfish score. Play around with it.
  float totalScore() const;

  // The subscores that go in to computing the total score (above).
  float score(ScoreType scoreType, ScoreSubtype scoreSubtype) const;

private:
  std::string fen_;
  std::vector<std::string> legalMoves_;
  float percentMidGame_;
  float percentEndGame1_;
  float percentEndGame2_;
  float totalScore_;
  float scores_[NUM_SCORE_TYPES][NUM_SCORE_SUBTYPES];

public:
  // Accessors for python controller.
  CStockfish();
  void reset();
  void setFEN(const std::string& fen_);
  void setLegalMoves(const std::string& legalMoves);
  void setTotal(float pm, float pe1, float pe2, float ts);
  void setScore(const std::string& scoreType, const std::string& scoreSubtype, float s);
};

#endif
