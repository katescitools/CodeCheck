#include <setjmp.h>

static jmp_buf env;

int main() {
  void (*myLeastFavoriteFunction)(_JBTYPE *, int) = &longjmp; // UndCC_Valid

  setjmp(env);      // UndCC_Violation
  _setjmp(env);     // UndCC_Violation
  longjmp(env, 1);  // UndCC_Violation
  _longjmp(env, 1); // UndCC_Violation
}
