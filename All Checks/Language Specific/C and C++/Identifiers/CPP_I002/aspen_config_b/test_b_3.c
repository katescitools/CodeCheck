// Custom

// Length for C90
//  123456**********************************     Characters
int b_aaa0;
int b_aaa1;
int b_bbbb0;
int b_bbbb1;

// Length for C999
//  1234567890123456789012345678901*********     Characters
int b_cccccccccccccccccccccccccccc0;
int b_cccccccccccccccccccccccccccc1;
int b_ddddddddddddddddddddddddddddd0; // UndCC_Violation - same as the next 1
int b_ddddddddddddddddddddddddddddd1;

// Types
//          1234567890123456789012345678901*********     Characters
typedef int b_eeeeeeeeeeeeeeeeeeeeeeeeeeeee0_t; // UndCC_Violation - same as the next 1
typedef int b_eeeeeeeeeeeeeeeeeeeeeeeeeeeee1_t;

// Functions
//   1234567890123456789012345678901*********     Characters
void b_fffffffffffffffffffffffffffff0_t() {} // UndCC_Violation - same as the next 1
void b_fffffffffffffffffffffffffffff1_t() {}
