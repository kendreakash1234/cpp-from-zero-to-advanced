#include <iostream>   // std::cout, std::cerr, std::cin  (the 3 streams)
#include <limits>     // std::numeric_limits — used to drain the input buffer

int main()
{
    int num1{}, num2{}, sum{};   // {} value-initializes all three to 0

    std::cout << "Enter two numbers: ";

    // std::cin >> num1 returns the stream; if the read fails the stream
    // tests as false, so !(...) becomes true and we enter the error branch.
    if (!(std::cin >> num1)) {
        std::cerr << "Expected a number\n";              // errors -> cerr channel
        std::cin.clear();                                // 1) reset the fail flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 2) drop the garbage
        return 1;                                        // non-zero = failure to the OS
    }

    if (!(std::cin >> num2)) {
        std::cerr << "Expected a number\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }

    sum = num1 + num2;

    std::cout << "Sum = " << sum << "\n";   // normal result -> cout channel
    return 0;
}