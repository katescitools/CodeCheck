#include "header.h"

{
typedef unsigned char uint8_t; /* Not compliant - redefinition */
}

void temp() {
	unsigned char uint8_t; /* Not compliant - reuse of uint8_t */ // UndCC_Violation
}

int uint8_t (){ /* Not compliant - reuse of uint8_t */ // UndCC_Violation
	return 4311;
}

int main() {
	return 1;
}
