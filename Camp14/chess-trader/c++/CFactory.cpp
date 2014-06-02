////////////////////////////////////////////////////////////
// Add all C++ strategies here:
// 1) as a #include, and
// 2) mapping a string name to the class constructor
////////////////////////////////////////////////////////////

#include "CFactory.h"
#include "MaterialCountStrategy.h"
#include "StockfishStrategy.h"
#include "MeTooStrategy.h"
#include "Salmon.h"
#include <stdexcept>

CStrategy* CFactory::makeStrategy(const std::string& strategyName)
{
  if (strategyName == "MaterialCountStrategy")
    return new MaterialCountStrategy();
  else if (strategyName == "StockfishStrategy")
    return new StockfishStrategy();
  else if (strategyName == "MeTooStrategy")
    return new MeTooStrategy();
  else if(strategyName == "Salmon")
      return new Salmon();
  else
    throw std::runtime_error("Unknown strategy type");
}
