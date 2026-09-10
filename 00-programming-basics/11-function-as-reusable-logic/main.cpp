#include <iostream>

// A function: named, reusable block of logic.

// Returns the sum of two integers.
int add(int a, int b) {
    return a + b;
}

// Returns true if n is even. A comparison already yields a bool.
bool isEven(int n) {
    return n % 2 == 0;
}

// Returns n! using a loop. Note: int overflows beyond 12!.
int factorial(int n) {
    int fact{1};
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

int main() {
    // --- add ---
    int num1{}, num2{};
    std::cout << "Enter the first number: ";
    if (!(std::cin >> num1)) {
        std::cerr << "Invalid input: not a number.\n";
        return 1;
    }
    std::cout << "Enter the second number: ";
    if (!(std::cin >> num2)) {
        std::cerr << "Invalid input: not a number.\n";
        return 1;
    }
    std::cout << "Sum of " << num1 << " and " << num2
              << " is " << add(num1, num2) << '\n';

    // --- isEven ---
    int even{};
    std::cout << "Enter a number to check even/odd: ";
    if (!(std::cin >> even)) {
        std::cerr << "Invalid input: not a number.\n";
        return 1;
    }
    if (isEven(even)) {
        std::cout << even << " is Even\n";
    } else {
        std::cout << even << " is Odd\n";
    }

    // --- factorial ---
    int n{};
    std::cout << "Enter a number to calculate factorial: ";
    if (!(std::cin >> n)) {
        std::cerr << "Invalid input: not a number.\n";
        return 1;
    }
    if (n < 0) {
        std::cerr << "Factorial is undefined for negative numbers.\n";
        return 1;
    }
    std::cout << "Factorial of " << n << " is " << factorial(n) << '\n';

    return 0;
}