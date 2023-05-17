// library.cpp
void func() noexcept(false)
{
    // ...
    if (true)
    {
        throw 42;
    }
}