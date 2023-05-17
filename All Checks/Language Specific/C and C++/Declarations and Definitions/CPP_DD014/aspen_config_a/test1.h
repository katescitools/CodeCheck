// See test2.c for other declarations

typedef int INT;
typedef void VOID;

// Objects - no extern keyword
int int0_a;
int int1_a = 1;
int int2_a;
INT int3_a;
INT int4_a = 4;
INT int5_a;
int int6_a;     // UndCC_Violation - Type is INT in other declaration
int int7_a = 4; // UndCC_Violation - Type is INT in other declaration
int int8_a;     // UndCC_Violation - Type is INT in other declaration

// Objects - extern keyword in this file
extern int int9_a;
extern int int10_a;
extern INT int11_a;
extern INT int12_a;
extern int int13_a; // UndCC_Violation - Type is INT in other declaration
extern int int14_a; // UndCC_Violation - Type is INT in other declaration

// Objects - comma-separated declaration, pointers
int **int16_a, int17_a;
int *int18_a, int19_a; // UndCC_Violation - Type is INT in other declaration

// Objects - functional macro arguments
int int20_a; // UndCC_FalseNeg - Macro in another declaration prevents seeing custom type
int int21_a;
