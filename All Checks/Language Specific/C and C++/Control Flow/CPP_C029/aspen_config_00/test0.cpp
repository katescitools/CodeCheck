#include <cstdint>

#define expression 1

// MISRA C++ 2008

void fn ( void )
{
  if ( expression )
  {
    return;  // UndCC_Violation - early return
  }
  try
  {
    if ( expression )
    {
      throw ( 1 );
    }
  }
  catch ( int32_t )
  {
    throw;
  }
  return;
}
void fn2 ( void )
{
  try
  {
    return;  // UndCC_Violation - early return
  }
  catch ( ... )
  {
    return;  // UndCC_Violation - early return
  }
}
void fn3 ( void ) try
{
  return;
}
catch ( int32_t )
{
  return;
}
catch ( ... )
{
  return;
}
