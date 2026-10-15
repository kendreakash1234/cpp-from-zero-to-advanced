#include <iostream>
#include <vector>

int main()
{
    // Guards: input first, then range. "Invalid" is the opposite of
    // (n >= 1 && n <= 12), so by De Morgan it uses ||, not &&.
    int n{};
    if (!(std::cin >> n)) {
        std::cerr << "invalid input\n";
        return 1;
    }
    if (n < 1 || n > 12) {
        std::cerr << "invalid input\n";
        return 1;
    }

    // Classic for: init; condition; update. x exists only inside the loop.
    for (int x{1}; x <= 10; ++x) {
        std::cout << n << " x " << x << " = " << n * x << '\n';
    }

    // One loop: sum, maximum, and its index. std::size_t matches size(): no sign-compare warning.
    const std::vector<int> scores{70, 85, 90, 65};
    int sum{};
    int maxValue{scores[0]};
    std::size_t maxIndex{0};
    for (std::size_t k{0}; k < scores.size(); ++k) {   // <, never <=
        sum += scores[k];
        if (scores[k] > maxValue) {
            maxValue = scores[k];
            maxIndex = k;
        }
    }
    std::cout << "sum " << sum << ", max " << maxValue << " at index " << maxIndex << '\n';

    // Safe backwards loop: start at size(), stop at 0, use k - 1.
    for (std::size_t k{scores.size()}; k > 0; --k) {
        std::cout << scores[k - 1] << ' ';
    }
    std::cout << '\n';

    return 0;

    // Traps shown in this lesson:
    // for (std::size_t k{0}; k <= scores.size(); ++k)   // reads scores[4]: printed 0 silently,
    //                                                   // cxxt aborts: Assertion '__n < this->size()'
    // for (std::size_t k{0}; k < scores.size() - 1; ++k) // skips the last element
    // for (int k{0}; k < scores.size(); ++k)            // [-Wsign-compare]
    // for (std::size_t k{scores.size() - 1}; k >= 0; --k) // never ends [-Wtype-limits]
    // for (double d{0.0}; d != 1.0; d += 0.1)           // never equals 1.0: count with int
}