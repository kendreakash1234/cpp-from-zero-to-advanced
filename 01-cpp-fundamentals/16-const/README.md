# 16 — const

## What is it?

`const` makes an object **read-only after initialization**. A `const` object can
be initialized, but never assigned.

```cpp
const int maxItems{50};
maxItems = 60;   // error: assignment of read-only variable 'maxItems'
```

## Why does it matter?

Values that should never change (limits, rates, IDs) become rules the compiler
enforces, not comments. It documents intent, and C++ practice is to make objects
`const` by default.

## Rules

Tested with `cxx` (GCC 13, `-std=c++23`):

| Code                    | Result                                                   |
| ----------------------- | -------------------------------------------------------- |
| `const int limit;`      | error: uninitialized 'const limit'                       |
| `maxItems = 60;`        | error: assignment of read-only variable 'maxItems'       |
| `maxItems += 1;`        | error: assignment of read-only variable 'maxItems'       |
| `std::cin >> maxItems;` | error: no match for 'operator>>' ... discards qualifiers |
| `const int q{input};`   | allowed: the value can come from run time                |

## const is not compile-time

`const` means "not modifiable", not "known at compile time". The value can come
from user input. Compile-time values are `constexpr` (Stage 10).

## Pattern: read input, then copy into a const

```cpp
int quantityInput{};
std::cin >> quantityInput;                  // std::cin needs a modifiable variable
const int orderedQuantity{quantityInput};   // fixed from here on
```

## Reading a long error message

`std::cin >> quantity;` with a `const int` produces a very long error. Read the
first error, then search for the line naming your type:

```text
error: no match for 'operator>>' (operand types are 'std::istream' and 'const int')
error: binding reference of type 'int&' to 'const int' discards qualifiers
```

`std::cin` needs write access to the variable; giving it would discard `const`.

## Should it be const?

| Value                   | const? | Why                                      |
| ----------------------- | ------ | ---------------------------------------- |
| Days in a week          | yes    | never changes                            |
| Loop counter            | no     | it is updated; `const` would not compile |
| Birth year, read once   | yes    | read into a normal variable, then copy   |
| Running total of a cart | no     | it changes with each item                |

## Example output

```text
Enter the quantity: 7
max items:        50
tax rate:         0.18
currency:         $
ordered quantity: 7
```

## Common mistakes

| Mistake                         | Problem                          | Fix                                   |
| ------------------------------- | -------------------------------- | ------------------------------------- |
| `const int limit;`              | A const must be initialized      | `const int limit{10};`                |
| Modifying a const               | Assignment and `+=` are rejected | Remove `const` only if it must change |
| Magic numbers (`amount * 0.18`) | Meaning unclear, hard to change  | `const double taxRate{0.18};`         |
| `const` input variable          | `std::cin` cannot write into it  | Read first, then copy into a const    |
| Thinking const = compile-time   | Run-time values are allowed      | Compile-time is `constexpr`           |

## Key takeaway

`const` objects are initialized once and never changed. Make values `const`
unless they need to change.

## Standard

C++23 (`const` has existed since the first C++ standard).

## Compile command

```bash
g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main
```