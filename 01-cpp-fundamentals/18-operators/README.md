# 18 — Arithmetic, Comparison, and Logical Operators

## What is it?

Operators combine values into a new value.

| Family     | Operators                   | Result   |       |        |
| ---------- | --------------------------- | -------- | ----- | ------ |
| Arithmetic | `+` `-` `*` `/` `%`         | a number |       |        |
| Comparison | `==` `!=` `<` `<=` `>` `>=` | `bool`   |       |        |
| Logical    | `&&` `\                     | \        | ` `!` | `bool` |

## Why does it matter?

Every calculation and decision uses operators, and C++ adds no safety checks:
integer division drops fractions, signed overflow is undefined behavior, and
`1 < x < 3` compiles but does not check a range.

## Arithmetic results

Tested with `cxx` (GCC 13, `-std=c++23`):

| Expression  | Result | Why                                |
| ----------- | ------ | ---------------------------------- |
| `17 / 5`    | 3      | integer division: fraction dropped |
| `17 % 5`    | 2      | remainder                          |
| `17.0 / 5`  | 3.4    | one `double` operand               |
| `-17 / 5`   | -3     | truncates toward zero              |
| `-17 % 5`   | -2     | takes the sign of the left operand |
| `2 + 3 * 4` | 14     | `*` before `+`                     |

The **operands'** types decide the calculation, not the variable the result goes into.

## Precedence (high to low)

| Level | Operators         |     |     |
| ----- | ----------------- | --- | --- |
| 1     | `!`, unary `-`    |     |     |
| 2     | `*` `/` `%`       |     |     |
| 3     | `+` `-`           |     |     |
| 4     | `<` `<=` `>` `>=` |     |     |
| 5     | `==` `!=`         |     |     |
| 6     | `&&`              |     |     |
| 7     | `\                | \   | `   |
| 8     | `=` `+=` ...      |     |     |

When in doubt, add parentheses.

## Signed overflow and UBSan

```cpp
int big{2147483647};
int result{big + 1};
```

| Build                         | Result                                                                                       |
| ----------------------------- | -------------------------------------------------------------------------------------------- |
| `cxx`                         | prints -2147483648, no warning                                                               |
| `cxx -g -fsanitize=undefined` | `runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int'` |
| `long long` instead of `int`  | prints 2147483648, clean under UBSan                                                         |

Signed overflow has no defined result in C++; seeing it wrap once proves nothing.
UBSan detects it at the exact line.

## Short-circuit: order matters

With `d = 0`, built with UBSan:

| Expression             | Result                                                      |
| ---------------------- | ----------------------------------------------------------- |
| `d != 0 && 10 / d > 1` | `false`: the division never runs                            |
| `10 / d > 1 && d != 0` | `runtime error: division by zero`, then the program crashes |

A guard only protects what comes after it.

## The chained-comparison trap

`(5 < x < 3)` with `x = 2` prints `true`: it means `(5 < x) < 3`, so `false`
becomes 0, and `0 < 3` is true. GCC warns:

```text
warning: comparison of constant '3' with boolean expression is always true
warning: comparisons like 'X<=Y<=Z' do not have their mathematical meaning
```

A range needs two comparisons: `(1 < x && x < 3)`. Test inside, below, and above:
2 → true, 0 → false, 5 → false.

## Common mistakes

| Mistake                         | Problem                           | Fix                             |
| ------------------------------- | --------------------------------- | ------------------------------- |
| `double avg{total / count};`    | Integer division happens first    | Make one operand floating-point |
| `int` overflow                  | Undefined behavior, silent        | Wider type; test with UBSan     |
| `0.1 + 0.2 == 0.3`              | `false` because of rounding       | Compare with a tolerance        |
| `1 < x < 3`                     | Always true or false, not a range | `1 < x && x < 3`                |
| `(x < 3) && (x < 5)` as a range | Just means `x < 3`                | One comparison per bound        |
| `10 / d > 1 && d != 0`          | Divides before checking           | Put the guard first             |

## UB watch

Signed overflow and integer division by zero are undefined behavior. Build tests
with `-fsanitize=undefined` from this topic on.

## Key takeaway

The operands decide the calculation, `&&` and `||` stop early, and UBSan finds
the undefined behavior that normal builds hide.

## Standard

C++23 (`%` with negative operands truncates toward zero since C++11).

## Compile commands

```bash
g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main
g++ -Wall -Wextra -Wpedantic -std=c++23 -g -fsanitize=undefined main.cpp -o main
```