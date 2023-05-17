#define M(A) printf ( #A )
void main ( )
{
  M ( // UndCC_Violation
#ifdef SW 
  "Message 1"
#else 
  "Message 2"
#endif 
  );
}
