// $Id: A8-4-9.cpp 306178 2018-02-01 15:52:25Z christof.meerwald $
#include <cstdint>
#include <numeric>
#include <string>
#include <vector>


int32_t Sum(std::vector<int32_t> &v) // UndCC_Violation
{
  return std::accumulate(v.begin(), v.end(), 0);
}

// UndCC_Valid: Modifying "in-out" parameter
void AppendNewline(std::string &s)
{
  s += '\n';
}


void GetFileExtension(std::string &ext) // UndCC_Violation
{
  ext = ".cpp";
}

// UndCC_Valid: Reading before replacing object
void SampleFunction(std::string &a)
{
  a += '\n';
  a = "hello";
}

// UndCC_Valid: not "in-out" parameter
void NotInOutFunction(std::string b)
{
  b = b * (-1);
}

// UndCC_Valid: Reading before replacing object
void FunctionReadThenSet(std::string &c)
{
  c += '\n';
  c += '\n';
  c = "hello";
}


void FunctionSetThenRead(std::string &d) // UndCC_Violation
{
  d = "hello";
  d += '\n';
  d += '\n';  
}
