// Conditional: ifdef
#ifdef x   // UndCC_Valid - ifdef allowed
#elifdef y // UndCC_Valid - elifdef allowed
#endif

// Conditional: ifndef
#ifndef x   // UndCC_Valid - ifndef allowed
#elifndef x // UndCC_Valid - elifndef allowed
#endif

// Conditional if defined
#if defined x && defined (y) // UndCC_Valid - defined allowed
#endif

// Conditional: if
#if x   // UndCC_Violation
#elif y // UndCC_Violation
#endif

// Replace
#define z x    // UndCC_Violation
#undef x       // UndCC_Violation
#undef z       // UndCC_Valid
#define z #x   // UndCC_Violation
#undef z       // UndCC_Valid
#define z x##y // UndCC_Violation
#undef z       // UndCC_Valid
#define z x##y // UndCC_Violation
#undef z       // UndCC_Valid

// Error and warning
#if 0
    #error x   // UndCC_Valid - string, not identifier
    #warning x // UndCC_Valid - string, not identifier
#endif

// Include
#include x           // UndCC_Violation
#if __has_include(x) // UndCC_Violation
#endif

// Implementation-defined
#pragma x // UndCC_Violation

// File name and line informations
#line x // UndCC_Violation
