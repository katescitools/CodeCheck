#include <cstdint>

int main() {
	int32_t a;           // UNDCC_Valid
	int32_t b, *c;       // UNDCC_Violation
	int32_t *d, &e = b;  // UNDCC_Violation
	int32_t f, g;        // UNDCC_Violation
	f, g = 0;            // UNDCC_Valid
}
