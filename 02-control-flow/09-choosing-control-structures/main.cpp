#include <iostream>

// The cleaned-up classifier. The original had six problems:
//   1. score < 0 && score > 100   -> impossible condition; should be ||   [-Wlogical-op]
//   2. score >= 50 checked first  -> the B and A branches were unreachable (no warning)
//   3. a second score >= 50 branch -> duplicated condition               [-Wduplicated-cond]
//   4. bonus = 10 in both branches -> identical branches                  [-Wduplicated-branches]
//   5. a statement after return    -> dead code (no warning)
//   6. two-value choice as an if/else -> clearer as the conditional operator
int main()
{
    int score{};
    if (!(std::cin >> score)) {
        std::cerr << "invalid input\n";
        return 1;
    }
    if (score < 0 || score > 100) {
        std::cerr << "out of range\n";
        return 1;
    }

    // Ranges: an if chain, most restrictive condition first.
    if (score >= 90) {
        std::cout << "A\n";
    } else if (score >= 75) {
        std::cout << "B\n";
    } else if (score >= 50) {
        std::cout << "C\n";
    } else {
        std::cout << "F\n";
    }

    // Choosing between two values: the conditional operator.
    const int bonus{(score == 100) ? 10 : 0};
    std::cout << "bonus " << bonus << '\n';

    // Parity: compare with 0. For -3, -3 % 2 is -1, so "== 1" would wrongly say even.
    std::cout << score << " is " << ((score % 2 == 0) ? "even" : "odd") << '\n';

    return 0;
}