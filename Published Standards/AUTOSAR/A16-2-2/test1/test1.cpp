
#include <stdio.h>
#include "usedindirect.hpp" // UndCC_Valid

#include "notused.hpp"      // UndCC_Violation
#include "used.hpp"         // UndCC_Valid


int main()
{
    int i = MACUSED;
    useindirect();
    used();
    printf("Coucou\n");
    return 1;
}
