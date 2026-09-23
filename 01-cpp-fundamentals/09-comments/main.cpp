#include <iostream>   // std::cout / std::cin  (I/O streams)
#include <limits>     // std::numeric_limits — used to drain the input buffer

// Reads one integer and echoes it, rejecting non-numeric input.
int main()
{
    /* Plan:
       1. read an int
       2. if the read fails, report + recover
       3. print the value
       (Comments explain WHY/intent — the code shows the WHAT.) */

    int num{};                       // {} value-initializes to 0

    std::cout << "Enter the number: ";

    // Read as int so non-numeric input is rejected here, not later.
    if (!(std::cin >> num)) {
        std::cerr << "Invalid input: expected integer\n";        // errors -> cerr
        std::cin.clear();                                        // reset fail flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // drop garbage
    }

    std::cout << "number: " << num << '\n';
    return 0;
}