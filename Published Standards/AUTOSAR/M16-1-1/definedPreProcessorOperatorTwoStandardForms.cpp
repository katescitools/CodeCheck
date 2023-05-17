#if defined ( X > Y ) // UndCC_Violation – constraint violation
#endif
#define DEFINED defined // UndCC_Violation
#if DEFINED(X)  
#endif
#defined A // UndCC_Valid
#if defined ( B ) // UndCC_Valid
#endif