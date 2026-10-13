#include <iostream>

// A calculator for input like "8 * 2": number, operator, number.
int main()
{
    double a{};
    double b{};
    char op{};

    // Read in the same order as the input, and guard it: a failed read
    // otherwise leaves op empty and every result becomes "unknown operator".
    if (!(std::cin >> a >> op >> b)) {
        std::cerr << "invalid input\n";
        return 1;
    }

    switch (op) {          // char works: a char is an integer ('+' is 43)
    case '+':
        std::cout << a << " + " << b << " = " << a + b << '\n';
        break;
    case '-':
        std::cout << a << " - " << b << " = " << a - b << '\n';
        break;
    case 'x':              // stacked empty labels share code: no fall-through warning
    case 'X':
    case '*':
        std::cout << a << " * " << b << " = " << a * b << '\n';
        break;
    case '/':
        if (b == 0) {
            std::cerr << "division by zero\n";
            return 1;
        }
        std::cout << a << " / " << b << " = " << a / b << '\n';
        break;
    case '%': {            // braces: this case declares a variable
        // Guard the value actually used: for 8 % 0.5, b is not 0 but divisor is.
        const int divisor{static_cast<int>(b)};
        if (divisor == 0) {
            std::cerr << "division by zero\n";
            return 1;
        }
        std::cout << static_cast<int>(a) << " % " << divisor << " = "
                  << static_cast<int>(a) % divisor << '\n';
        break;
    }
    default:
        std::cerr << "unknown operator\n";
        return 1;
    }

    return 0;

    // Traps shown in this lesson:
    // case '+': ... (no break)      -> falls into the next case    [-Wimplicit-fallthrough]
    // case 6: [[fallthrough]]; ...  -> intentional, documented, no warning
    // case '/': const double r{a / b}; ... default:  -> error: jump to case label
    // switch (std::string{...})    -> error: switch quantity not an integer
}