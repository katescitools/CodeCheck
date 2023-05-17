#include <new>
#include <stdexcept>

void *operator new(std::size_t count, const std::nothrow_t &tag)
{
    int a = 5;
    int b = -5;
    if ( a < 0 || b < 0 ) {
        throw std::invalid_argument( "received negative value" ); // UndCC_Violation
    }
}
