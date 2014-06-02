#ifndef __CFACTORY_H__
#define __CFACTORY_H__
#include <CStrategy.h>

////////////////////////////////////////////////////////////
// Any C++ strategy that you create should be added to the
// makeStrategy() method in CFactory.cpp.
////////////////////////////////////////////////////////////
class CFactory
{
public:
  static CStrategy* makeStrategy(const std::string& strategyName);
};

#endif
