int fun(int a) {
  int i = 10;
  return i + a;
  i++;             /* UndCC_Violation unreachable code */
}
