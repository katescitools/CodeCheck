// Magic Numbers are bad
#define VALIDMACRO = 111;

enum validEnum { VALID2 = 222 };

const int Valid3 = 5;

void validFunc(){
  int Valid1 = 100;  // UndCC_Violation
}

void violationFunc(){
int Violation1, Violation2;
    Violation1 = Valid2 + 57; // UndCC_Violation
    Violation2 = 5 + 7; // UndCC_Violation
}

void testExceptions(){
  int Exception1, Exception2;
  Exception1= 1 + Valid1;
  Exception2= Valid3 + 1024;
}
