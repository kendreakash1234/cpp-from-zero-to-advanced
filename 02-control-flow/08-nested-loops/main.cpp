#include <iostream>
#include <vector>

int main()
{
    int n{};
    if (!(std::cin >> n)) {
        std::cerr << "invalid input\n";
        return 1;
    }
    if (n < 1 || n > 9) {
        std::cerr << "invalid input\n";
        return 1;
    }

    // n x n grid: the inner loop restarts for every row, so it runs n * n times.
    int gridRuns{};
    for (int row{1}; row <= n; ++row) {
        for (int col{1}; col <= n; ++col) {
            ++gridRuns;
            std::cout << row * col << '\t';
        }
        std::cout << '\n';
    }

    // Triangle: the inner bound depends on the outer counter: 1 + 2 + ... + n runs.
    int triangleRuns{};
    for (int row{1}; row <= n; ++row) {
        for (int star{1}; star <= row; ++star) {
            ++triangleRuns;
            std::cout << "* ";
        }
        std::cout << '\n';
    }
    std::cout << "grid runs: " << gridRuns << ", triangle runs: " << triangleRuns << '\n';

    // First pair summing to the target. j starts at i + 1: no self-pairs, no duplicates.
    // break leaves only the inner loop; the found flag stops the outer loop too.
    const int target{10};
    const std::vector<int> v{3, 7, 1, 6, 4};
    bool found{false};
    int checks{};
    for (std::size_t i{0}; i < v.size() && !found; ++i) {
        for (std::size_t j{i + 1}; j < v.size(); ++j) {
            ++checks;
            if (v[i] + v[j] == target) {
                std::cout << "found: v[" << i << "] + v[" << j << "] = "
                          << v[i] << " + " << v[j] << '\n';
                found = true;
                break;
            }
        }
    }
    std::cout << "pairs checked: " << checks << '\n';

    return 0;

    // Traps shown in this lesson:
    // for (int j{0}; j < 3; ++i)          // inner loop updates i: j never changes, hangs, no warning
    // for (int i...) { for (int i...) }   // shadows the outer i  [-Wshadow=compatible-local]
    // outer condition without && !found   // 7 checks, and both pairs (3+7, 6+4) reported
}