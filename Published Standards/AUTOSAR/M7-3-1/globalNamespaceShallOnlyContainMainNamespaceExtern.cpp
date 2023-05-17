#include <cstdint>

void f1 ( int32_t );          // UndCC_Violation
int32_t x1;                   // UndCC_Violation
namespace
{
    void f2 ( int32_t );      // UndCC_Valid
    int32_t x2;               // UndCC_Valid
}
namespace MY_API
{
    void b2 ( int32_t );      // UndCC_Valid
    int32_t x2;               // UndCC_Valid
}
int32_t main ( )              // UndCC_Valid
{
}

typedef signed short int16_t; // Exception
typedef int INT;              // UndCC_Violation

extern "C"                    // UndCC_Valid
{
    int foo()
    {
        return 1;
    }
}

extern int f3();              // UndCC_Violation

// Typedefs allowed in the global namespace by exception
typedef char char_t;
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
// typedef signed long int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
// typedef unsigned long uint64_t;
typedef float float32_t;
typedef double float64_t;
typedef long double float128_t;
