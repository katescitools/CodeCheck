#include <array>
#include <cstdint>
#include <iostream>


void Fn1() noexcept
{
  constexpr std::int32_t arraySize = 16;
  std::int32_t array[arraySize]{0};    /* UndCC_Violation initializing array size with identifier */

  std::int32_t elem1 =
    array[0];  /* UndCC_Valid */
  std::int32_t elem2 =
    array[12];  /* UndCC_Valid */
  for (std::int32_t idx = 0; idx < 20; ++idx)
  {
    std::int32_t elem3 =
      array[idx];  /* UndCC_Violation access beyond ArraySize */
  }

  std::int32_t shift = 25;
  std::int32_t elem4 =
    *(array + shift);
  
  std::int32_t index = 0;
  std::cin >> index;
  std::int32_t elem5 =
    array[index];    /* UndCC_Violation index may exceed the ArraySize bounds */
  if (index < arraySize)
  {
    std::int32_t elem6 = array[index];  /* UndCC_Violation index may exceed the ArraySize bounds */
  }
}

void Fn2() noexcept
{
  constexpr std::int32_t arraySize = 32;
  std::array<std::int32_t, arraySize> array;
  array.fill(0);

  std::int32_t elem1 =
    array[10];  /* UndCC_Valid */
  std::int32_t index = 40;
  std::int32_t elem2 =
    array[index];
  try
  {
    std::int32_t elem3 =
      array.at(50);  /* UndCC_Valid */
  }
  catch (std::out_of_range&)
  {
    // Handle an error
  }
  for (auto&& e : array)  // The std::array provides a possibility to iterate over its elements with range-based loop
  {
    // Iterate over all elements
  }
}
