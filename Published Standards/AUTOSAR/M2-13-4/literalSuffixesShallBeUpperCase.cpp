const unsigned int a = 0U;
const unsigned int b = 0u; // UndCC_Violation
const long int c = 0L;
const long int d = 0l; // UndCC_Violation
const unsigned long int e = 0UL;
const unsigned long int f = 0Ul; // UndCC_Violation
const unsigned int g = 0x12bU;
const unsigned int h = 0x12bu; 
const float m = 1.2F;
const float n = 2.4f; // UndCC_Violation
const double o = 1.2L;
const double p = 2.4l; // UndCC_Violation
const double q = o;
double r = p;

// No violations should be reported in inactive code
#if 0

const unsigned int a = 0U;
const unsigned int b = 0u; // UndCC_Violation but inactive
const long int c = 0L;
const long int d = 0l; // UndCC_Violation but inactive
const unsigned long int e = 0UL;
const unsigned long int f = 0Ul; // UndCC_Violation but inactive but inactive
const unsigned int g = 0x12bU;
const unsigned int h = 0x12bu; 
const float m = 1.2F;
const float n = 2.4f; // UndCC_Violation but inactive
const double o = 1.2L;
const double p = 2.4l; // UndCC_Violation but inactive
const double q = o;
double r = p;

#endif
