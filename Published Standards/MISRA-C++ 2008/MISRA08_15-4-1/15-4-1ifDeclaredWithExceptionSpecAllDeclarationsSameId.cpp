// Translation unit A
void foo( ) throw ( const char * )
{
  throw "Hello World!";
}
// Translation unit B
// foo declared in this translation unit with a different exception
// specification
extern void foo ( ) throw ( int ); // UndCC_Violation -
// different specifier
void b ( ) throw ( int )
{
  foo ( ); // The behaviour here is undefined.
}
