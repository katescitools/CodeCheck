typedef int my_type;
typedef long my_type; // UNDCC_Violation

typedef struct { int a; int b; } my_struct;
typedef struct { int c; int d; } another_struct;
typedef another_struct my_struct; // UNDCC_Violation 

typedef union { int a; float b; } my_union;
typedef union { int c; float d; } another_union;
typedef another_union my_union; // UNDCC_Violation
