#include <iostream>

// Definitions come before main: a function must be declared before it is called.

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
    for (int i{5}; i <= x / i; i += 6) { // i <= x / i cannot overflow; i * i <= x can
        if (x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int countDigits(int x)
{
    int digits{};
    int rest{x};
    do { // runs at least once: 0 has 1 digit; / truncates toward 0, so negatives work
        ++digits;
        rest /= 10;
    } while (rest != 0);
    return digits;
}

int sign(int x)
{
    // Every path returns a value. Falling off the end of a non-void function is
    // undefined behavior: with GCC it crashed with "Illegal instruction".
    if (x > 0) {
        return 1;
    }
    if (x < 0) {
        return -1;
    }
    return 0;
}

int main()
{
    for (int value : {0, 1, 2, 97, 121, -45, 2147483647}) {
        std::cout << value << ": prime " << std::boolalpha << isPrime(value) << ", digits "
                  << countDigits(value) << ", sign " << sign(value) << '\n';
    }
    return 0;
}