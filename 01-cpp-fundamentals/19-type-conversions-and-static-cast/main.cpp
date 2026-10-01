#include <iostream>

int main()
{
    // Cast an operand, not the result, to avoid integer division.
    const int sum{7 + 8 + 10};
    const int count{3};
    std::cout << "sum / count:                     " << sum / count << '\n';                          // 8
    std::cout << "static_cast<double>(sum / count): " << static_cast<double>(sum / count) << '\n';    // 8: too late
    std::cout << "static_cast<double>(sum) / count: " << static_cast<double>(sum) / count << '\n';    // 8.33333

    // Floating-point to integer truncates toward zero.
    std::cout << "static_cast<int>(9.99):  " << static_cast<int>(9.99) << '\n';    // 9
    std::cout << "static_cast<int>(-9.99): " << static_cast<int>(-9.99) << '\n';   // -9
    std::cout << "static_cast<int>(0.5):   " << static_cast<int>(0.5) << '\n';     // 0

    // Integer promotion: char arithmetic produces an int.
    std::cout << "'a' + 1:                   " << 'a' + 1 << '\n';                     // 98
    std::cout << "static_cast<char>('a' + 1): " << static_cast<char>('a' + 1) << '\n'; // b
    std::cout << "sizeof('a' + 1):           " << sizeof('a' + 1) << '\n';             // 4

    // Signed vs unsigned: guard the negative case first, then convert safely.
    const int index{-1};
    const unsigned int size{5};
    std::cout << std::boolalpha;
    std::cout << "fixed index < size: "
              << (index < 0 || static_cast<unsigned int>(index) < size) << '\n';     // true

    // Traps shown in this lesson (uncomment to see the result):
    // std::cout << (index < size);           // false, warning: -Wsign-compare
    // int n = (int)3.7;                      // warning with -Wold-style-cast
    // double big{3e10};
    // int bad{static_cast<int>(big)};        // UB: needs -fsanitize=float-cast-overflow

    return 0;
}