int16_t usedtype() {
typedef int16_t myVar = 67; // UndCC_Violation
return myVar;
}

int16_t unusedtype() { 
  typedef int16_t local_Type; // UndCC_Violation
  return 67;
}
