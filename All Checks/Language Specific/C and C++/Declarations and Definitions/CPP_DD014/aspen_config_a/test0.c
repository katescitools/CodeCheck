#include <stdint.h>
#include <stdbool.h>
#define bool_t bool

// MISRA C 2012

extern void f_a ( signed int );  // UndCC_Valid - Exception allows the same primitive types
       void f_a (        int );  // UndCC_Valid - Exception allows the same primitive types
extern void g_a ( int * const ); // UndCC_Violation - Type qualifier const
       void g_a ( int *       ); // UndCC_Violation - No type qualifier const


extern int16_t func_a ( int16_t num, int16_t den );  // UndCC_Violation - Parameter names different

int16_t func_a ( int16_t den, int16_t num )          // UndCC_Violation - Parameter names different
{
  return num / den;
}


typedef uint16_t width_t;
typedef uint16_t height_t;
typedef uint32_t area_t;

extern area_t area_a ( width_t w, height_t h ); // UndCC_Violation - Parameter types different

area_t area_a ( width_t w, width_t h )          // UndCC_Violation - Parameter types different
{
  return ( area_t ) w * h;
}


extern void f1_a ( int16_t x );
extern void f2_a ( int16_t y );

void h_a ( bool_t b )
{
  void ( *fp1 ) ( int16_t z ) = b ? f1_a : f2_a;
}
