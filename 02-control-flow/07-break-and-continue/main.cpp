#include <iostream>

// Score filter: continue skips negatives, break stops at the first score above 100.
int main()
{
    int x{};
    int sum{};
    int count{};
    int negatives{};
    int stoppedAt{0};
    bool stoppedEarly{false};   // records WHY the loop ended

    while (std::cin >> x) {
        if (x < 0) {            // guard at the top of the body
            ++negatives;
            continue;           // skip the rest of this run
        }
        if (x > 100) {
            stoppedEarly = true;
            stoppedAt = x;
            break;              // leave the loop
        }
        ++count;
        sum += x;
    }

    std::cout << "accepted:  " << count << " (sum " << sum << ")\n";
    std::cout << "negatives: " << negatives << " skipped\n";
    if (stoppedEarly) {
        std::cout << "stopped at " << stoppedAt << '\n';
    } else {
        std::cout << "reached the end\n";
    }
    return 0;

    // Traps shown in this lesson:
    // while (i < 5) { if (i == 2) { continue; } ++i; }   // continue skips ++i: hangs, no warning
    // for (...) { switch (i) { case 1: break; } }        // break leaves the SWITCH, not the loop
    // break; outside a loop or switch                    // error: break statement not within loop or switch
}