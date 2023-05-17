#include <string>
void F()
{
    const std::string c = "\U0001f34c"; // UndCC_Valid
}

void \U0001f615() { // UndCC_Violation
    //
}
