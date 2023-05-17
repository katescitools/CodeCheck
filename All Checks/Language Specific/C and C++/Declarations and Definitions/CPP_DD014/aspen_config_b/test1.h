// See test2.c for other declarations

typedef int INT;
typedef void VOID;

// Objects - no extern keyword
int int0_b;
int int1_b = 1;
int int2_b;
INT int3_b;
INT int4_b = 4;
INT int5_b;
int int6_b;     // UndCC_Violation - Type is INT in other declaration
int int7_b = 4; // UndCC_Violation - Type is INT in other declaration
int int8_b;     // UndCC_Violation - Type is INT in other declaration

// Objects - extern keyword in this file
extern int int9_b;
extern int int10_b;
extern INT int11_b;
extern INT int12_b;
extern int int13_b; // UndCC_Violation - Type is INT in other declaration
extern int int14_b; // UndCC_Violation - Type is INT in other declaration

// Objects - comma-separated declaration, pointers
int **int16_b, int17_b;
int *int18_b, int19_b; // UndCC_Violation - Type is INT in other declaration

// Objects - functional macro arguments
int int20_b; // UndCC_FalseNeg - Macro in another declaration prevents seeing custom type
int int21_b;
