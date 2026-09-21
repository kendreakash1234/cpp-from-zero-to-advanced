# 04 - First C++ Program

## Definition
The smallest complete C++ program that compiles, links, runs, and produces
console output. It is the reduced form of every C++ program: one entry point,
one return-to-OS contract, output through the Standard Library.

## Why it matters
It separates your *environment* from your *logic*. If this runs, your compiler,
linker, headers, and Standard Library are correctly set up — so later failures
are about your code, not your setup.

## How it runs (pipeline)
| Stage        | What happens                                                        |
|--------------|---------------------------------------------------------------------|
| Preprocess   | `#include` pastes header *declarations* into one translation unit.  |
| Compile      | Source is checked and turned into object code (library calls unresolved). |
| Link         | Your object code is joined to the Standard Library's compiled I/O.  |
| Run          | The OS loads the exe, startup code runs, then calls `main()`.       |

## Structure
- `#include <iostream>` - brings stream I/O names (declared in namespace `std`).
- `int main()` - entry point; returns an `int` exit status.
- `std::cout << ...` - inserts text into standard output; `\n` is one newline.
- `return 0;` - reports success to the OS.

## Example
See `main.cpp`. Multiple lines are produced by chaining `<<` and using `\n`.

## Common mistakes
- Using `std::cout` without `#include <iostream>`.
- Writing `cout` without the `std::` qualifier.
- Missing the `;` statement terminator.
- Using non-standard `void main()` instead of `int main()`.
- Thinking `std` lives "inside iostream" - `std` is the namespace; `<iostream>`
  is just one header that adds names into it.

## Key takeaway
`main` is the entry point, `std` is the Standard Library's namespace, and
`std::cout << ...` streams output to the console.

## Standard and compiler command
C++23:

    g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main