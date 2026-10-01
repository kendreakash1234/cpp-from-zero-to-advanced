# 19 — Type Conversions and static_cast

## What is it?

A **conversion** turns a value of one type into another type.

- **Implicit**: automatic, whenever C++ needs a different type (`7.0 / 2`).
- **Explicit**: requested with `static_cast<Type>(value)`.

## Why does it matter?

C++ converts implicitly in many places, and some conversions lose information
silently. `static_cast` makes intentional conversions visible; braces and warnings
catch the accidental ones.

## Results

Tested with `cxx` (GCC 13, `-std=c++23`):

| Code                               | Result  | Why                              |
| ---------------------------------- | ------- | -------------------------------- |
| `sum / count` (25 / 3)             | 8       | integer division                 |
| `static_cast<double>(sum / count)` | 8       | cast after dividing: too late    |
| `static_cast<double>(sum) / count` | 8.33333 | cast an operand                  |
| `static_cast<int>(9.99)`           | 9       | truncates toward zero            |
| `static_cast<int>(-9.99)`          | -9      | truncates toward zero            |
| `static_cast<int>(0.5)`            | 0       | never rounds                     |
| `'a' + 1`                          | 98      | integer promotion: an `int`      |
| `static_cast<char>('a' + 1)`       | b       | back to `char`                   |
| `sizeof('a' + 1)`                  | 4       | the result is an `int`           |
| `-5 < 3u`                          | false   | -5 becomes a huge unsigned value |

## The usual arithmetic conversions

1. If either operand is floating-point, the other becomes floating-point.
2. Otherwise, small types (`char`, `short`, `bool`) are promoted to `int`.
3. If they still differ, the wider type wins; signed meeting unsigned of the
   same size becomes **unsigned**.

## Signed vs unsigned

```cpp
const int index{-1};
const unsigned int size{5};
(index < size)                                              // false, -Wsign-compare
(index < 0 || static_cast<unsigned int>(index) < size)      // true
```

The fix is safe because `||` short-circuits: the cast only runs when `index` is
not negative.

## The sanitizer gap

```cpp
double big{3e10};
int bad{static_cast<int>(big)};   // undefined behavior: does not fit int
```

| Build                                             | Result                                                                            |
| ------------------------------------------------- | --------------------------------------------------------------------------------- |
| `cxx -g -fsanitize=undefined`                     | prints -2147483648, no message                                                    |
| `cxx -g -fsanitize=undefined,float-cast-overflow` | `runtime error: 3e+10 is outside the range of representable values of type 'int'` |

A clean sanitizer run only covers the checks that were enabled.

## static_cast vs C-style casts

`int n = (int)3.7;` built with `-Wold-style-cast`:

```text
warning: use of old-style cast to 'int' [-Wold-style-cast]
```

GCC suggests the replacement: `int n{static_cast<int>(3.7)};`. `static_cast`
allows only sensible conversions, states intent, and is easy to search for.

## Common mistakes

| Mistake                              | Problem                              | Fix                                            |
| ------------------------------------ | ------------------------------------ | ---------------------------------------------- |
| `static_cast<double>(total / count)` | Division already happened            | `static_cast<double>(total) / count`           |
| Expecting a cast to round            | It truncates                         | `std::round`                                   |
| `index < size` with mixed signedness | -1 becomes huge                      | Guard the negative case first                  |
| Out-of-range double to int           | Undefined behavior                   | Check the range; test with float-cast-overflow |
| `(int)x`                             | Hides intent, allows dangerous casts | `static_cast<int>(x)`                          |
| A cast to silence a narrowing error  | Hides a real data loss               | Fix the type instead                           |

## UB watch

Converting a floating-point value that does not fit the target integer type is
undefined behavior. On GCC, `-fsanitize=undefined` does not report it; add
`float-cast-overflow`.

## Key takeaway

`static_cast` makes a conversion explicit, not safe. Cast operands, guard
signedness, and know which sanitizer checks are enabled.

## Standard

C++23 (signed-to-unsigned conversion is modulo 2ⁿ; C++20 also defines the reverse).

## Compile commands

```bash
g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main
g++ -Wall -Wextra -Wpedantic -std=c++23 -g -fsanitize=undefined,float-cast-overflow main.cpp -o main
```