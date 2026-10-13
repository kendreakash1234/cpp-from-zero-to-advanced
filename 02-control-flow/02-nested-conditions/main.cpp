#include <iostream>

// Event entry checker written with guard clauses:
// each bad case is checked first and leaves immediately, so the main path is flat.
int main()
{
    int age{};
    bool hasTicket{};   // >> into a bool accepts only 0 or 1; "2" makes the read fail

    // Guard 1: input. Nothing below is meaningful if the read failed.
    if (!(std::cin >> age >> hasTicket)) {
        std::cerr << "invalid input\n";
        return 1;
    }

    // Guard 2: range.
    if (age < 0) {
        std::cerr << "invalid input\n";
        return 1;
    }

    // Guards 3 and 4: business rules. Each one returns: a guard that doesn't
    // return falls through to the next lines.
    if (age < 18) {
        std::cout << "too young\n";
        return 0;
    }
    if (!hasTicket) {
        std::cout << "no ticket\n";
        return 0;
    }

    // Main path: every precondition already holds.
    std::cout << "allowed\n";
    return 0;

    // Traps shown in this lesson:
    // if (age >= 18 && hasTicket) { allowed } else { "too young" }
    //     merges two failures: 25 0 printed "too young" instead of "no ticket".
    // The opposite of (age >= 18 && hasTicket) is (age < 18 || !hasTicket):
    //     De Morgan turns && into ||. Not (age <= 18 ...): >= inverts to <.
}