#include <iostream>
#include <limits>

int main()
{
    // Arithmetic: the operands' types decide the calculation.
    std::cout << "17 / 5    = " << 17 / 5 << '\n';     // 3: integer division
    std::cout << "17 % 5    = " << 17 % 5 << '\n';     // 2: remainder
    std::cout << "17.0 / 5  = " << 17.0 / 5 << '\n';   // 3.4: one double operand
    std::cout << "-17 / 5   = " << -17 / 5 << '\n';    // -3: truncates toward zero
    std::cout << "-17 % 5   = " << -17 % 5 << '\n';    // -2: sign of the left operand

    // Logical operators combine bool results.
    std::cout << std::boolalpha;
    std::cout << "10 > 3 && 2 > 5: " << (10 > 3 && 2 > 5) << '\n';
    std::cout << "10 > 3 || 2 > 5: " << (10 > 3 || 2 > 5) << '\n';
    std::cout << "!(10 > 3):       " << !(10 > 3) << '\n';

    // A range needs two comparisons: 1 < x < 3 does not do this.
    const int x{2};
    std::cout << "1 < x && x < 3:  " << (1 < x && x < 3) << '\n';

    // Overflow: long long has room for 2147483647 + 1.
    const long long big{2147483647};
    const long long result{big + 1};
    std::cout << "big + 1:         " << result << '\n';

    // Short-circuit guard: 10 / d runs only when d != 0.
    int d{};
    std::cout << "Enter d: ";
    if (!(std::cin >> d)) {
        std::cerr << "Invalid input: expected an integer\n";
        return 1;
    }
    std::cout << "d != 0 && 10 / d > 1: " << (d != 0 && 10 / d > 1) << '\n';

    // Traps shown in this lesson (uncomment to see the result):
    // int small{2147483647};
    // int wrapped{small + 1};          // UB: -fsanitize=undefined reports signed overflow
    // std::cout << (5 < x < 3);        // warning: always true
    // std::cout << (10 / d > 1 && d != 0);  // d == 0: division by zero, crash
    // std::cout << (0.1 + 0.2 == 0.3); // false: floating-point rounding

    return 0;
}