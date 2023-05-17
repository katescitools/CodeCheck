// Multiple lines

#define y /* UndCC_Valid */ \
        x /* UndCC_Violation */

#if y == 0 && /* UndCC_Valid */ \
    y != 1    /* UndCC_Valid */
#endif


// Functional macros

#define MIN(A, B) ((A) > (B) ? (B) : (A)) // UndCC_Valid

#define my_int int                        // UndCC_Valid

#if my_int == int                         // UndCC_Valid
#endif


// Code identifier used in preprocessor directive

static const int raspberry = 1;
void pick(int berry) {}

#define my_berry raspberry // UndCC_Valid

#if raspberry              // UndCC_Valid
#endif

#define my_picker pick // UndCC_Valid

#if pick               // UndCC_Valid
#endif


// Keywords

#define my_int int // UndCC_Valid
