#include <stdbool.h>
#include <stdint.h>

#define bool_t bool
#define MAX 10

// MISRA C 2012

bool_t f ( uint16_t n, char *p )
{
  if ( n > MAX )
  {
    return false;  // UndCC_Violation - early return
  }
  if ( p == NULL )
  {
    return false;  // UndCC_Violation - early return
  }
  return true;
}
