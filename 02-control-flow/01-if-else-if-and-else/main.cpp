#include <iostream>

int main()
{
    int score{};
    std::cout << "Enter the score: ";
    if (!(std::cin >> score)) {
        std::cerr << "Expected an integer\n";
        return 1;
    }

    if (score < 0 || score > 100) {
        std::cerr << "out of range\n";
        return 1;
    }

    // First match wins: each else if already knows the earlier checks failed,
    // so no upper bounds are needed. Most restrictive condition first.
    if (score >= 90) {
        std::cout << "A\n";
    } else if (score >= 75) {
        std::cout << "B\n";
    } else if (score >= 50) {
        std::cout << "C\n";
    } else {
        std::cout << "F\n";
    }

    // if with an initializer (C++17): toPass exists only in this if/else.
    if (const int toPass{50 - score}; toPass > 0) {
        std::cout << toPass << " more points needed to pass\n";
    } else {
        std::cout << "passed with " << -toPass << " points to spare\n";
    }

    // Traps shown in this lesson (each compiles; cxx warns about the first three):
    // if (score = 5) { }            // assignment, always true      [-Wparentheses]
    // if (score > 10); { }          // the ; is the body            [-Wempty-body]
    // if (a > 0) if (b > 0) ... else ...   // else binds to the INNER if [-Wdangling-else]
    // if (score >= 50) ... else if (score >= 90) ...   // A is unreachable: no warning

    return 0;
}