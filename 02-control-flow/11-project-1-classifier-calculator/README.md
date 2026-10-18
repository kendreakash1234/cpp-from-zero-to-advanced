# 11 — Project 1: Number Classifier and Calculator

The Stage 02 gate project: a menu program built only from Stage 01 and Stage 02
features (plus one small helper function), with robust input validation.

## Features

```text
1 Classify a number     sign, parity, digit count, prime
2 Calculator            a op b with + - * x X / %
3 Primes in a range     2 <= low <= high <= 10000
4 Quit
```

## Design

Every prompt uses the same validation loop, with **three exits**:

| Exit              | When                                      | Result                              |
| ----------------- | ----------------------------------------- | ----------------------------------- |
| valid input       | read succeeds, no trailing text, in range | continue                            |
| end of input      | `std::cin.eof()`                          | `no more input` (std::cerr), exit 1 |
| too many attempts | 3 failed attempts                         | `too many invalid attempts`, exit 1 |

Retry messages (`not a number`, `out of range`, `trailing characters`) go to
`std::cout`. Quit prints `bye` and returns 0 immediately.

Key decisions:

| Decision                                | Why                                               |
| --------------------------------------- | ------------------------------------------------- |
| explicit `return` for each exit         | a combined loop condition with `\|\|` never ended |
| `i <= x / i` in the prime test          | `i * i` overflowed for 2147483647 (UBSan)         |
| `do while` with `rest != 0` for digits  | gives 1 for 0, and works for negatives            |
| `double` in the calculator              | `7 / 2` must be 3.5; `int` overflowed             |
| `%` checks the int range and `-1` first | `1e20` to `int` and `INT_MIN % -1` are both UB    |

## Test plan and results

33 tests, written before the final version. All pass with
`-Wall -Wextra -Wpedantic -Wshadow=local -Wduplicated-cond -Wduplicated-branches -Wlogical-op`
and under `-fsanitize=undefined,float-cast-overflow -D_GLIBCXX_ASSERTIONS` (zero reports).

| #   | Input (piped)       | Expected                                          | Exit | Result |
| --- | ------------------- | ------------------------------------------------- | ---- | ------ |
| 1   | `4`                 | bye                                               | 0    | ✅     |
| 2   | `0` `4`             | out of range, bye                                 | 0    | ✅     |
| 3   | `5` `4`             | out of range, bye                                 | 0    | ✅     |
| 4   | `abc` `4`           | not a number, bye                                 | 0    | ✅     |
| 5   | `2x` `4`            | trailing characters, bye                          | 0    | ✅     |
| 6   | `a` `b` `c`         | too many invalid attempts                         | 1    | ✅     |
| 7   | (empty)             | no more input                                     | 1    | ✅     |
| 8   | `1` `7` (then end)  | prime: yes, no more input                         | 1    | ✅     |
| 9   | `1` `0`             | sign: zero, parity: even, digits: 1, prime: no    | 0    | ✅     |
| 10  | `1` `1`             | sign: positive, parity: odd, digits: 1, prime: no | 0    | ✅     |
| 11  | `1` `2`             | parity: even, prime: yes                          | 0    | ✅     |
| 12  | `1` `-7`            | sign: negative, parity: odd, digits: 1, prime: no | 0    | ✅     |
| 13  | `1` `97`            | digits: 2, prime: yes                             | 0    | ✅     |
| 14  | `1` `100`           | digits: 3, prime: no                              | 0    | ✅     |
| 15  | `1` `121`           | prime: no                                         | 0    | ✅     |
| 16  | `1` `-45`           | sign: negative, digits: 2                         | 0    | ✅     |
| 17  | `1` `2147483647`    | digits: 10, prime: yes                            | 0    | ✅     |
| 18  | `1` `abc` `5`       | not a number, then prime: yes                     | 0    | ✅     |
| 19  | `1` `a` `b` `c`     | too many invalid attempts                         | 1    | ✅     |
| 20  | `1` (then end)      | no more input                                     | 1    | ✅     |
| 21  | `2` `7 / 2`         | 7 / 2 = 3.5                                       | 0    | ✅     |
| 22  | `2` `8 x 2`         | = 16                                              | 0    | ✅     |
| 23  | `2` `9 % 4`         | 9 % 4 = 1                                         | 0    | ✅     |
| 24  | `2` `8 / 0`         | division by zero, bye                             | 0    | ✅     |
| 25  | `2` `8 % 0.5`       | division by zero, bye                             | 0    | ✅     |
| 26  | `2` `8 ? 2`         | unknown operator, bye                             | 0    | ✅     |
| 27  | `2` (then end)      | no more input                                     | 1    | ✅     |
| 28  | `3` `2 2`           | count: 1                                          | 0    | ✅     |
| 29  | `3` `10 20`         | 11 13 17 19, count: 4                             | 0    | ✅     |
| 30  | `3` `20 10` `10 20` | out of range, count: 4                            | 0    | ✅     |
| 31  | `3` `1 10` `2 10`   | out of range, count: 4                            | 0    | ✅     |
| 32  | `3` `2 10000`       | count: 1229                                       | 0    | ✅     |
| 33  | `3` (then end)      | no more input                                     | 1    | ✅     |

Extra sanitizer checks: `2147483647 * 2` and `-2147483648 / -1` (double, no
overflow), `1e20 % 3` (out of range for %), `-2147483648 % -1` (= 0).

## Bugs found during development

| Bug in an earlier version                | Symptom                                                   |
| ---------------------------------------- | --------------------------------------------------------- |
| prime loop stepped by 5 instead of 6     | 121 and 143 "prime"; 2046 primes up to 10000 (true: 1229) |
| `i * i <= x`                             | signed overflow at 2147483647                             |
| no end-of-input exit                     | `Invalid input` forever                                   |
| `choice != 4 \|\| invalidCounts < 3`     | Quit did not quit; end of input never ended               |
| guards that printed but did not leave    | `abc` classified as 0; `20 10` ran anyway                 |
| `while (number > 0)` for digits          | 0 and negatives had 0 digits                              |
| `int` calculator                         | 7 / 2 = 3; `2147483647 * 2` = -2                          |
| `static_cast<int>(1e20)`, `INT_MIN % -1` | UBSan reports; the second crashed                         |

## Known limitations

- The validation loop is repeated four times (menu and three features): duplicated
  logic. Functions with parameters (Stage 03) will remove it.
- `%` works on the integer parts of its operands, within `int` range.

## Build and test

```bash
g++ -Wall -Wextra -Wpedantic -Wshadow=local -Wduplicated-cond -Wduplicated-branches -Wlogical-op -std=c++23 main.cpp -o main
printf '4\n' | ./main; echo "exit: $?"
printf '' | ./main; echo "exit: $?"
printf '1\n2147483647\n4\n' | ./main
printf '3\n2 10000\n4\n' | ./main | tail -1
```