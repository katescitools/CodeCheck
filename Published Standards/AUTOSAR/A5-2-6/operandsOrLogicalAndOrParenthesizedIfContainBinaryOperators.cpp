// $Id: A5-2-6.cpp$

#include <cstdint>

void Fn(std::int32_t value) noexcept
{
    if (value > 0 && value < 3) // UndCC_Violation
    {
        // do some work
    }
    else if ((value > 1) && (value < 2)) // UndCC_Valid
    {
        // do some work
    }
    else if (value > 1 || (value < 2)) // UndCC_Violation
    {
      // do some work
    }
    else if ((value > 1) || value < 2) // UndCC_Violation
    {
      // do some work
    }
    else
    {
        // do some work
    }

    return;
}
