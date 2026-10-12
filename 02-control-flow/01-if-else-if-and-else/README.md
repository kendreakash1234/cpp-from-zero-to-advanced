# 01 — if, else if, and else

## What is it?

An `if` statement runs a block only when its condition is true. `else if` adds more
conditions, checked in order, and `else` handles everything left. **Exactly one
branch runs: the first whose condition is true.**

## Why does it matter?

Programs must decide: valid input or not, which grade, which path. C++ also accepts
several conditions that are almost certainly bugs, and only warnings reveal them.

## Syntax

```cpp
if (condition) {
    // ...
} else if (other) {
    // ...
} else {
    // ...
}

if (const int toPass{50 - score}; toPass > 0) {   // C++17: toPass exists only here
    // ...
}
```

The condition is converted to `bool`: 0 is false, anything else is true.

## Grade classifier results

Tested with `cxx` (GCC 13), including the boundaries:

| Input | Output              | Exit |
| ----- | ------------------- | ---- |
| `95`  | A                   | 0    |
| `75`  | B                   | 0    |
| `74`  | C                   | 0    |
| `0`   | F                   | 0    |
| `-5`  | out of range        | 1    |
| `abc` | Expected an integer | 1    |
| `100` | A                   | 0    |
| `101` | out of range        | 1    |

Boundaries (74/75, 100/101, 0/-5) are where `<` vs `<=` mistakes hide.
Shell note: `printf "-5"` fails because printf treats `-5` as an option; use
`printf -- "-5"`.

## First match wins: order matters

The same chain with `>= 50` checked first:

| Input | Wrong order | Correct |
| ----- | ----------- | ------- |
| 95    | C           | A       |
| 75    | C           | B       |
| 74    | C           | C       |
| 0     | F           | F       |
| 100   | C           | A       |

Every score from 50 matches `>= 50` first, so the `B` and `A` branches become
unreachable, with no warning. Put the most restrictive condition first.

## The four traps

| Code                          | Problem                                    | `cxx` warning                                             |
| ----------------------------- | ------------------------------------------ | --------------------------------------------------------- |
| `if (x = 5)`                  | assigns 5: always true                     | suggest parentheses around assignment used as truth value |
| `if (x > 10);` then `{ ... }` | the `;` is the body; the block always runs | suggest braces around empty body in an 'if' statement     |
| the same layout               | indentation hides the real structure       | this 'if' clause does not guard...                        |
| nested `if` with one `else`   | `else` binds to the nearest `if`           | suggest explicit braces to avoid ambiguous 'else'         |

## The dangling else

With `a = 1` and `b = 0`:

| Version                      | `else` belongs to | Output      |
| ---------------------------- | ----------------- | ----------- |
| no braces                    | inner `if`        | `which if?` |
| braces around the inner `if` | outer `if`        | (nothing)   |

Indentation means nothing to the compiler; braces define structure. Always use them.

## Common mistakes

| Mistake                           | Fix                                            |
| --------------------------------- | ---------------------------------------------- |
| `=` instead of `==`               | read `-Wparentheses` warnings                  |
| Missing braces                    | always use braces, even for one statement      |
| Wrong order in a chain            | most restrictive condition first               |
| Redundant upper bounds in a chain | earlier branches already excluded those values |
| Errors printed to `std::cout`     | `std::cerr` for errors                         |
| Testing only easy inputs          | test every boundary                            |

## Key takeaway

First match wins, so order the chain carefully, always use braces, and test the
boundaries.

## Standard

C++23 (`if` with an initializer since C++17).

## Compile command

```bash
g++ -Wall -Wextra -Wpedantic -Wshadow=local -std=c++23 main.cpp -o main
```