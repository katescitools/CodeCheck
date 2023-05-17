#include <cstdint>

#define expression 1

// MISRA C++ 2008

void fn ( void )      // UndCC_Violation - 1 early return
{
  if ( expression )
  {
    return;
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
void fn2 ( void )     // UndCC_Violation - 2 early returns
{
  try
  {
    return;
  }
  catch ( ... )
  {
    return;
  }
}
void fn3 ( void ) try // UndCC_Valid - 1 return at each end
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
