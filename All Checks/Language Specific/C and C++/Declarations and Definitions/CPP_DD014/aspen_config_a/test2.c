#include "test1.h"

// Objects - no extern keyword
int int0_a;
int int1_a;
int int2_a = 2;
INT int3_a;
INT int4_a;
INT int5_a = 5;
INT int6_a;     // UndCC_Violation - Type is int in other declaration
INT int7_a;     // UndCC_Violation - Type is int in other declaration
INT int8_a = 8; // UndCC_Violation - Type is int in other declaration

// Objects - extern keyword in other file
int int9_a;
int int10_a = 10;
INT int11_a;
INT int12_a = 12;
INT int13_a;      // UndCC_Violation - Type is int in other declaration
INT int14_a = 12; // UndCC_Violation - Type is int in other declaration

// Objects - comma-separated declaration, pointers
int int17_a, **int16_a;
INT int19_a, *int18_a; // UndCC_Violation - Type is int in other declaration

// Objects - functional macro arguments
#define INT_var(identifier) INT identifier
#define int_var(identifier) int identifier
INT_var(int20_a); // UndCC_FalseNeg - Macro in this declaration prevents seeing custom type
int_var(int21_a);

// Functions - functional macro arguments
#define VOID_fn(identifier) VOID identifier (VOID)
#define void_fn(identifier) void identifier (void)
VOID_fn(fn0_a) { } // UndCC_FalseNeg - Macro in this declaration prevents seeing custom type
void fn0_a(void);  // UndCC_FalseNeg - Macro in above declaration
void_fn(fn1_a) { }
void fn1_a(void);
