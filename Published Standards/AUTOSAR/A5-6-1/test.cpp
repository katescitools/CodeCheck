// $Id: A5-6-1.cpp 305629 2018-01-29 13:29:25Z piotr.serwa $
#include <cstdint>
#include <stdexcept>
std::int32_t Division1(std::int32_t a, std::int32_t b) noexcept
{
    return (a / b);
}

std::int32_t Division2(std::int32_t a, std::int32_t b)
{
  if (b == 0) {
    throw std::runtime_error("Division by zero error");
  }
  return (a / b);  // UndCC_Valid - value of b checked before division
}

double Fn()
{
  std::int32_t x = 20 / 0;  /* UndCC_Violation undefined behavior */
  x = Division1(20, 0);
  x = Division2(20,
                0);
  std::int32_t remainder = 20 % 0;  /* UndCC_Violation undefined behavior */
}
