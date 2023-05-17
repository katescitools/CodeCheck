// $Id: A5-1-4.cpp 289436 2017-10-04 10:45:23Z michal.szczepankiewicz $
#include <cstdint>
#include <functional>

std::function<int()> F()
{
  
  int a = 1000; // UndCC_Violation
  return ([&a]() -> int {
    
    a = 10;
    return a;
    
  }); 
}
