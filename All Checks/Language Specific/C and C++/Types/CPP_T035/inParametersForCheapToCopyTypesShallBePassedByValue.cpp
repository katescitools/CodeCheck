// $Id: A8-4-7.cpp 305588 2018-01-29 11:07:35Z michal.szczepankiewicz $

#include <cstdint>
#include <iostream>
#include <string>

// UNDCC_Valid - pass by value
void output(std::uint32_t i)
{
    std::cout << i << '\n';
}


void output(std::string s) // UndCC_Violation
{
    std::cout << s << '\n';
}

struct A
{
    std::uint32_t v1;
    std::uint32_t v2;
};


void output(const A &a) // UndCC_Violation
{
    std::cout << a.v1 << ", " << a.v2 << '\n';
}


void output(std::uint32_t &i) // UndCC_Violation
{
    std::cout << i << '\n';
}
