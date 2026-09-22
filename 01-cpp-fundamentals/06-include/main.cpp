#include <iostream>   // standard header: brings in std::cout
#include "program.h"  // project header: brings in the add() declaration

// Definition of the function declared in program.h.
int add(int a, int b)
{
    return a + b;
}

int main()
{
    std::cout << add(3, 4) << "\n";  // prints 7
    return 0;
}