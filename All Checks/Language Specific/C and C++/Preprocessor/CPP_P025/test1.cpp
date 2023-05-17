// Operator: defined

#if defined ( X > Y ) // UndCC_Valid
#endif

#define DEFINED defined
#if DEFINED(X)        // UndCC_Violation - macro expansion to 'defined' is undefined behavior
#endif

#defined A            // UndCC_Valid - not in a real preprocessor directive

#if defined ( B )     // UndCC_Valid
#endif
