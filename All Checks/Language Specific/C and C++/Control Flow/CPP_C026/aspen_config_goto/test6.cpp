#include <iostream>
#include <vector>

void test6 ()
{
  std::vector<int> v = {0, 1, 2, 3, 4, 5};

  for (const int& i : v) { // UndCC_Valid - 0 gotos
    if (i % 2 == 0)
      break;
    std::cout << i << '\n';
  }

  for (const int& i : v) { // UndCC_Valid - 0 gotos
    if (i % 2 == 0)
      break;
    if (i % 3 == 0)
      break;
    std::cout << i << '\n';
  }
}
