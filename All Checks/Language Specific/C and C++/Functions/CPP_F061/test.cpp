#include <bits/stdc++.h>
using namespace std;
class Student
{
    public:
    string name;
  
    printname() // UndCC_Violation
    {
       cout << "Student's name is: " << name;
    }
};
  
int main() {
  
    Student obj1;
  
    obj1.name = "John";
  
    obj1.printname();
    return 0;
}
