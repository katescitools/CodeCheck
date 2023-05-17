#include <stdbool.h>
#include <stdint.h>

#define bool_t bool
#define MAX 10

// MISRA C 2012

bool_t f ( uint16_t n, char *p ) // UndCC_Violation - 2 early returns
{
  if ( n > MAX )
  {
    return false;
  }
  if ( p == NULL )
  {
    return false;
  }
  return true;
}
