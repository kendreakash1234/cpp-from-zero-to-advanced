#include <iostream>

int main()
{
    int number{};

    std::cout << "Enter an integer: ";

    if (!(std::cin >> number))
    {
        std::cerr << "Invalid input: expected an integer.\n";
        return 1;
    }

    // This decision directly follows the three branches in the pseudocode.
    if (number < 0)
    {
        std::cout << number << " is negative.\n";
    }
    else if (number > 0)
    {
        std::cout << number << " is positive.\n";
    }
    else
    {
        std::cout << "The number is zero.\n";
    }

    return 0;
}