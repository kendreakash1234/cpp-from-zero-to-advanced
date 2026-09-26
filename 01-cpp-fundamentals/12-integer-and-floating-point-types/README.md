# 12 — Integer and Floating-Point Types

## What is it?

A fixed number of bits can hold only a limited set of values.

- **Integer types** store whole numbers **exactly**, within a **range**.
  - **signed** (the default): negative and positive values.
  - **unsigned**: zero and positive values only.
- **Floating-point types** store numbers with fractions over a huge range,
  but only **approximately**, with limited **precision**.

Integers are exact but narrow; floating-point types are wide but approximate.

## Why does it matter?

C++ integers never grow to fit a value, and most decimal fractions cannot be
stored exactly. Choosing a type means knowing what it can represent, not just
how big it is.

## Signed vs. unsigned: the top bit

Each bit is a place value. In **signed** (two's complement, required since
C++20), the top place is worth **minus** its usual value.

3-bit example:

| Bits  | Unsigned (+4, 2, 1)   | Signed (−4, 2, 1) |
| `000` | 0                     | 0                 |
| `011` | 3                     | 3                 |
| `100` | 4                     | −4                |
| `111` | 7                     | −1                |

Both forms have the same size and the same **number** of values (8). Signed
gives up 4 to 7 to represent −4 to −1.

8-bit: `11111111` is 255 unsigned (+128 + 127) and −1 signed (−128 + 127).
`01111111` is 127 in both, because its top bit is 0.

## Integer ranges

For an **n-bit** integer:

| Form      | Range             |
| signed    | −2ⁿ⁻¹ to 2ⁿ⁻¹ − 1 |
| unsigned  | 0 to 2ⁿ − 1       |

The signed maximum is 2ⁿ⁻¹ − 1 because one of the 2ⁿ⁻¹ non-negative patterns is 0.

Hand check for `short` (16 bits): 2¹⁵ = 32,768, so −32,768 to 32,767. ✓

Measured on x86-64 Linux with `std::numeric_limits`:

| Type                  | Range |
| `short`               | −32,768 to 32,767 |
| `unsigned short`      | 0 to 65,535 |
| `int`                 | −2,147,483,648 to 2,147,483,647 |
| `unsigned int`        | 0 to 4,294,967,295 |
| `long long`           | −9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |
| `unsigned long long`  | 0 to 18,446,744,073,709,551,615 |

## Floating-point precision

A `double` is stored like scientific notation in binary:
1 sign bit, 11 exponent bits, 52 fraction bits (IEEE 754 on this platform).

| Type      | `digits10` (digits guaranteed to survive) | Range             |
| `float`   | 6                                         | ±3.40282 × 10³⁸   |
| `double`  | 15                                        | ±1.79769 × 10³⁰⁸  |

Only fractions built from halves (½, ¼, ⅛, …) are exact. 0.1 is 1/10, which
cannot be built from a finite sum of halves, so it is rounded:

```text
0.1 is stored as 0.10000000000000001
0.2 is stored as 0.20000000000000001
0.3 is stored as 0.29999999999999999
0.4 is stored as 0.40000000000000002
0.5 is stored as 0.5
```

A `float` represents every whole number up to 2²⁴ = 16,777,216. Above that,
`float` values are 2 apart, so `float big{16777217};` is rejected: the value
would change.

## Common mistakes

| Mistake                                           | Problem                           | Fix                           |
| `int worldPopulation{8'000'000'000};`             | Too large for `int`               | `long long`                   |
| `unsigned` because "it can't be negative"         | `0 - 1` wraps to the maximum      | Signed types for arithmetic   |
| Treating 0.1 as exact | It is rounded             | Integers for exact amounts (cents)|
| `float` by default                                | Only ~6–7 digits                  | `double` by default           |
| `numeric_limits<double>::min()` as most negative  | It is the smallest positive value | `lowest()`                    |

## UB watch

Unsigned arithmetic wraps around modulo 2ⁿ, which is defined. **Signed
overflow is undefined behavior.** Covered in detail in topic 18.

## Key takeaway

Integers are exact within a range; floating-point values are approximate
within a precision. Pick the type whose range and precision fit the value.

## Standard

C++23 (two's complement required since C++20; `long long` since C++11;
digit separators such as `8'000'000'000` since C++14).

## Compile command

```bash
g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main
```