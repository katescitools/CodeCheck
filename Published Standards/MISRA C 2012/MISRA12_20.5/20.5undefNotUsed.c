#define QUALIFIER volatile

#undef QUALIFIER /* UndCC_Violation */

void f ( QUALIFIER int32_t p )
{
	while ( p != 0 )
	{
		; /* Wait... */
	}
}
