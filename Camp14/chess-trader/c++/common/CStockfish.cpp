#include <CStockfish.h>
#include <limits>
#include <stdexcept>

const std::string& CStockfish::getFEN() const
{
  return fen_;
}

const std::vector<std::string>& CStockfish::legalMoves() const
{
  return legalMoves_;
}

float CStockfish::percentMidGame() const
{
  return percentMidGame_;
}

float CStockfish::percentEndGame1() const
{
  return percentEndGame1_;
}

float CStockfish::percentEndGame2() const
{
  return percentEndGame2_;
}

float CStockfish::totalScore() const
{
  return totalScore_;
}

float CStockfish::score(ScoreType scoreType, ScoreSubtype scoreSubtype) const
{
  return scores_[scoreType][scoreSubtype];
}

CStockfish::CStockfish()
{
  reset();
}

void CStockfish::reset()
{
  fen_ = "";
  legalMoves_.clear();
  percentMidGame_ = 0;
  percentEndGame1_ = 0;
  percentEndGame2_ = 0;
  totalScore_ = 0;
  for (unsigned i=0; i < NUM_SCORE_TYPES; ++i) {
    for (unsigned j=0; j < NUM_SCORE_SUBTYPES; ++j)
      scores_[i][j] = std::numeric_limits<float>::quiet_NaN();
  }
}

void CStockfish::setFEN(const std::string& fen)
{
  fen_ = fen;
}

void CStockfish::setLegalMoves(const std::string& legalMoves)
{
  if (legalMoves == "")
    return;

  // legalMoves is space delimited string of moves. Split
  // and store in vector.
  size_t start=0, end=0;
  while ((end = legalMoves.find(" ", start)) != std::string::npos) {
    std::string move = legalMoves.substr(start, end - start);
    legalMoves_.push_back(move);
    start = end + 1;
  }
  std::string move = legalMoves.substr(start);
  legalMoves_.push_back(move);
}

void CStockfish::setTotal(float pm, float pe1, float pe2, float ts)
{
  percentMidGame_ = pm;
  percentEndGame1_ = pe1;
  percentEndGame2_ = pe2;
  totalScore_ = ts;
}

void CStockfish::setScore(
  const std::string& scoreType,
  const std::string& scoreSubtype,
  float score)
{
  ScoreType t = NUM_SCORE_TYPES;
  ScoreSubtype st = NUM_SCORE_SUBTYPES;

  if      (scoreType == "Material, PST, Tempo") t = MATERIAL_PST_TEMPO;
  else if (scoreType == "Material imbalance")   t = MATERIAL_IMBALANCE;
  else if (scoreType == "Pawns")                t = PAWNS;
  else if (scoreType == "Knights")              t = KNIGHTS;
  else if (scoreType == "Bishops")              t = BISHOPS;
  else if (scoreType == "Rooks")                t = ROOKS;
  else if (scoreType == "Queens")               t = QUEENS;
  else if (scoreType == "Mobility")             t = MOBILITY;
  else if (scoreType == "King safety")          t = KING_SAFETY;
  else if (scoreType == "Threats")              t = THREATS;
  else if (scoreType == "Passed pawns")         t = PASSED_PAWNS;
  else if (scoreType == "Space")                t = SPACE;
  else if (scoreType == "Total")                t = TOTAL;
  else throw std::runtime_error("Unknown score type");

  if      (scoreSubtype == "WM") st = WHITE_MID_GAME;
  else if (scoreSubtype == "WE") st = WHITE_END_GAME;
  else if (scoreSubtype == "BM") st = BLACK_MID_GAME;
  else if (scoreSubtype == "BE") st = BLACK_END_GAME;
  else if (scoreSubtype == "TM") st = TOTAL_MID_GAME;
  else if (scoreSubtype == "TE") st = TOTAL_END_GAME;
  else throw std::runtime_error("Unkown score subtype");

  scores_[t][st] = score;
}

