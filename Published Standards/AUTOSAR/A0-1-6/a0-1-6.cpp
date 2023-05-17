#include <cstdint>

std::uint32_t Fn() noexcept
{
    using LocalUIntPtr = std::uint32_t *; // UndCC_Violation
    return 0U;
}

std::uint32_t Fn2() noexcept
{
    using LocalUIntPtr = std::uint32_t *; // UndCC_Valid
    LocalUIntPtr hey;
    return *hey;
}
