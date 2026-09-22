# 07 - Namespaces and std::

## Definition
A namespace is a named region that groups identifiers so names in different
libraries don't collide. `std` is the C++ Standard Library's namespace; `::`
(scope resolution) reaches inside it, e.g. `std::cout`.

## Why it matters
Large programs mix your code, the Standard Library, and third-party code.
Namespaces let each keep its own names (your `count` vs `std::count`).

## Syntax
    namespace mylib { int value = 42; }   // define
    mylib::value;                         // qualified access with ::
    using std::cout;                      // using-declaration: ONE name
    using namespace std;                  // using-directive: ALL names (risky)

## Example
See `main.cpp`. `geometry::area` and two same-named `length()` functions in
`metric` and `imperial` show why qualification matters.

    g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main

## Under the hood
Namespaces are compile-time only (zero runtime cost). The compiler encodes the
namespace into the linker symbol (name mangling), so metric::length and
imperial::length are distinct symbols.

## Common mistakes
- Confusing `std` (a namespace) with `<iostream>` (a header).
- `using namespace std;` in a header - forces all std names into every file.
- Two using-declarations of the same name -> ambiguous call (compiler error).

## Key takeaway
`std` is a namespace, not a header. `::` selects a name inside a namespace.
Prefer explicit `std::`; use narrow using-declarations only when helpful.

## Standard and compiler command
C++23:

    g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main