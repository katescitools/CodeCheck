#include <h3.h>         // UndCC_Valid
#include <h1.hpp>       // UndCC_Valid
#include <h2.hxx>       // UndCC_Valid
#include <h4.cpp>       // UndCC_Violation
#include <h5.c>         // UndCC_Violation
#include "h6.hdr"       // UndCC_Valid - not defined in the project
#include "h7.inc"       // UndCC_Valid - not defined in the project
#include "hello.h"      // UndCC_Valid
#include "goodbye.cpp"  // UndCC_Violation
