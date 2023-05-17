#include <typeinfo>

class B1_1211
{
public:
  B1_1211 ( )
  {
    typeid ( B1_1211 ); // UndCC_Valid, B1 not polymorphic
  }
};
class B2_1211
{
public:
  virtual ~B2_1211 ( );
  virtual void foo_1211 ( );
  B2_1211 ( )
  {
    typeid ( B2_1211 ); // UndCC_Violation
    B2_1211::foo_1211 ( ); // UndCC_Valid � not a virtual call
    foo_1211 ( ); // UndCC_Violation
    dynamic_cast< B2_1211* > ( this ); // UndCC_Violation
  }
};
