void F8(); // UndCC_Valid - functions called in try statements ignored
void F9(); // UndCC_Violation - missing noexcept
void F10() // UndCC_Valid - directly throws
{
    throw;
}

void F11() // UndCC_Valid - indirectly throws
{
    try
    {
        F8();
    }
    catch (...)
    {

    }
    F9();
    F10();
}

class C3
{
    public:
        C3()  // UndCC_Valid - constructors ignored
        {
        }

        ~C3() // UndCC_Valid - constructors ignored
        {
        }
};
