#include <iostream>

class Dog {
    public:
        static void bark() {
            std::cout << "RARRRRR!!!";
        }
};

class Chihuahua: public Dog {
    public:
        static void bark() {
            std::cout << "waaa";
        }
};

extern void f ( void );

void g() {
    if ( 0 == f )                          // UNDCC_Violation
    {
        // ...
    }
    void (*p)( void ) = f;                 // UNDCC_Violation
    if ( 0 == &f )                         // UNDCC_Valid
    {
        (f)();                             // UNDCC_Valid as function is called
        f();                               // UNDCC_Valid as function is called
    }
    void (*p)( void ) = &f;                // UNDCC_Valid

    void (*p2)( void ) = Chihuahua::bark;  // UNDCC_Violation
    void (*p3)( void ) = &Chihuahua::bark; // UNDCC_Valid
    void (*p4)( void ) = (Dog::bark);      // UNDCC_Violation
    void (*p5)( void ) = &(Dog::bark);     // UNDCC_Valid

    Dog dog = Dog();                       // UNDCC_Valid

    taco(Dog::bark)                        // UNDCC_Violation
}
