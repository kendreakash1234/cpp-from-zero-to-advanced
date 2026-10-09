# 22 — A First Look at std::string and std::vector

## What is it?

- **`std::string`** (`<string>`): a sequence of characters.
- **`std::vector<T>`** (`<vector>`): a sequence of values of type `T` that can grow.

Both are Standard Library class types that know their size, grow when needed, and
release their memory automatically at the end of their scope.

## Why does it matter?

They replace fixed-size C arrays and character arrays, which cannot grow and do not
know their own size. They are the default choice for text and lists in modern C++.

## Basic operations

| Operation        | Example                         | Result           |
| ---------------- | ------------------------------- | ---------------- |
| size             | `city.size()`                   | 4 for `"Pune"`   |
| element by index | `city[0]`                       | `'P'`            |
| last element     | `city.back()`                   | `'e'`            |
| join strings     | `city + ", India"`              | `"Pune, India"`  |
| add to a vector  | `temps.push_back(33)`           | size 3 becomes 4 |
| first / last     | `temps.front()`, `temps.back()` | 28, 33           |
| checked access   | `temps.at(1)`                   | 31               |

Valid indexes run from `0` to `size() - 1`.

## Out of bounds: three builds

Reading index 10 from a 3-element vector (tested with GCC 13):

| Access                               | Result                                                                |
| ------------------------------------ | --------------------------------------------------------------------- |
| `v[10]`, `cxx`                       | printed 0, exit code 0: silent undefined behavior                     |
| `v[10]`, `cxx -D_GLIBCXX_ASSERTIONS` | `Assertion '__n < this->size()' failed`, aborted                      |
| `v.at(10)`, `cxx`                    | `std::out_of_range`: `__n (which is 10) >= this->size() (which is 3)` |

Use `.at()` when the index comes from outside the program, and build tests with
`-D_GLIBCXX_ASSERTIONS`.

## Parentheses vs braces

| Code                      | Result                      |
| ------------------------- | --------------------------- |
| `std::vector<int> a(4);`  | 4 elements, all 0           |
| `std::vector<int> b{4};`  | 1 element: 4                |
| `std::string s1(3, 'x');` | `"xxx"`, size 3             |
| `std::string s2{3, 'x'};` | size 2: `char(3)` and `'x'` |

For "N copies of a value", use parentheses.

## size() vs sizeof

`sizeof(std::string)` is 32 and `sizeof(std::vector<int>)` is 24 on this platform,
whatever they hold: the object stores bookkeeping, and the elements usually live in
separately allocated memory. Use `size()` for the number of elements.

## Example output

```text
Pune, size 4, first 'P', last 'e'
Pune, India, size 11
joined: C++
temps: size 4, front 28, back 33, temps[1] 31, temps.at(1) 31
a(4): size 4, a[0] 0
b{4}: size 1, b[0] 4
s1(3, 'x'): size 3, s2{3, 'x'}: size 2
```

## Common mistakes

| Mistake                              | Problem                                | Fix                                     |
| ------------------------------------ | -------------------------------------- | --------------------------------------- |
| `v[v.size()]`                        | Undefined behavior, often silent       | Last index is `size() - 1`; use `.at()` |
| `std::vector<int> v{3};` for 3 zeros | One element, 3                         | `std::vector<int> v(3);`                |
| `"C" + "++"`                         | Error: two `const char` arrays         | `std::string{"C"} + "++"`               |
| `std::cin >> name` for a full name   | Stops at the first space               | `std::getline` (Stage 04)               |
| `sizeof(name)` as the length         | Object size, not text length           | `name.size()`                           |
| Missing `#include <string>`          | Compiles by accident on some libraries | Include what you use                    |

## UB watch

`[]` with an invalid index is undefined behavior. A normal build can print a
believable value and exit successfully.

## Key takeaway

Use `std::string` and `std::vector` by default, index from 0 to `size() - 1`, and
let `.at()` or `-D_GLIBCXX_ASSERTIONS` catch bad indexes.

## Standard

C++23.

## Compile commands

```bash
g++ -Wall -Wextra -Wpedantic -Wshadow=local -std=c++23 main.cpp -o main
g++ -Wall -Wextra -Wpedantic -Wshadow=local -std=c++23 -D_GLIBCXX_ASSERTIONS main.cpp -o main
```