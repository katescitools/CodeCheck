void valid() {
  int a = 1;
  int b = 1;
  if (a == b) {};  // UndCC_Valid
}

void optional() {
  int a = 1;
  int b = 1;
  if ((a = b)) {}; // UndCC_Valid - Exception allowed
}

void invalid() {
  int a = 1;
  int b = 1;
  if (a = b) {};   // UndCC_Violation
}
