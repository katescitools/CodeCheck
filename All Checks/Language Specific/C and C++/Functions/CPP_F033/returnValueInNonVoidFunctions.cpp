// $Id: A8-4-2.cpp 289436 2017-10-04 10:45:23Z michal.szczepankiewicz $
#include <cstdint>
#include <stdexcept>
std::int32_t F1() noexcept // UndCC_Violation
{
}

std::int32_t F2(std::int32_t x) noexcept(false)
{
  if (x > 100)
  {
    throw std::logic_error("Logic Error"); // UndCC_Valid by exception
  }
  return x; // UndCC_Valid
}

std::int32_t F3(std::int32_t x, std::int32_t y)
{
  if (x > 100 || y > 100)
  {
    throw std::logic_error("Logic Error"); // UndCC_Valid by exception
  }
  
  if (y > x)
  {
    //return (y - x); // UndCC_Valid
  }
  
  return (x - y); // UndCC_Valid
}

std::int32_t F4(std::int32_t x, std::int32_t y) // UndCC_Violation - no return/throw in
                                                // all 'if conditions' did not met exit path
{
  if (x > 100 || y > 100)
  {
    throw std::logic_error("Logic Error"); // UndCC_Valid by exception
  }
  
  if (y > x)
  {
    return (y - x); // UndCC_Valid
  }
}

std::int32_t F5(std::int32_t x, std::int32_t y) // UndCC_Valid all exit path covered
{
  if (x > 100 || y > 100)
  {
    throw std::logic_error("Logic Error"); // UndCC_Valid by exception
  }
  
  if (y > x)
  {
    throw std::logic_error("Logic Error"); // UndCC_Valid
  }
  return 1;
}

std::int32_t F6(std::int32_t x, std::int32_t y) // UndCC_Valid all exit path covered
{
  if (x > 100 || y > 100)
  {
    throw std::logic_error("Logic Error"); // UndCC_Valid by exception
  }
  
  if (y > x)
  {
    return (y - x); // UndCC_Valid
  }
	else
	{
		return 0;
	}
}
