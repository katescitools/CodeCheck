#define A( x2011 ) #x2011 /* UndCC_Valid */
#define B( x2011, y2011 ) x2011 ## y2011 /* UndCC_Valid */
#define C( x2011, y2011 ) #x2011 ## y2011 /* UndCC_Violation */

#define B( x2011, y2011 ) x2011 \
## y2011 /* UndCC_Valid */

#define C( x2011, y2011 ) #x2011 \
## y2011 /* UndCC_Violation */
