#include <cstdint>
#include <iostream>
void f ( int32_t k )
{
    int32_t j = k * k; // UndCC_Violation
    {
        int32_t i = j; // UndCC_Valid
        std::cout << i << j << std::endl;
    }
}
