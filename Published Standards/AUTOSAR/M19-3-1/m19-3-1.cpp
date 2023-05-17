#include <cstdlib>
#include <cerrno>
void f1 ( const char * str )
{
  errno = 0; // UndCC_Violation
  int32_t i = atoi ( str );
  if ( 0 != errno ) // UndCC_Violation
  {
    // handle error case???
  }
}
