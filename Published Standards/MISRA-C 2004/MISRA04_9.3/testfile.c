enum colour { red=3, blue, green, yellow=5 };        /* UndCC_Violation */
   /* green and yellow represent the same value - this is duplication */
enum colour { red=3, blue=4, green=5, yellow=5 };        /* UndCC_Valid */
   /* green and yellow represent the same value - this is duplication */

enum invalidInit {
	TEST0,
	TEST1,
	TESTbig0 = 1000, // UndCC_Violation
	TESTbig1,
};

enum validInit {
	FIRST = 10000,
	SECOND,
	THIRD,
	FOURTH,
	FIFTH,
};

enum validRegular { a, b, c, d, e, f };
