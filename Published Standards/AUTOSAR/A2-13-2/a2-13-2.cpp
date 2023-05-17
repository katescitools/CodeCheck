//% $Id: A2-13-2.cpp 305629 2018-01-29 13:29:25Z piotr.serwa $

char16_t nArray[] =
u"Hello"
u"World"; // UndCC_Valid, "u" stands for char16_t type

char32_t nArray2[] =
U"Hello"
U"World"; // UndCC_Valid, "U" stands for char32_t type

wchar_t wArray[] =
L"Hello"
L"World"; // UndCC_Valid, "L" stands for wchar_t type - violates A2-13-3
// rule.

wchar_t mixed1[] =
"Hello"
L"World"; // UndCC_Valid

char32_t mixed2[] =
"Hello"
U"World"; // UndCC_Valid

char16_t mixed3[] =
"Hello"
u"World"; // UndCC_Valid

wchar_t mixed4[] = u"Hello" L"World"; // UndCC_Violation - compilation error

char32_t mixed5[] = u"Hello" U"World"; // UndCC_Violation - compilation error
