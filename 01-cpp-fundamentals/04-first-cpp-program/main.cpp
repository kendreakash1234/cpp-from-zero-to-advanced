// 04 - First C++ Program
// The smallest complete program: it compiles, links, runs, and prints output.
// Build: g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main

#include <iostream>  // declares std::cout and the stream insertion operator <<

int main()  // program entry point; the runtime calls this; returns int to the OS
{
    // Exercise 11: one chained statement, my name then my goal.
    std::cout << "I am Akash\n"
              << "I want to conquer C++\n";

    // Challenge 12: three lines from a single chain of <<.
    std::cout << "I am working as a senior developer\n"
              << "I have started my journey this month and\n"
              << "in 6 months I will try to conquer it.\n";

    return 0;  // 0 = success reported back to the operating system
}