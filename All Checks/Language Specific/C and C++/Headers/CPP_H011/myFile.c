#include <stdio.h>
#include "C:\Users\john\Desktop\myFile.h" // UNDCC_Violation
#include "/Users/Mahesh/Documents/myFile.h" // UNDCC_Violation
#include "compliantHeader.h" // UNDCC_Valid
#define LAST 10

int main()
{
  int i, sum = 0;
  
  for ( i = 1; i <= LAST; i++ ) {
    sum += i;
  }
  printf("sum = %d\n", sum);

  return 0;
}

