# 11 — Fundamental Data Types

## What is it?

A **type** decides four things about an object: its **set of values**, its
**size**, its **representation** (how its bits are interpreted), and the
**operations** that are valid on it.

**Fundamental types** are built into the C++ language itself. They need no
`#include` and are not part of the Standard Library.

## Why does it matter?

Memory holds only bits. The type gives those bits their meaning: the same bit
pattern can be the number `65` as an `int` or the character `'A'` as a `char`.
C++ checks types at compile time, and uses them to choose storage and machine
instructions.

## The families

| Family `          | Types                                                                                      |
| Boolean           | `bool`                                                                                     |
| Character         | `char` (plus `signed char`, `unsigned char`, `wchar_t`, `char8_t`, `char16_t`, `char32_t`) |
| Integer           | `short`, `int`, `long`, `long long` (each also `unsigned`)                                 |
| Floating-point    | `float`, `double`, `long double`                                                           |
| Void              | `void` (no value; no object can have this type)                                            |

Boolean, character, and integer types are **integral types**. Integral plus
floating-point types are **arithmetic types**.

## Size guarantees vs. this platform

`sizeof(type)` gives the size of a type in bytes. It is evaluated at compile time.

| Type          | Guaranteed by the standard | x86-64 Linux (measured)       |
| `char`        | exactly 1 byte                    | 1                      |
| `bool`        | not specified                     | 1                      |
| `short`       | ≥ 16 bits                         | 2 bytes = 16 bits ✓    |
| `int`         | ≥ 16 bits, ≥ `short`              | 4 bytes = 32 bits ✓    |
| `long`        | ≥ 32 bits, ≥ `int`                | 8 bytes = 64 bits ✓    |
| `long long`   | ≥ 64 bits, ≥ `long`               | 8 bytes = 64 bits ✓    |
| `float`       | not specified                     | 4                      |
| `double`      | at least the precision of `float` | 8                      |
| `long double` | at least the precision of `double`| 16                     |

`sizeof(short) ≤ sizeof(int) ≤ sizeof(long) ≤ sizeof(long long)` holds.
`long` and `long long` are both 8 bytes here: equal sizes are allowed.

**Sizes beyond the guarantees are implementation-defined.** The platform's
data model decides them:

| Target            | Data model | `sizeof(long)` |
 
| x86-64 Linux      | LP64       | 8 |
| x86-64 Windows    | LLP64      | 4 |

Checked with Clang 18: `int main() { return sizeof(long); }` compiles to
`mov eax, 8` for `x86_64-pc-linux-gnu` and `mov eax, 4` for
`x86_64-pc-windows-msvc`. Same processor, same compiler, different target.

## Example

```cpp
int number{65};
char code{65};
std::cout << number << '\n';   // 65
std::cout << code << '\n';     // A
```

Both objects hold the value 65, and the byte containing `01000001` matches.
The type and size differ: `int` is 4 bytes, `char` is 1 byte here.

## How the program works

`main.cpp` prints `sizeof` for all nine types, then prints the value 65 as an
`int` and as a `char` to show that the type decides how the value is printed.

## Common mistakes

| Mistake                                | Problem                              | Fix                               |
| Assuming `long` is 8 bytes everywhere  | It is 4 bytes on Windows             | Rely only on guaranteed sizes     |
| Reading `sizeof(count)` as the value   | `sizeof` gives bytes, not contents   | `sizeof(x)` = bytes `x` occupies  |
| `sizeof int`                           | A type name needs parentheses        | `sizeof(int)`                     |
| `int average{7.5};`                    | `int` cannot hold a fraction         | `double average{7.5};`            |
| `void nothing;`                        | `void` has no value and no size      | `void` is not an object type      |

## Key takeaway

The type gives the bits their meaning. Know which sizes the standard guarantees
and which are only true on your platform.

## Standard

C++23 (`long long` guaranteed since C++11; `char8_t` since C++20).

## Compile command

```bash
g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main
```