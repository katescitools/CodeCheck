// $Id: A10-3-2.cpp 289436 2017-10-04 10:45:23Z michal.szczepankiewicz $
class A
{
  public:
    virtual ~A() {}
    virtual void F() noexcept = 0;
    virtual void G() noexcept {}
    virtual void Z() noexcept {}
    virtual A& operator+=(A const& oth) = 0;
    virtual void V() noexcept = 0;
};

class B : public A
{
  public:
    ~B() override {} // UndCC_Valid
    void F() noexcept // UndCC_Violation
    {
    }
    virtual void G() noexcept // UndCC_Violation
    {
    }
    void Z() noexcept override // UndCC_Valid
    {
    }
    B& operator+=(A const& oth) override // UndCC_Valid
    {
      return *this;
    }
    void V() noexcept // UndCC_Violation
    {
    }
};

class C : public A
{
  public:
    ~C() {} // UndCC_Violation
    void F() noexcept override // UndCC_Valid
    {
    }
    void G() noexcept override // UndCC_Valid
    {
    }
    void Z() noexcept override // UndCC_Valid
    {
    }
    C& operator+=(A const& oth) // UndCC_Violation
    {
      return *this;
    }
    void V() noexcept final // UndCC_Valid
    {
    }
};
