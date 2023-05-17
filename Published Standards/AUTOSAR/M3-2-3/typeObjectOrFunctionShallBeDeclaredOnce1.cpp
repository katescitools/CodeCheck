// typeObjectOrFunctionShallBeDeclaredOnce2.cpp
#include "typeObjectOrFunctionShallBeDeclaredOnce.hpp"
extern long int b; // UndCC_Violation - compiler may not detect the error
long int a; // UndCC_Valid - compiler will detect the error
