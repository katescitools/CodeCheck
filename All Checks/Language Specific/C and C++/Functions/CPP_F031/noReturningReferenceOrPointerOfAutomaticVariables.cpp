#include <cstdint>

int32_t * fn1( void )
{
    int32_t x = 99;
    return ( &x );         // UNDCC_Violation
}
int32_t * fn2( int32_t y )
{
    return ( &y );         // UNDCC_Violation
}
int32_t & fn3( void )
{
    int32_t x = 99;
    return ( x );          // UNDCC_Violation
}
int32_t & fn4( int32_t y )
{
    return ( y );          // UNDCC_Violation
}
int32_t * fn5 ( void )
{
    static int32_t x = 0;
    return &x;             // UNDCC_Valid
}
int32_t * fn6( bool s )
{
    static int32_t x = 0;
    int32_t y;
    bool samp = s;
    return samp ? &x : &y; // UNDCC_Violation - if y is returned
}
int32_t * fn7( int32_t * y )
{
    return ( y );          // UNDCC_Valid
}
char * fn8( unsigned char * x )
{
    return ( char * ) x;   // UNDCC_Valid
}
const char * fn9( char x )
{
    return ( char * ) x;   // UNDCC_Valid
}
int32_t & fn10( int32_t & y )
{
    return ( y );          // UNDCC_Valid
}
