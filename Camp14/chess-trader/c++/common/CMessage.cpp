#include <CMessage.h>

CExchangeMessage::Type CExchangeMessage::type() const
{
  return type_;
}

const COrder& CExchangeMessage::order() const
{
  return order_;
}

CExchangeMessage::CExchangeMessage()
{
  type_ = EXCHANGE_UNKNOWN;
}

CExchangeMessage::CExchangeMessage(const std::string& type, COrder order)
  : order_(order)
{
  if      (type == "XN") type_ = EXCHANGE_NEW_GAME;
  else if (type == "XA") type_ = EXCHANGE_ADD_ORDER;
  else if (type == "XC") type_ = EXCHANGE_CANCEL_ORDER;
  else if (type == "XT") type_ = EXCHANGE_TRADE;
  else                   type_ = EXCHANGE_UNKNOWN;
}

CChessMessage::Type CChessMessage::type() const
{
  return type_;
}

const std::string& CChessMessage::gameid() const
{
  return gameid_;
}

const std::string& CChessMessage::move() const
{
  return move_;
}

const std::vector<std::string>& CChessMessage::history() const
{
  return history_;
}

CChessMessage::CChessMessage()
{
  type_ = CHESS_UNKNOWN;
  gameid_ = std::string();
}

CChessMessage::CChessMessage(
  const std::string& type,
  const std::string& gid,
  const std::string& move,
  const std::vector<std::string>& history,
  const std::string& result)
  : gameid_(gid)
  , move_(move)
  , history_(history)
  , result_(result)
{
  if      (type == "CN") type_ = CHESS_NEW_GAME;
  else if (type == "CM") type_ = CHESS_MOVE;
  else if (type == "CR") type_ = CHESS_RESULT;
  else                   type_ = CHESS_UNKNOWN;
}

