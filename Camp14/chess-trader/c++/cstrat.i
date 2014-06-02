////////////////////////////////////////////////////////////
// SWIG interface file. You will not need to touch this.
////////////////////////////////////////////////////////////

%module cstrat

%{
#define SWIG_FILE_WITH_INIT
#include "common/CBook.h"
#include "common/COrder.h"
#include "common/CGateway.h"
#include "common/CBoard.h"
#include "common/CStockfish.h"
#include "common/CMessage.h"
#include "common/CStrategy.h"
#include "CFactory.h"
%}

%include std_string.i
%include std_vector.i

namespace std {
  %template(vector_s) vector<string>;
  %template(vector_o) vector<COrder>;
}

%exception {
  try {
    $action
  } catch(std::runtime_error& e) {
    PyErr_SetString(PyExc_RuntimeError, const_cast<char*>(e.what()));
    return NULL;
  }
}

%include "common/CBook.h"
%include "common/COrder.h"
%include "common/CGateway.h"
%include "common/CBoard.h"
%include "common/CStockfish.h"
%include "common/CMessage.h"
%include "common/CStrategy.h"
%include "CFactory.h"

