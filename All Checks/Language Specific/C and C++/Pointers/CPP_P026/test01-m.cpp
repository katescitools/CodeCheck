#include <cstdint>
#include <iostream>

using namespace std;

typedef int MYINT;

int* f03(int);

struct S
{
  int32_t i;
  int32_t j;
};
void f01(S* s)
{
  int32_t p = reinterpret_cast<int32_t>(s); /* UNDCC_VIOLATION */
}

void f02(int* a, int b)
{
  int c = (int64_t)a; /* UNDCC_VIOLATION */
}

int* f03(int a)
{
  return &a;
}

int main() {

  int x = 5;
  int* xp = &x;

  int xpc = (int)xp; /* UNDCC_VIOLATION */
  
  int xpc2 = (int)&x; /* UNDCC_FalseNeg - Computed values can't be recognized */
  int xpc3 = (int)f03(x); /* UNDCC_FalseNeg - Computed values can't be recognized */
  
  f02(xp, reinterpret_cast<int32_t>(xp)); /* UNDCC_VIOLATION */
  
  char a = 'b';
  char* ap = &a;
  
  int xpc4 = reinterpret_cast<int>(ap); /* UNDCC_VIOLATION */
  int xpc5 = (int64_t)ap; /* UNDCC_VIOLATION */
  int xpc6 = (MYINT)ap;  /* UNDCC_VIOLATION */
  int xpc7 = reinterpret_cast<MYINT>(ap); /* UNDCC_VIOLATION */

  return 0;
}
