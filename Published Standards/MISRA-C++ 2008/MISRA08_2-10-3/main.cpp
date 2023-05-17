#include "posix_typedefs.h"
#include "header.h"

class bar {
	private:
		int WIDTH;
		int HEIGHT;
	public:
		int foobar();
		void bar(int w, int h);
};

namespace NS1
{
	typedef int16_t WIDTH;
}

void f1 ( ) {
	typedef int32_t TYPE;
}
void f2 ( ) {
	float32_t TYPE; // UndCC_Violation
}

{
	typedef unsigned char uint8_t; /* Not compliant - redefinition */
}

void temp() {
	unsigned char uint8_t;  // UndCC_Violation
}

int uint8_t () {  // UndCC_Violation
	return 4311;
}

int main() {
	int WIDTH;  // UndCC_Violation
	WIDTH = 1;
	return WIDTH;
}
