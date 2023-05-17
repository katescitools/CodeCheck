#include <cstdint>

struct S1
{
	int32_t i;
};
struct S2
{
	int32_t i;
};

typedef int16_t i16;
typedef int32_t i32;

inline int32_t f(int32_t x) {
	return x * 2;
}
int32_t g(int32_t x) {
	return x + 2;
}
inline int32_t h(int32_t x) {
	return x + 4;
}
