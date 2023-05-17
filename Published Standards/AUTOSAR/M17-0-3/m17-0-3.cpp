#include <cinttypes>

int32_t printf ( int32_t a, int32_t b ) // UndCC_Violation
{
	return ( ( a > b ) ? a : b );
}