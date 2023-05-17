#include <vector>


// Function try blocks

void fn0() try
{

}
catch (...)
{

}

void fn1() try
{
  return;
}
catch (...)
{
  return;
}

void fn2() try
{
  return;
}
catch (...)
{
  if (1)
    return;  // UndCC_Violation - early return
  return;
}


// Return objects with { }

std::vector<int> fn3()
{
  return { 0, 1 };
}

std::vector<int> fn4()
{
  if (1)
    return { 1 };  // UndCC_Violation - early return
  return { 0 };
}


// Lambdas

int fn5()
{
  return []() {
    return 1;
  }();
}

int fn6()
{
  if (1)
    return []() {  // UndCC_Violation - early return
      return 1;
    }();

  return []() {
    return 0;
  }();
}

int fn7()
{
  return []() {
    if (1)
      return 1;  // UndCC_Violation - early return
    return 0;
  }();
}


// Position of one return

void fn8()
{
  if (1)
    return;  // UndCC_Violation - early return
}

void fn9()
{
  while (1)
    return;  // UndCC_Violation - early return
}

void fn10()
{
  for (;;)
    return;  // UndCC_Violation - early return
}

void fn11()
{
  do
    return;  // UndCC_Violation - early return
  while (1);
}

void fn12()
{
  int x = 0;
  switch (x)
    return;  // UndCC_Violation - early return
}

void fn13()
{
  int x = 0;
  switch (x) {
    case 0:
      return;  // UndCC_Violation - early return
  }
}

void fn14()
{
  int x = 0;
  switch (x) {
    default:
      return;  // UndCC_Violation - early return
  }
}

void fn15()
{
  try {
    return;  // UndCC_Violation - early return
  } catch (...) {

  }
}

void fn16(std::vector<int> nums = {})
{
  try {

  } catch (...) {
    return;  // UndCC_Violation - early return
  }
}

void fn17()
{
  return;  // UndCC_Violation - early return
  fn14();
}

void fn18()
{
  return;
  // Comment
}
