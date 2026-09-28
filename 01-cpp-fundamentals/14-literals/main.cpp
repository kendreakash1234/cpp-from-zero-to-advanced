#include <iostream>

int main()
{
    // One value, four notations: all print 255.
    std::cout << "decimal 255:        " << 255 << '\n';
    std::cout << "hex 0xFF:           " << 0xFF << '\n';
    std::cout << "octal 0377:         " << 0377 << '\n';
    std::cout << "binary 0b11111111:  " << 0b11111111 << '\n';
    std::cout << "separated 1'000'000: " << 1'000'000 << '\n';

    // Every literal has a type; sizeof reveals its size.
    std::cout << "sizeof(42):         " << sizeof(42) << '\n';          // int
    std::cout << "sizeof(42U):        " << sizeof(42U) << '\n';         // unsigned int
    std::cout << "sizeof(42L):        " << sizeof(42L) << '\n';         // long
    std::cout << "sizeof(42LL):       " << sizeof(42LL) << '\n';        // long long
    std::cout << "sizeof(42uz):       " << sizeof(42uz) << '\n';        // std::size_t (C++23)
    std::cout << "sizeof(3000000000): " << sizeof(3000000000) << '\n';  // long: too big for int
    std::cout << "sizeof(0.1f):       " << sizeof(0.1f) << '\n';        // float
    std::cout << "sizeof(0.1):        " << sizeof(0.1) << '\n';         // double
    std::cout << "sizeof(0.1L):       " << sizeof(0.1L) << '\n';        // long double
    std::cout << "sizeof('A'):        " << sizeof('A') << '\n';         // char
    std::cout << "sizeof(\"hi\"):       " << sizeof("hi") << '\n';      // 'h', 'i', '\0'

    // Escape sequences: tab, double quote, backslash.
    std::cout << "tab[\t] quote[\"] backslash[\\]" << '\n';

    // The path trap and two fixes.
    std::cout << "C:\\new\\table" << '\n';
    std::cout << "C:/new/table" << '\n';

    // Traps shown in this lesson (uncomment to see the result):
    // int code{010};              // 8, not 10: a leading 0 means octal
    // int big{3000000000};        // error: the literal is a long
    // char letter{"A"};           // error: "A" is a string, not a char
    // std::cout << "C:\new\table"; // prints a newline and a tab

    return 0;
}