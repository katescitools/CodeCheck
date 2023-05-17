#include "posix_typedefs.h"

typedef bool boolean;
typedef boolean boolean_indirect;

typedef uint32_t uint32_indirect;

struct SomeStruct {
	int invalidField : 4; // UndCC_Violation
	signed int validSigned : 2;
	unsigned int validUnsigned: 1;
	char invalidChar : 2; // UndCC_Violation
	unsigned char invalidUnsignedChar : 2;
	signed char invalidSignedChar : 2;
	bool validBool : 1;
	boolean validBoolean : 1;
	boolean_indirect validIndirectBoolean : 1;
	uint32_t validUint32 : 8;
	char_t invalidChar : 3; // UndCC_Violation
	uint32_indirect validIndirectUint32 : 7;
};

struct S
{
     signed int    a : 2; // UndCC_Valid
   unsigned int    b : 2; // UndCC_Valid
             char  c : 2; // UndCC_Violation
     signed char   d : 2; // UndCC_Valid
   unsigned char   e : 2; // UndCC_Valid
             short f : 2; // UndCC_Violation
     signed short  g : 2; // UndCC_Valid
   unsigned short  h : 2; // UndCC_Valid
             int   i : 2; // UndCC_Violation
             bool  j : 2; // UndCC_Valid
          wchar_t  k : 2; // UndCC_Violation
         uint32_t  l : 2; // UndCC_Valid
           int8_t  m : 2; // UndCC_Valid
};
