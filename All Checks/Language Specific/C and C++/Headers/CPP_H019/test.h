// UndCC_Valid
class TargetClass;
class SourceClass
{
  TargetClass *pTargetClass;
};


#include "TargetClass.h" // UndCC_Violation
class SourceClass1 {
  TargetClass *pTargetClass;
};
