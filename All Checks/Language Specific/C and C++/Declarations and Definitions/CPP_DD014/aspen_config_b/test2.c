#include "test1.h"

// Objects - no extern keyword
int int0_b;
int int1_b;
int int2_b = 2;
INT int3_b;
INT int4_b;
INT int5_b = 5;
INT int6_b;     // UndCC_Violation - Type is int in other declaration
INT int7_b;     // UndCC_Violation - Type is int in other declaration
INT int8_b = 8; // UndCC_Violation - Type is int in other declaration

// Objects - extern keyword in other file
int int9_b;
int int10_b = 10;
INT int11_b;
INT int12_b = 12;
INT int13_b;      // UndCC_Violation - Type is int in other declaration
INT int14_b = 12; // UndCC_Violation - Type is int in other declaration

// Objects - comma-separated declaration, pointers
int int17_b, **int16_b;
INT int19_b, *int18_b; // UndCC_Violation - Type is int in other declaration

// Objects - functional macro arguments
#define INT_var(identifier) INT identifier
#define int_var(identifier) int identifier
INT_var(int20_b); // UndCC_FalseNeg - Macro in this declaration prevents seeing custom type
int_var(int21_b);

// Functions - functional macro arguments
#define VOID_fn(identifier) VOID identifier (VOID)
#define void_fn(identifier) void identifier (void)
VOID_fn(fn0_b) { } // UndCC_FalseNeg - Macro in this declaration prevents seeing custom type
void fn0_b(void);  // UndCC_FalseNeg - Macro in above declaration
void_fn(fn1_b) { }
void fn1_b(void);
