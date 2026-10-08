# 21 — Reading Input with std::cin and Detecting Failure

## What is it?

`std::cin >> value` reads text from standard input and converts it to the
variable's type. If the text cannot be converted, the stream enters a **fail
state**. Nothing crashes and nothing is thrown: the program must check.

## Why does it matter?

Input is the part of a program you do not control. A failed stream silently skips
every later read, and the variable alone cannot tell you whether the read worked.

## How >> reads an int

1. Skip whitespace.
2. Read characters while they can be part of an `int` (sign, digits).
3. Stop at the first character that does not fit, and leave it in the buffer.

## What happens with each input

Two reads into variables initialized to -1, tested with `cxx` (GCC 13):

| Input         | first      | fail after first | second | Why                                                |
| ------------- | ---------- | ---------------- | ------ | -------------------------------------------------- |
| `10 20`       | 10         | false            | 20     | normal                                             |
| `abc`         | 0          | true             | -1     | second read skipped: stream is failed              |
| `7xyz`        | 7          | false            | 0      | partial input succeeds; `xyz` breaks the next read |
| `4.9`         | 4          | false            | 0      | `.9` left behind                                   |
| `99999999999` | 2147483647 | true             | -1     | overflow stores the limit **and** fails            |
| (no input)    | -1         | true             | -1     | end of input: variable untouched                   |

Never judge a read by the value. Check the stream: `std::cin.fail()` or
`if (!(std::cin >> value))`.

## Recovery: clear() then ignore()

Input `abc` then `25`:

| Recovery                  | Second read      | Why                                      |
| ------------------------- | ---------------- | ---------------------------------------- |
| `clear()` + `ignore()`    | 25, fail = false | the bad line was discarded               |
| `clear()` only            | 0, fail = true   | the second read hit the same `abc` again |
| `ignore()` then `clear()` | 0, fail = true   | a failed stream skips `ignore()` too     |

`clear()` resets the state flags; `ignore()` discards the leftover characters.
`clear()` must come first.

## Final program behaviour

| Input                  | Result                                     | Exit |
| ---------------------- | ------------------------------------------ | ---- |
| `25`                   | Accepted: 25                               | 0    |
| `abc` then `25`        | recovers, Accepted: 25                     | 0    |
| `7xyz`                 | Accepted: 7 (partial input succeeds)       | 0    |
| `99999999999` then `5` | first read fails at the limit, Accepted: 5 | 0    |
| (no input)             | value stays -1, eof = true, gives up       | 1    |

## Common mistakes

| Mistake                      | Problem                                     | Fix                                |
| ---------------------------- | ------------------------------------------- | ---------------------------------- |
| Not checking the read        | Bad input silently becomes 0                | `if (!(std::cin >> value))`        |
| Checking the value (`== 0`)  | 0 is valid; failures can leave other values | Check the stream state             |
| `clear()` without `ignore()` | Reads the same bad text again               | `clear()`, then `ignore()`         |
| `ignore()` before `clear()`  | A failed stream skips `ignore()`            | `clear()` first                    |
| Assuming `42abc` fails       | The first read succeeds                     | Validate the whole line (Stage 04) |
| Never testing empty input    | Every read fails at end of input            | Test with `printf "" \| ./main`    |

## Key takeaway

A failed stream skips everything until `clear()`, and only the stream state, not
the value, tells you whether a read worked.

## Coming next

Re-asking until the input is valid needs a loop: Stage 02 · 13.

## Standard

C++23 (on conversion failure the value is set to 0, and on overflow to the type's
limit, since C++11).

## Compile and test

```bash
g++ -Wall -Wextra -Wpedantic -Wshadow=local -std=c++23 main.cpp -o main
printf "abc\n25\n" | ./main
printf "" | ./main
```