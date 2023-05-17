#include <stdio.h> // UndCC_Violation
void fn ( )
{
  char_t array [ 10 ];
  gets ( array ); // Can lead to buffer over-run
}
