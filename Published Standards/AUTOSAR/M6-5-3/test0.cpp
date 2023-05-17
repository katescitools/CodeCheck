bool modify ( int * pX )
{
  *pX++;
  return ( *pX < 10 );
}

int main () {
	for ( int x = 0; modify ( &x ); ) // UndCC_Violation
	{
	}
	for ( int x = 0; x < 10; )
	{
		x = x * 2; // UndCC_Violation
	}
	return 0;
}
