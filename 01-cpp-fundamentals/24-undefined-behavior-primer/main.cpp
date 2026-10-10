#include <iostream>
#include <limits>
#include <vector>

// The five Stage 01 UB red flags, each rewritten without undefined behavior.
int main()
{
    // 1. Uninitialized read -> initialize at the definition.
    const int count{};
    std::cout << "count:      " << count << '\n';                        // 0

    // 2. Signed overflow -> a type with enough range on EVERY platform.
    //    long is 4 bytes on 64-bit Windows, so use long long, not long.
    const long long big{2147483647};
    std::cout << "big + 1:    " << big + 1 << '\n';                      // 2147483648

    // 3. Division by zero -> guard before dividing (topic 18's short-circuit idea).
    int divisor{0};   // not const: in real code this would come from input
    if (divisor != 0) {
        std::cout << "10 / divisor: " << 10 / divisor << '\n';
    } else {
        std::cout << "10 / divisor: refused, divisor is 0\n";
    }

    // 4. Out-of-range double -> int -> check the range before converting.
    const double huge{1e20};
    if (huge >= std::numeric_limits<int>::lowest() && huge <= std::numeric_limits<int>::max()) {
        std::cout << "huge as int: " << static_cast<int>(huge) << '\n';
    } else {
        std::cout << "huge as int: refused, " << huge << " does not fit int\n";
    }

    // 5. Out-of-bounds [] -> use a valid index; .at() reports a bad one.
    const std::vector<int> values{1, 2, 3};
    std::cout << "last value: " << values.at(values.size() - 1) << '\n';  // 3

    // The folded-overflow surprise (needs input, so shown as a comment):
    //   int x{}; std::cin >> x;          // enter 2147483647
    //   x + 1 > x                        // true: the compiler assumed no overflow and folded it,
    //                                    //       so UBSan had no addition left to check
    //   const int next{x + 1}; next > x  // false: next wrapped to -2147483648; UBSan reports it

    return 0;
}