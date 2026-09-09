# 10 — Repetition (Loops)

## What is repetition?
Repetition means running the same block of code multiple times without rewriting
it. In C++ this is done with **loops**: `while`, `do-while`, and `for`. This module
focuses on the **`while` loop**.

## Why it matters
Real programs repeat work — summing numbers, reading input until it ends, processing
each item in a list. Loops let one small piece of code run a controlled number of
times, including a count only known at runtime.

## Syntax
```cpp
while (condition) {
    // body — runs repeatedly while condition is true
}
```
The condition is a `bool` expression, checked **once before each pass**. If `true`,
the body runs and the condition is checked again; if `false`, the loop stops.

## The three parts of a counter loop
1. **Initialization** — set the counter (`int i{1};`)
2. **Condition** — when to keep going (`i <= num`)
3. **Update** — move toward stopping (`i++`)

A `for` loop packs these three into one line; a `while` loop spreads them out.

## Example
This program reads a positive integer `n` and computes `1 + 2 + ... + n`:
```cpp
int sum{}, i{1};
while (i <= num) {
    sum += i;
    i++;
}
```
Input `10` → `Sum of 1 to 10 is 55`.

## Common mistakes
- **Forgetting the update** (`i++`) → the condition stays true → infinite loop.
- **Stray semicolon**: `while (cond);` gives an empty body and loops forever.
- **Off-by-one**: wrong start value or `<` vs `<=` runs one time too many/few.
- Assuming the body runs at least once — a `while` may run **zero** times.

## Key takeaway
```
initialize → check condition → run body → update → re-check → ... → stop
```
Compiled with: `g++ -Wall -Wextra -std=c++17 main.cpp -o main`