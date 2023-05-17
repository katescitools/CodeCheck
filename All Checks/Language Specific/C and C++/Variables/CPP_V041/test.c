#include <stdio.h>

int i;

void foo() {
  int i;    //UndCC_Violation This is a different variable, flag violation
  
  i = 10;   /* Could be confusing as to which variable this references */
}
