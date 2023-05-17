int a;

void func1(void)
{
	float a;	/* different from global `a' */ // UndCC_Violation
	float local;
	a = 0.0;	/* sets `a' declared in this block to 0.0 */
			/* global `a' is untouched */
	{
		int a;	/* new `a' variable */ // UndCC_Violation

		a = 2;	/* outer `a' is still set to 0.0 */
		int b;
	}
	float b;
	b = a;		/* sets `b' to 0.0 */
}

/* global 'a' is untouched by anything done in f() */

void func2(int a){ // UndCC_Violation
	float local;
	local = 4;
}
