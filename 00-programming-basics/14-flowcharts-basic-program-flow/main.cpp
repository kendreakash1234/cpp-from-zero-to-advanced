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

    // PROCESS: Store the even/odd result in a bool.
    const bool isEven{number % 2 == 0};

    // DECISION: Select a path using the stored Boolean result.
    if (isEven)
    {
        std::cout << number << " is even.\n";
    }
    else
    {
        std::cout << number << " is odd.\n";
    }

    return 0;
}