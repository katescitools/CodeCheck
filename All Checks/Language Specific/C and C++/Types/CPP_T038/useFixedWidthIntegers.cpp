//% $Id: A3-9-1.cpp 289436 2017-10-04 10:45:23Z michal.szczepankiewicz $
#include <cstdint>

void F()
{
  std::int32_t i1 = 5; // UndCC_Valid
  int i2 = 10; // UndCC_Violation
  std::int64_t i3 = 250; // UndCC_Valid
  long int i4 = 50; // UndCC_Violation
  std::int8_t i5 = 16; // UndCC_Valid
  char i6 = 23; // UndCC_Violation
  wchar_t i7 = 23; // UndCC_Valid
}
