# 03 — switch, case, and default

## What is it?

A `switch` compares **one integer value** against constant `case` labels and
**jumps** to the matching one. Execution then runs **downward until `break`**.
`default` runs when nothing matches.

## Why does it matter?

When one value selects among many fixed options (an operator, a menu choice), a
`switch` states that intent directly. Its C heritage brings one big trap: cases
fall through without `break`.

## Rules

Tested with `cxx` (GCC 13):

| Rule                      | Example                                            | Result                                                           |
| ------------------------- | -------------------------------------------------- | ---------------------------------------------------------------- |
| Only integer-like values  | `switch (std::string{...})`                        | error: switch quantity not an integer                            |
| Labels must be constants  | `case k:` with `int k{2};`                         | error: the value of 'k' is not usable in a constant expression   |
| No duplicate labels       | two `case 1:`                                      | error: duplicate case value                                      |
| No ranges in standard C++ | `case 1 ... 3:`                                    | warning: range expressions in switch statements are non-standard |
| No variable jumped over   | `case '/': const double r{a / b};` then `default:` | error: jump to case label                                        |
| Missing `break`           | `case '+': ...` then `case '-':`                   | warning: this statement may fall through                         |

`char` works because a `char` is an integer (`'+'` is 43). `std::string` is a class
type with no integer value to jump on.

## Fall-through

Without `break` after `+`, input `8 + 2` printed both the addition **and** the
subtraction. Two ways to share code on purpose:

| Form                               | Use                                         |
| ---------------------------------- | ------------------------------------------- |
| `case 'x': case 'X': case '*':`    | stacked empty labels: no warning needed     |
| `case 6: [[fallthrough]]; case 7:` | a case that continues into the next (C++17) |

## Calculator results

Tested with `cxxt`:

| Input     | Output           | Exit |
| --------- | ---------------- | ---- |
| `8 + 2`   | 8 + 2 = 10       | 0    |
| `8 - 2`   | 8 - 2 = 6        | 0    |
| `8 * 2`   | 8 * 2 = 16       | 0    |
| `8 x 2`   | 8 * 2 = 16       | 0    |
| `8 X 2`   | 8 * 2 = 16       | 0    |
| `8 / 2`   | 8 / 2 = 4        | 0    |
| `8 / 0`   | division by zero | 1    |
| `8 % 2`   | 8 % 2 = 0        | 0    |
| `8 % 0.5` | division by zero | 1    |
| `abc`     | invalid input    | 1    |
| `8 ? 2`   | unknown operator | 1    |

## Two bugs found while building it

| Bug                                             | Symptom                                    | Fix                                 |
| ----------------------------------------------- | ------------------------------------------ | ----------------------------------- |
| Read `a >> b >> op` for input `8 + 2`, no guard | every run printed "unknown operator"       | read `a >> op >> b`, guard the read |
| Guarded `b == 0`, divided by `int(b)`           | `8 % 0.5`: runtime error: division by zero | guard the converted divisor         |

A guard must check the value that is actually used.

## Shell note

`printf "8 % 2"` fails: `%` starts a printf format code. Pass input as data:
`printf '%s' "8 % 2"`.

## Common mistakes

| Mistake                                | Fix                                     |
| -------------------------------------- | --------------------------------------- |
| Forgotten `break`                      | Treat `-Wimplicit-fallthrough` as a bug |
| Intended fall-through, undocumented    | `[[fallthrough]];`                      |
| Variable declared in a case            | Wrap the case in `{ }`                  |
| No `default`, or `default` returning 0 | Report unknown values, exit with 1      |
| Ranges with `case`                     | Use an `if` chain                       |

## Key takeaway

A switch jumps to a label and runs downward until `break`. Guard the input, guard
the value you actually use, and make every error exit non-zero.

## Standard

C++23 (`[[fallthrough]]` and `switch` with an initializer since C++17).

## Compile and test

```bash
g++ -Wall -Wextra -Wpedantic -Wshadow=local -std=c++23 main.cpp -o main
for v in "8 + 2" "8 / 0" "8 % 0.5" "abc" "8 ? 2"; do echo "== $v"; printf '%s' "$v" | ./main; echo "exit: $?"; done
```