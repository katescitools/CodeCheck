class Base_712
{
public:
  virtual void myfunc_712( int * param1_712,         // param1: Addresses an object which is modified - Compliant
				 const int * param2_712,     // param2: Addresses an object which is not modified � Compliant
				 int * param3_712,            // UndCC_Violation
				 int * const param4_712)      // UndCC_Violation
  {
	*param1_712 = *param2_712 + *param3_712 + *param4_712;
    // Data at address param3 and param4 have not been changed
  }
};

class Derived_712 : public Base_712
{
public:
  void myfunc_712( int * param1_712,          // UndCC_Violation
				 const int * param2_712,     // param2: Addresses an object which is not modified � Compliant
				 int * param3_712,           // param3: Addresses an object which is not modified � Non-compliant
				 int * const param4_712)      // UndCC_Violation
  {
    *param3_712 = *param2_712 + *param1_712 + *param4_712;
    // Data at address param3 and param4 have not been changed
  }
};



