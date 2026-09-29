# 15 — Assignment

## What is it?

**Assignment** replaces the value of an object that already exists.
**Initialization** gives an object its first value when it is created.

```cpp
int balance{1000};   // initialization: balance is created
balance = 1500;      // assignment: balance already exists
```

## Why does it matter?

Programs change state over time. Initialization happens once; assignment can
happen any number of times. The difference matters for `const` (topic 16) and
class types, and plain assignment does not protect against narrowing.

## Syntax

| Form           | Meaning                       |
| -------------- | ----------------------------- |
| `x = value;`   | store `value` in `x`          |
| `x = {value};` | same, but rejects narrowing   |
| `a = b = 42;`  | right to left: `a = (b = 42)` |
| `x += 5;`      | `x = x + 5;`                  |
| `x -= 5;`      | `x = x - 5;`                  |
| `x *= 5;`      | `x = x * 5;`                  |
| `x /= 5;`      | `x = x / 5;`                  |
| `x %= 5;`      | `x = x % 5;`                  |

The left side must be a **modifiable lvalue**: an object that can be changed.

## Narrowing: assignment does not protect you

Tested with `int p{};` and the value 7.8:

| Code         | Build              | Result                               |
| ------------ | ------------------ | ------------------------------------ |
| `p = 7.8;`   | `cxx`              | compiles silently; `p` is 7          |
| `p = 7.8;`   | `cxx -Wconversion` | warning: value changes from 7.8 to 7 |
| `p = {7.8};` | `cxx`              | error: narrowing conversion          |

The compiler reports 7.8 as `7.7999999999999998`: the `double` literal is not
exact (topic 12).

## Trace: each assignment changes only its left side

| After line | x   | y   | z   |
| ---------- | --- | --- | --- |
| start      | 1   | 2   | 3   |
| `x = y;`   | 2   | 2   | 3   |
| `y = z;`   | 2   | 3   | 3   |
| `z = x;`   | 2   | 3   | 2   |

`a = b` copies the current value; the two objects stay separate.

## Example output

```text
initialized:    1000
assigned 1500:  1500
after += 250:   1750
after -= 100:   1650
a = b = 42:     a = 42, b = 42
p = 7.8 gives:  7
trace result:   x = 2, y = 3, z = 2
```

## Common mistakes

| Mistake                         | Problem                                          | Fix                             |
| ------------------------------- | ------------------------------------------------ | ------------------------------- |
| `p = 7.8;`                      | Narrows silently to 7                            | `p = {7.8};` or `-Wconversion`  |
| `5 = balance;`                  | A literal is not an lvalue                       | `balance = 5;`                  |
| `balance + = 5;`                | `+=` is one token: "expected primary-expression" | `balance += 5;`                 |
| `int n = 0;` read as assignment | It is initialization                             | `=` in a definition initializes |
| Tracing assignments loosely     | Only the left side changes                       | Trace one line at a time        |

## Key takeaway

Initialization creates an object with a value; assignment replaces the value of
an existing object. Plain `=` narrows silently, so use braces or `-Wconversion`.

## Standard

C++23 (brace assignment rejects narrowing since C++11).

## Compile command

```bash
g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main
```