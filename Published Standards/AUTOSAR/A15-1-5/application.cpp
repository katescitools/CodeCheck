// application.cpp
#include "library.h"

void f()
{
    try
    {
        func();   // UNDCC_Violation
    }
    catch (int &e)
    {
        // Handle error
    }
}
