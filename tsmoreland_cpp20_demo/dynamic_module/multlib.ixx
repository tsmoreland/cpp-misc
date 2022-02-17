module;
#include "export.h"

export module multlib;


export namespace tsmoreland::math::multlib {

DYNAMICMODULE_EXPORT int multiply(int lhs, int rhs) { return lhs * rhs; }

}  // namespace tsmoreland::main::multlib