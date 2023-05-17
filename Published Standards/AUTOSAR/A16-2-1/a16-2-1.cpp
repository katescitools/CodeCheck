// $Id: A16-2-1.cpp 271687 2017-03-23 08:57:35Z piotr.tanski $

#include <directory/headerfile.hpp> // UndCC_Valid
#include <headerfile.hpp>           // UndCC_Valid
#include "directory/headerfile.hpp" // UndCC_Valid
#include "headerfile.hpp"           // UndCC_Valid
#include <directory/*.hpp> // UndCC_Violation
#include <header'file.hpp> // UndCC_Violation
#include <"headerfile.hpp"> // UndCC_Violation
#include <directory\\headerfile.hpp> // UndCC_Violation
