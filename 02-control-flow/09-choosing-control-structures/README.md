# 09 — Choosing Control Structures, and Avoiding Unreachable and Duplicated Logic

## What is it?

Choosing the structure whose shape matches the question, then keeping the logic
clean: no **unreachable** branches or lines, and no **duplicated** conditions or code.

## Choosing a structure

| Situation                                       | Use                       |
| ----------------------------------------------- | ------------------------- |
| one condition, or ranges (`score >= 90`)        | `if` / `else if` / `else` |
| one integer or `char` against many fixed values | `switch`                  |
| choosing between two values                     | `cond ? a : b`            |
| several bad cases before the main work          | guard clauses             |
| every element, no position                      | range-based `for`         |
| a known count, or the index                     | classic `for`             |
| repeat until a condition changes                | `while`                   |
| must run at least once                          | `do while`                |

## What the compiler catches

Six bugs in one file (GCC 13):

| Bug                                | `-Wall -Wextra -Wpedantic` | `+ -Wduplicated-cond -Wduplicated-branches -Wlogical-op`  |
| ---------------------------------- | -------------------------- | --------------------------------------------------------- |
| `score < 0 && score > 100`         | silent                     | logical 'and' of mutually exclusive tests is always false |
| a second `else if (score >= 50)`   | silent                     | duplicated 'if' condition                                 |
| identical `if` / `else` bodies     | silent                     | this condition has identical branches                     |
| `x == 1 && x == 2`                 | silent                     | logical 'and' of mutually exclusive tests is always false |
| `>= 50` before `>= 75` and `>= 90` | silent                     | **silent**: A and B unreachable                           |
| a statement after `return`         | silent                     | **silent**                                                |

`-Wunreachable-code` is accepted by GCC but reports nothing. The three flags above
are now part of the `cxx` alias. Ordering discipline and boundary tests catch the rest.

## The same mistake, two structures

A duplicated value `2`:

| Structure  | Result                                                  |
| ---------- | ------------------------------------------------------- |
| `if` chain | warning: duplicated 'if' condition (with the new flags) |
| `switch`   | error: duplicate case value                             |

For exact values, `switch` makes the compiler refuse the mistake.

## Cleaned-up classifier results

| Input | Grade         | Bonus | Exit |
| ----- | ------------- | ----- | ---- |
| `95`  | A             | 0     | 0    |
| `75`  | B             | 0     | 0    |
| `50`  | C             | 0     | 0    |
| `10`  | F             | 0     | 0    |
| `100` | A             | 10    | 0    |
| `-1`  | out of range  | -     | 1    |
| `101` | out of range  | -     | 1    |
| `abc` | invalid input | -     | 1    |

Fixing identical branches means restoring what each branch was **meant** to do:
an `else` of 20 compiled cleanly but gave every score a bonus.

## The conditional operator and parity

```cpp
const int bonus{(score == 100) ? 10 : 0};
(n % 2 == 0) ? "even" : "odd"
```

`7` odd, `4` even, `0` even, `-3` odd. Compare with 0: `-3 % 2` is `-1`, so
`n % 2 == 1` would call -3 even.

## Best practices

- Match the structure to the question: values → `switch`, ranges → `if` chain.
- Most restrictive condition first.
- Fix duplicates by restoring intent, not by changing values.
- Delete code after `return` or `break`.
- Keep `?:` for choosing a value; never nest it deeply.
- Test the boundaries: some logic bugs are invisible to every compiler.

## Key takeaway

Choose the structure whose shape matches the question, so the compiler can check
it. Then test, because some logic bugs compile silently even with every flag on.

## Standard

C++23. Flags: GCC 13.

## Compile command

```bash
g++ -Wall -Wextra -Wpedantic -Wshadow=local -Wduplicated-cond -Wduplicated-branches -Wlogical-op -std=c++23 main.cpp -o main
```