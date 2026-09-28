# 14 — Literals

## What is it?

A **literal** is a value written directly in source code: `42`, `3.14`, `'A'`,
`"hi"`, `true`. **Every literal has a type**, decided by how it is written.

## Why does it matter?

The literal's type drives conversions, narrowing checks, and the code the compiler
generates. Some notations are traps: a leading `0` means octal, and a backslash
inside a string starts an escape sequence.

## Integer literals: one value, four notations

| Literal      | Notation        | Working          | Value |
| ------------ | --------------- | ---------------- | ----- |
| `255`        | decimal         | 2×100 + 5×10 + 5 | 255   |
| `0xFF`       | hex (base 16)   | 15×16 + 15       | 255   |
| `0377`       | octal (base 8)  | 3×64 + 7×8 + 7   | 255   |
| `0b11111111` | binary (base 2) | 128 + 64 + … + 1 | 255   |

All four are the same `int` value. The notation disappears after compilation.
`1'000'000` uses digit separators (C++14); they are ignored by the compiler.

The same digits with different prefixes:

| Literal | Notation | Value |
| ------- | -------- | ----- |
| `0b10`  | binary   | 2     |
| `010`   | octal    | 8     |
| `10`    | decimal  | 10    |
| `0x10`  | hex      | 16    |

## Every literal has a type

Measured with `sizeof` on x86-64 Linux:

| Literal      | Type                  | Size |
| ------------ | --------------------- | ---- |
| `42`         | `int`                 | 4    |
| `42U`        | `unsigned int`        | 4    |
| `42L`        | `long`                | 8    |
| `42LL`       | `long long`           | 8    |
| `42uz`       | `std::size_t` (C++23) | 8    |
| `3000000000` | `long`                | 8    |
| `0.1f`       | `float`               | 4    |
| `0.1`        | `double`              | 8    |
| `0.1L`       | `long double`         | 16   |
| `'A'`        | `char`                | 1    |
| `"hi"`       | `const char[3]`       | 3    |

- An unsuffixed decimal literal takes the first type that fits: `int`, then
  `long`, then `long long`. `3000000000` does not fit `int`, so it is a `long`.
- Floating-point literals are `double` unless suffixed with `f` or `L`.
- `uz` gives `std::size_t`, the same type `sizeof` produces.
- `"hi"` is 3 bytes: `h`, `i`, and the terminating `\0`.

## Escape sequences

| Escape | Meaning        |
| ------ | -------------- |
| `\n`   | newline        |
| `\t`   | tab            |
| `\\`   | backslash      |
| `\'`   | single quote   |
| `\"`   | double quote   |
| `\0`   | null character |

`"C:\new\table"` prints `C:`, a newline, `ew`, a tab, and `able`, with no warning.
Fix it with `"C:\\new\\table"` or `"C:/new/table"`.

## Common mistakes

| Mistake                | Problem                                  | Fix                          |
| ---------------------- | ---------------------------------------- | ---------------------------- |
| `int code{010};`       | Leading `0` means octal: value is 8      | `int code{10};`              |
| `"C:\new\table"`       | `\n` and `\t` become newline and tab     | `"C:\\new\\table"`           |
| `char letter{"A"};`    | `"A"` is a string, not a `char`          | `char letter{'A'};`          |
| `float gain{0.75};`    | Converts a `double` literal              | `float gain{0.75f};`         |
| `int big{3000000000};` | The literal is a `long` and does not fit | `long long big{3000000000};` |
| `unsigned int n{-1};`  | Narrowing: −1 is not unsigned            | Use a signed type            |

## Key takeaway

Every literal has a type. The way you write it (digits, prefix, suffix, quotes)
decides which.

## Standard

C++23 (binary literals and digit separators since C++14; `uz` suffix since C++23).

## Compile command

```bash
g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main
```