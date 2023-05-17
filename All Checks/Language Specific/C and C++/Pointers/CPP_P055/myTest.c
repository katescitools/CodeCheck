#include <stdio.h>


int main() {
  int *myPointer; // VALID // UndCC_Valid
  int ***myTriplePointer; // VALID // UndCC_Valid
  int *myNum = 10; // VALID // UndCC_Valid
  char* myChar;  // INVALID
  char * myOtherChar; // INVALID // UndCC_Violation

  return 0;
}
