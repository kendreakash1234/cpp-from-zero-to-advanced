# 06 - #include

## Definition
`#include` is a preprocessor directive that pastes the entire contents of
another file in place of the directive line, before compilation.

## Why it matters
C++ compiles each .cpp independently. To use a name defined elsewhere, its
declaration must be visible in this file - `#include` makes it visible.

## Syntax
    #include <header>     // angle brackets: search system paths only
    #include "myfile.h"   // quotes: search project first, then system

## Example
See `main.cpp` and `program.h`. The header declares `add`; the source defines
and calls it. Build:

    g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main

## Under the hood
`#include` runs at the preprocessing stage. See the expansion with:

    g++ -E main.cpp | wc -l

A ~15-line program expands to tens of thousands of lines, because <iostream>
transitively includes many other headers.

## Common mistakes
- Adding a `;` after the directive (it is not a statement).
- Using <...> for your own headers instead of "...".
- Missing an include guard (`#pragma once`) in a header.
- Putting definitions (not just declarations) in a header -> linker errors.

## Key takeaway
`#include` only makes declarations visible (compile time). The linker attaches
the actual definitions later. Missing declaration -> compiler error; missing
definition -> linker error.

## Standard and compiler command
C++23:

    g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main