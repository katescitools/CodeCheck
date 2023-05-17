#include <stdbool.h>

void test5 ()
{
  int number = 3;
  bool expression = true;

  do // UndCC_Valid - 0 gotos
  {
    #include "test5.inc"
  }
  while (expression);

  do // UndCC_Valid - 0 gotos
  {
    if (expression)
      break;

    #include "test5.inc"
  }
  while (expression);
}
