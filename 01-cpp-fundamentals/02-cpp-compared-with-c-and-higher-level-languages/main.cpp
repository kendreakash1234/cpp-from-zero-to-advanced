// C++ compared with C and higher-level languages - Stage 01, Module 02
//
// Same task ("sum a list of numbers") written the idiomatic C++ way:
// high-level and safe (std::vector, range-based for), yet compiled and fast.
//
// Build (C++23 baseline):
//   g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main
//   ./main

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers{4, 7, 2, 9};   // manages its own memory (RAII)

    int sum = 0;
    for (int n : numbers)                    // high-level loop, no manual index
    {
        sum += n;
    }

    std::cout << "sum = " << sum << '\n';
    return 0;
}
