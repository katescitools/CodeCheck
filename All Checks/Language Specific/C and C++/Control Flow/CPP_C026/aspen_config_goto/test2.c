#include <stdbool.h>

void test2 ()
{
  bool expression = true;

  do     // UndCC_Valid - 0 gotos
  {
    do { // UndCC_Valid - 0 gotos
      break;
    } while (expression);

    if (expression)
      break;
    else
      break;
  }
  while (expression);
}
