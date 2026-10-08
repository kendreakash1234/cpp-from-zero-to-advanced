#include <iostream>
#include <limits>

int main()
{
    int value{-1};   // -1 shows whether a failed read touched the variable

    std::cout << "Enter a number: ";
    std::cin >> value;
    std::cout << std::boolalpha << "\nfirst read:  value = " << value
              << ", fail = " << std::cin.fail() << ", eof = " << std::cin.eof() << '\n';

    if (std::cin.fail()) {
        // clear() first: a failed stream skips every input operation, ignore() included.
        std::cin.clear();
        // Then discard the rest of the bad line.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Invalid input. Enter a number again: ";
        std::cin >> value;
        std::cout << "\nsecond read: value = " << value
                  << ", fail = " << std::cin.fail() << '\n';

        if (std::cin.fail()) {
            std::cerr << "Still invalid. Giving up.\n";
            return 1;
        }
    }

    std::cout << "Accepted: " << value << '\n';
    return 0;
}