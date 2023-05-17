#include "filename.h" // UndCC_Valid
#include <filename.h> // UndCC_Valid
#define HEADER "filename.h" // UndCC_Violation with Rule 16-2-2
#include HEADER // UndCC_Valid
#include another.h // UndCC_Violation
