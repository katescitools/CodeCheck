// $Id: A5-10-1.cpp 289436 2017-10-04 10:45:23Z michal.szczepankiewicz $

class A
{
  public:
    virtual ~A() = default;
    void F1() noexcept {}
    void F2() noexcept {}
    virtual void F3() noexcept {}
};

void Fn()
{
  bool b1 = (&A::F1 == &A::F2);   // UndCC_Valid
  bool b2 = (&A::F1 == nullptr);  // UndCC_Valid
  bool b3 = (&A::F3 == nullptr);  // UndCC_Valid
  bool b4 = (&A::F3 != nullptr);  // UndCC_Valid
  bool b5 = (&A::F3 == &A::F1);   // UndCC_Violation
	bool b6 = (&A::F3 <= &A::F1);   // UndCC_Violation
	bool b7 = (nullptr == &A::F3);  // UndCC_Valid
}
