// The C++ build pipeline - Stage 01, Module 03
//
// A tiny program used to walk through every build stage:
//   preprocessing -> compilation -> assembly -> linking -> executable
//
// See each stage yourself:
//   g++ -std=c++23 -E main.cpp -o main.i    // 1. preprocess only
//   g++ -std=c++23 -S main.cpp -o main.s    // 2. compile to assembly
//   g++ -std=c++23 -c main.cpp -o main.o    // 3. assemble to object file
//   g++ main.o -o app                       // 4. link into executable
//   g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main   // all at once

#include <iostream>

#define GREETING "Build pipeline: preprocess -> compile -> assemble -> link"

int main()
{
    // std::cout is declared in <iostream> (compiler) and its code lives in
    // the standard library (linker connects the call to that definition).
    std::cout << GREETING << '\n';
    return 0;
}
