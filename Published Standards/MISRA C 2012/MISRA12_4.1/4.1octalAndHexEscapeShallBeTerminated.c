const char *s1_41 = "\x41g"; 		/* UndCC_Violation */
const char *s2_41 = "\x41" "g"; 	/* UndCC_Valid - terminated by end of literal */
const char *s3_41 = "\x41\x67"; 	/* UndCC_Valid - terminated by another escape */
int c1_41 = '\141t'; 				/* UndCC_Violation */
c1_41 = '\141\t';					/* UndCC_Valid */
int c2_41 = '\141\t'; 				/* UndCC_Valid - terminated by another escape */

int main_41 () {
	
	c1_41 = '\xabc';				/* UndCC_Valid */
	return 0;
	
}
