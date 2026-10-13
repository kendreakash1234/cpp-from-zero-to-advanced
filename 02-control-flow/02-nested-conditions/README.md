# 02 — Nested Conditions, and How to Flatten Them

## What is it?

A **nested condition** is an `if` inside another `if`. The inner check runs only
when the outer one passed. Deep nesting ("arrow code") is hard to read and test, so
the main skill is **flattening** it.

## Three tools for flattening

| Tool              | How                                                   | Safe when                            |
| ----------------- | ----------------------------------------------------- | ------------------------------------ |
| Guard clauses     | check each bad case first and `return`                | always; each guard must return       |
| Combine with `&&` | `if (a) { if (b) {...} }` becomes `if (a && b) {...}` | only if the outer `if` has no `else` |
| Invert            | check the opposite condition to exit early            | invert correctly (De Morgan)         |

## Guard order

1. **Input**: did the read succeed?
2. **Range**: is the value valid?
3. **Business rules**: too young, no ticket.
4. **Main path**: at the left margin, no nesting.

## Event entry checker results

Tested with `cxx` (GCC 13):

| Input  | Output        | Exit | Why                                             |
| ------ | ------------- | ---- | ----------------------------------------------- |
| `25 1` | allowed       | 0    | every guard passed                              |
| `25 0` | no ticket     | 0    | guard 4                                         |
| `15 1` | too young     | 0    | guard 3                                         |
| `15 0` | too young     | 0    | guard 3 comes first                             |
| `-3 1` | invalid input | 1    | guard 2: range                                  |
| `25 2` | invalid input | 1    | guard 1: `>>` into a `bool` accepts only 0 or 1 |
| `abc`  | invalid input | 1    | guard 1: read failed                            |

## The && trap

```cpp
if (age >= 18 && hasTicket) { std::cout << "allowed\n"; }
else                        { std::cout << "too young\n"; }
```

| Input  | Guard clauses | `&&` with `else` |
| ------ | ------------- | ---------------- |
| `25 1` | allowed       | allowed          |
| `25 0` | no ticket     | **too young** ✗  |
| `15 1` | too young     | too young        |

The `else` merges two different failures into one message. No warning.

## De Morgan's laws

| Condition   | Opposite     | Wrong        |
| ----------- | ------------ | ------------ |
| `age >= 18` | `age < 18`   | `age <= 18`  |
| `a && b`    | `!a \|\| !b` | `!a && !b`   |
| `a \|\| b`  | `!a && !b`   | `!a \|\| !b` |

`!(age >= 18 && hasTicket == 1)` becomes `age < 18 || hasTicket != 1`: it rejected
`25 0`, `15 1`, and `15 0`, the same inputs as the separate guards.

## Reading a bool with std::cin

| Input  | Value after the read | `fail()` |
| ------ | -------------------- | -------- |
| `0`    | false                | false    |
| `1`    | true                 | false    |
| `2`    | true                 | true     |
| `true` | false                | true     |

With `int hasTicket`, `2` reads fine, so a separate guard is needed:
`if (hasTicket != 0 && hasTicket != 1)`.

## Common mistakes

| Mistake                               | Fix                                            |
| ------------------------------------- | ---------------------------------------------- |
| Arrow code (4+ levels)                | Guard clauses                                  |
| A guard without `return`              | It falls through: `10` printed minor AND adult |
| `&&` replacing nesting with an `else` | Keep separate guards                           |
| Inverting `>=` to `<=`                | `>=` inverts to `<`                            |
| `!(a && b)` as `!a && !b`             | `!a \|\| !b`                                   |
| Checking rules before the input read  | Input first, then range, then rules            |

## Key takeaway

Check the bad cases first and leave early. Every guard must return, and the main
path stays at the left margin.

## Standard

C++23.

## Compile and test

```bash
g++ -Wall -Wextra -Wpedantic -Wshadow=local -std=c++23 main.cpp -o main
for v in "25 1" "25 0" "15 1" "15 0" "-3 1" "25 2" "abc"; do echo "== $v"; printf -- "$v" | ./main; done
```