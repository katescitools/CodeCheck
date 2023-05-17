#include <cstdint>

void foo()
{
    uint8_t a = -1U; // UndCC_Violation - a is assigned 255
    int32_t b = -a;  // UndCC_Violation - b is assigned -255
    uint32_t c = 1U;
    int64_t d = -c;  // UndCC_Violation - d is assigned MAX_UINT
}
