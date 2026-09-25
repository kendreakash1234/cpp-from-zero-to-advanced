#include <iostream>

int main()
{
    // sizeof(type) gives the size of a type in bytes, computed at compile time.
    std::cout << "bool:        " << sizeof(bool) << '\n';
    std::cout << "char:        " << sizeof(char) << '\n';
    std::cout << "short:       " << sizeof(short) << '\n';
    std::cout << "int:         " << sizeof(int) << '\n';
    std::cout << "long:        " << sizeof(long) << '\n';
    std::cout << "long long:   " << sizeof(long long) << '\n';
    std::cout << "float:       " << sizeof(float) << '\n';
    std::cout << "double:      " << sizeof(double) << '\n';
    std::cout << "long double: " << sizeof(long double) << '\n';

    // Same value, different types: the type decides how the value is printed.
    int number{65};
    char code{65};
    std::cout << "int 65 prints as:  " << number << '\n';
    std::cout << "char 65 prints as: " << code << '\n';

    // Traps shown in this lesson (uncomment to see the compiler's response):
    // void nothing;                      // error: an object cannot have type void
    // std::cout << sizeof int << '\n';   // error: a type name needs parentheses

    return 0;
}