#define M( A ) printf ( #A )
#include <stdio.h>
int main ( void )
{
	M ( // UndCC_Violation
#ifdef SW 
		"Message 1"
#else 
		"Message 2"
#endif 
	);
	return 1;
}
