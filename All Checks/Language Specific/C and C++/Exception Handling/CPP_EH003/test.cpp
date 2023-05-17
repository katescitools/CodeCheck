/* Example from https://help.semmle.com/wiki/display/CCPPOBJ/Exception+thrown+in+destructor */
#include <iostream>

class C {
  public:
  //...
  ~C(){ // UndCC_Violation
    if (error) {
      throw "Exception in destructor"; //wrong: exception thrown in destructor
    }
  }
};

void f() {
  C* c = new C();
  try {
    doOperation(c);
    delete c;
  } catch ( char * do_operation_exception) {
    delete c; //would immediately terminate program if C::~C throws an exception
  }
}
