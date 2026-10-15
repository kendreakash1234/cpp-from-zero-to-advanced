# 05 — The Classic for Loop

## What is it?

A counting loop with its three parts on one line:

```cpp
for (int i{0}; i < 3; ++i) { ... }   // 0 1 2
```

| Part      | Example    | Runs            |
| --------- | ---------- | --------------- |
| init      | `int i{0}` | once, first     |
| condition | `i < 3`    | before each run |
| update    | `++i`      | after each run  |

A `for` loop is a `while` loop inside its own block, so a variable defined in the
init exists only inside the loop:

```text
for (int i{0}; i < 3; ++i) {} return i;
error: 'i' was not declared in this scope
```

## Results

Tested with `cxx` (GCC 13):

| Input | Output                                                               | Exit |
| ----- | -------------------------------------------------------------------- | ---- |
| `7`   | 7 x 1 = 7 ... 7 x 10 = 70; sum 310, max 90 at index 2; `65 90 85 70` | 0    |
| `1`   | table of 1, same statistics                                          | 0    |
| `12`  | table of 12, same statistics                                         | 0    |
| `0`   | invalid input                                                        | 1    |
| `13`  | invalid input                                                        | 1    |
| `abc` | invalid input                                                        | 1    |

## Bugs found while building it

| Bug                                | Symptom                         | Fix                     |
| ---------------------------------- | ------------------------------- | ----------------------- |
| failed-read guard without `return` | `abc` printed the table of 0    | `return 1` in the guard |
| `if (n < 1 && n > 12)`             | always false: 0 and 13 accepted | `n < 1 \|\| n > 12`     |
| `k < scores.size() - 1`            | the last score (65) was skipped | `k < scores.size()`     |

## Off-by-one, both directions

| Condition               | Effect                                                                                   |
| ----------------------- | ---------------------------------------------------------------------------------------- |
| `k < scores.size() - 1` | one element too few                                                                      |
| `k <= scores.size()`    | `cxx`: printed `scores[4] = 0` silently; `cxxt`: `Assertion '__n < this->size()' failed` |
| `k < scores.size()`     | correct                                                                                  |

The 0 from `scores[4]` is not a rule: it is whatever memory followed the data.

## Index types and counting backwards

| Code                                                     | Result                                                                 |
| -------------------------------------------------------- | ---------------------------------------------------------------------- |
| `for (int k{0}; k < v.size(); ++k)`                      | warning: comparison of integer expressions of different signedness     |
| `for (std::size_t k{0}; k < v.size(); ++k)`              | clean                                                                  |
| `for (std::ptrdiff_t k{0}; k < std::ssize(v); ++k)`      | clean (C++20 signed size)                                              |
| `for (std::size_t k{v.size() - 1}; k >= 0; --k)`         | never ends: comparison of unsigned expression in '>= 0' is always true |
| `for (std::size_t k{v.size()}; k > 0; --k)` + `v[k - 1]` | safe, also for an empty vector                                         |

## Floating-point counters

| Loop                                           | Result                                  |
| ---------------------------------------------- | --------------------------------------- |
| `for (double d{0.0}; d != 1.0; d += 0.1)`      | never equals 1.0: hit the 20-step guard |
| `for (int i{0}; i <= 10; ++i)`, `d = i / 10.0` | exactly 11 runs                         |

Count with integers; compute decimals from the counter.

## Key takeaway

Keep the counter in the loop, match its type to `size()`, use `<` to the end, count
backwards with `k > 0` and `k - 1`, and never count with floating-point.

## Standard

C++23 (`std::ssize` since C++20).