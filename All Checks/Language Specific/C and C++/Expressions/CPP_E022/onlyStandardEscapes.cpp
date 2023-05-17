
int main() {
	/* good escapes */
	char * st = "\a \b \f \n \r \t \v \' \" \?  \xff \\";
	char end = '\0';
	/* bad escapes */
	char * x = "\012 \G"; // UndCC_Violation
	char * y = "\xll"; // UndCC_Violation
	char end = '\N'; // UndCC_Violation
	return 1;
}
