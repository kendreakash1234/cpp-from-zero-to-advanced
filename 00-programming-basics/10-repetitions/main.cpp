#include <iostream>

// Repetition (while loop): compute the sum 1 + 2 + ... + n
int main()
{
    int num{};
    std::cout << "Enter a positive integer: ";

    // Validate that the input is an integer
    if (!(std::cin >> num))
    {
        std::cerr << "Invalid input: please enter an integer.\n";
        return 1;
    }

    // Validate that the integer is positive
    if (num <= 0)
    {
        std::cerr << "Please enter a positive integer.\n";
        return 1;
    }

    int sum{};
    int i{1};                 // initialization
    while (i <= num)          // condition: checked before each pass
    {
        sum += i;             // loop body
        i++;                  // update: moves toward the stop condition
    }

    std::cout << "Sum of 1 to " << num << " is " << sum << '\n';
    return 0;
}