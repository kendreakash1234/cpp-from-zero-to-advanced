# 04 — while and do while

## What is it?

Two loops that repeat a block while a condition is true. They differ only in
**when** the condition is checked.

| Loop       | Condition checked | Minimum runs |
| ---------- | ----------------- | ------------ |
| `while`    | before each run   | 0            |
| `do while` | after each run    | 1            |

```cpp
while (condition) { ... }
do { ... } while (condition);   // the ; is required
```

## Increment and decrement

| Code                | Result                              |
| ------------------- | ----------------------------------- |
| `int b{a++};` (a=5) | b = 5 (old value), then a = 6       |
| `int c{++a};` (a=6) | a = 7, then c = 7 (new value)       |
| `++i;` alone        | same effect as `i++;`: prefer `++i` |

## Reading until the input ends

```cpp
while (std::cin >> x) { ... }
```

The read is the condition: the loop stops at the first failed read (end of input,
or text like `abc`). Afterwards the input is finished, so any further read fails.

## Statistics and countdown results

Tested with `cxx` (GCC 13):

| Input     | Output                              | Note                                       |
| --------- | ----------------------------------- | ------------------------------------------ |
| `1 2 3 4` | count 4, sum 10, avg 2.5, `4 3 2 1` |                                            |
| `10`      | count 1, sum 10, avg 10, `1`        |                                            |
| (empty)   | no numbers                          | guard: no division by zero                 |
| `5 abc 7` | count 1, sum 5, avg 5, `1`          | the read stopped at `abc`; 7 is never read |
| `-3 3`    | count 2, sum 0, avg 0, `2 1`        |                                            |

## Bugs found while building it

| Bug                                     | Symptom                    | Fix                                  |
| --------------------------------------- | -------------------------- | ------------------------------------ |
| average computed with `count == 0`      | `avg -nan` for empty input | guard `count == 0` first             |
| a second `std::cin` read after the loop | always "Wrong input"       | count down from `count`; no new read |
| `do while` started with 0               | printed `j = 0` once       | `do while` runs once: guard it       |

## Loop traps

| Code                                         | Result                   | `cxx` reports                                              |
| -------------------------------------------- | ------------------------ | ---------------------------------------------------------- |
| loop body never updates the counter          | infinite loop            | nothing                                                    |
| `while (k < 3); { ++k; }`                    | infinite loop (exit 124) | this 'while' clause does not guard...                      |
| `unsigned int u{3}; while (u >= 0) { --u; }` | infinite loop            | comparison of unsigned expression in '>= 0' is always true |
| `do { ... } while (k < 3)` without `;`       | does not compile         | error: expected ';' before ...                             |
| `while (k = 5)`                              | always true              | suggest parentheses around assignment                      |

The stray-semicolon warning appeared in every normal layout tested. It only
disappeared when the entire program was written on a single line.

## Testing loops safely

```bash
printf '' | timeout 2 ./main; echo "exit: $?"   # 124 = killed after 2 seconds
```

`timeout` cannot tell a hang from a program waiting for keyboard input: always pipe
input. And chain build and test with `&&`, so a failed build cannot run the old binary:

```bash
cxx main.cpp -o main && printf '%s' "1 2 3 4" | ./main
```

## Key takeaway

`while` can run zero times; `do while` always runs once. Every loop needs an update
that ends it, and every test needs input and a fresh build.

## Standard

C++23.