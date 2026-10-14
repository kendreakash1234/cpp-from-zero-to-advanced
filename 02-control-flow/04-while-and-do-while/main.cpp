#include <iostream>

// Running statistics with while, then a countdown with do while.
int main()
{
    int x{};
    int count{};
    int sum{};

    // while: checks BEFORE each run, so it can run zero times.
    // The read is the condition: the loop stops when a read fails
    // (end of input, or text such as "abc").
    while (std::cin >> x) {
        ++count;
        sum += x;
    }
    // The input is finished here: any further std::cin read would fail too.

    if (count == 0) {   // guard: no division by zero, and protects the do while below
        std::cout << "no numbers\n";
        return 0;
    }

    const double avg{static_cast<double>(sum) / count};
    std::cout << "count " << count << '\n';
    std::cout << "sum " << sum << '\n';
    std::cout << "avg " << avg << '\n';

    // do while: runs ONCE before checking, which is safe only because count >= 1 here.
    int n{count};
    do {
        std::cout << n << ' ';
        --n;
    } while (n >= 1);
    std::cout << '\n';

    return 0;

    // Traps shown in this lesson:
    // while (k < 3); { ++k; }       // the ; is the body: infinite loop   [-Wmisleading-indentation]
    // unsigned int u{3}; while (u >= 0) { --u; }   // always true: hangs  [-Wtype-limits]
    // do { ++k; } while (k < 3)     // missing ;  -> error: expected ';' before ...
    // while (k = 5) { ... }         // assignment: always true             [-Wparentheses]
}