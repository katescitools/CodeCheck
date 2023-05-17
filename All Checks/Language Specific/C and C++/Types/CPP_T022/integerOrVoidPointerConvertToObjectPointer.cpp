#include <cstdint>

typedef int32_t myInt;
typedef void myVoid;
typedef myInt osbcureInt;

struct S
{
  int32_t i;
  int32_t j;
};

void f ( void * v, int32_t i )
{
  char * v2;
  S * s1 = reinterpret_cast< S * >( v ); // UndCC_Violation
  S * s2 = reinterpret_cast< S * >( i ); // UndCC_Violation
  S * s3;
  
  s3 = reinterpret_cast< S * >( v2 ); // UndCC_Valid
}

void g ( myVoid * v, myInt i )
{
  char * v2;
  S * s2 = reinterpret_cast< S * >( i ); // UndCC_Violation
  S * s1 = reinterpret_cast< S * >( v ); // UndCC_Violation
}

void h ( void * v, osbcureInt i )
{
  S * s1 = reinterpret_cast< S * >( v ); // UndCC_Violation
  S * s2 = reinterpret_cast< S * >( i ); // UndCC_Violation
}

