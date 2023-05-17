class B
{
};

class D : public virtual B // UndCC_Violation
{
}; 

class E : public B
{
}; // UndCC_Valid