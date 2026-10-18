#include <iostream>
#include <limits>

bool isPrime(int x)
{
    if (x < 2) {
        return false;
    }
    if (x == 2 || x == 3) {
        return true;
    }
    if (x % 2 == 0 || x % 3 == 0) {
        return false;
    }
    for (int i{5}; i <= x / i; i += 6) {   // FIX: i <= x / i cannot overflow
        if (x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    constexpr int maxAttempts{3};

    while (true) {
        std::cout << "1 Classify a number\n2 Calculator\n3 Primes in a range\n4 Quit\n";

        // FIX 1: the menu read has all three exits (valid, end of input, too many attempts)
        int choice{};
        bool valid{false};
        for (int attempt{1}; attempt <= maxAttempts; ++attempt) {
            std::cout << "Choice (1-4): ";
            if (std::cin >> choice) {
                if (std::cin.peek() != '\n' && std::cin.peek() != std::char_traits<char>::eof()) {
                    std::cout << "trailing characters\n";
                } else if (choice >= 1 && choice <= 4) {
                    valid = true;
                    break;
                } else {
                    std::cout << "out of range\n";      // FIX: retries go to std::cout
                }
            } else {
                if (std::cin.eof()) {
                    std::cerr << "no more input\n";
                    return 1;
                }
                std::cout << "not a number\n";
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (!valid) {
            std::cerr << "too many invalid attempts\n";
            return 1;
        }

        switch (choice) {
        case 1: {
            // FIX 2: validated read; a failed read never classifies 0
            int number{};
            valid = false;
            for (int attempt{1}; attempt <= maxAttempts; ++attempt) {
                std::cout << "Number: ";
                if (std::cin >> number) {
                    if (std::cin.peek() != '\n' && std::cin.peek() != std::char_traits<char>::eof()) {
                        std::cout << "trailing characters\n";
                    } else {
                        valid = true;
                        break;
                    }
                } else {
                    if (std::cin.eof()) {
                        std::cerr << "no more input\n";
                        return 1;
                    }
                    std::cout << "not a number\n";
                    std::cin.clear();
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if (!valid) {
                std::cerr << "too many invalid attempts\n";
                return 1;
            }

            // FIX 6: spec output format
            if (number > 0) {
                std::cout << "sign: positive\n";
            } else if (number < 0) {
                std::cout << "sign: negative\n";
            } else {
                std::cout << "sign: zero\n";
            }
            std::cout << "parity: " << ((number % 2 == 0) ? "even" : "odd") << '\n';

            // FIX 3: do while counts 1 digit for 0, and works for negatives (/ truncates toward 0)
            int digits{};
            int rest{number};
            do {
                ++digits;
                rest /= 10;
            } while (rest != 0);
            std::cout << "digits: " << digits << '\n';

            std::cout << "prime: " << (isPrime(number) ? "yes" : "no") << '\n';
            break;
        }
        case 2: {
            // FIX 5: double, read as "a op b" in one line
            double a{};
            double b{};
            char op{};
            valid = false;
            for (int attempt{1}; attempt <= maxAttempts; ++attempt) {
                std::cout << "Expression (a op b): ";
                if (std::cin >> a >> op >> b) {
                    if (std::cin.peek() != '\n' && std::cin.peek() != std::char_traits<char>::eof()) {
                        std::cout << "trailing characters\n";
                    } else {
                        valid = true;
                        break;
                    }
                } else {
                    if (std::cin.eof()) {
                        std::cerr << "no more input\n";
                        return 1;
                    }
                    std::cout << "not a number\n";
                    std::cin.clear();
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if (!valid) {
                std::cerr << "too many invalid attempts\n";
                return 1;
            }

            switch (op) {
            case '+':
                std::cout << a << " + " << b << " = " << a + b << '\n';
                break;
            case '-':
                std::cout << a << " - " << b << " = " << a - b << '\n';
                break;
            case 'x':
            case 'X':
            case '*':
                std::cout << a << " * " << b << " = " << a * b << '\n';
                break;
            case '/':
                if (b == 0) {
                    std::cout << "division by zero\n";
                    break;
                }
                std::cout << a << " / " << b << " = " << a / b << '\n';
                break;
            case '%': {
                // Converting a double outside int's range to int is undefined behavior: guard first.
                constexpr double intMin{std::numeric_limits<int>::min()};
                constexpr double intMax{std::numeric_limits<int>::max()};
                if (a < intMin || a > intMax || b < intMin || b > intMax) {
                    std::cout << "out of range for %\n";
                    break;
                }
                const int divisor{static_cast<int>(b)};   // guard the value actually used
                if (divisor == 0) {
                    std::cout << "division by zero\n";
                    break;
                }
                const int dividend{static_cast<int>(a)};
                // INT_MIN % -1 overflows (undefined behavior); any x % -1 is 0 anyway.
                const int result{(divisor == -1) ? 0 : dividend % divisor};
                std::cout << dividend << " % " << divisor << " = " << result << '\n';
                break;
            }
            default:
                std::cout << "unknown operator\n";
                break;
            }
            break;
        }
        case 3: {
            // FIX 4: an invalid range is a retry, not "print and run anyway"
            int low{};
            int high{};
            valid = false;
            for (int attempt{1}; attempt <= maxAttempts; ++attempt) {
                std::cout << "Range (low high): ";
                if (std::cin >> low >> high) {
                    if (std::cin.peek() != '\n' && std::cin.peek() != std::char_traits<char>::eof()) {
                        std::cout << "trailing characters\n";
                    } else if (low >= 2 && low <= high && high <= 10000) {
                        valid = true;
                        break;
                    } else {
                        std::cout << "out of range\n";
                    }
                } else {
                    if (std::cin.eof()) {
                        std::cerr << "no more input\n";
                        return 1;
                    }
                    std::cout << "not a number\n";
                    std::cin.clear();
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if (!valid) {
                std::cerr << "too many invalid attempts\n";
                return 1;
            }

            int count{};
            for (int i{low}; i <= high; ++i) {
                if (isPrime(i)) {
                    std::cout << i << ' ';
                    ++count;
                }
            }
            std::cout << "\ncount: " << count << '\n';
            break;
        }
        case 4:
            std::cout << "bye\n";
            return 0;                      // FIX 1: Quit leaves immediately
        default:
            break;                         // unreachable after validation
        }
    }
}