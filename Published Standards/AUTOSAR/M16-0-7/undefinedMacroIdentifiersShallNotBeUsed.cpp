#if x < 0  
#endif
#if defined ( X > Y ) // UndCC_Valid
#endif
#define DEFINED defined
#if DEFINED(X) // UndCC_Violation
#endif
#defined A // UndCC_Valid
#if defined ( B ) // UndCC_Valid
#endif
