#include <stdint.h>

void f(void) {
  
}

void func(unsigned int flag) {
  
  char *ptr;
  /* ... */
  uintptr_t number0 = (uintptr_t)ptr; /* UNDCC_Violation */
  /* ... */
  
  char *ptr1;
  unsigned int number = (unsigned int)ptr1; /* UNDCC_Violation */
  number = (number & 0x7fffff) | (flag << 23);
  ptr1 = (char *)number;
  
  int *p;
  int addr = ( int ) &p; /* UNDCC_FalseNeg - Computed values can't be recognized */
}
