# 08 — Nested Loops

## What is it?

A loop inside another loop's body. For **each** run of the outer loop, the inner
loop runs **completely**, restarting from its init. The inner body runs
outer × inner times.

## Patterns

| Pattern          | Inner loop        | Runs for n = 4 |
| ---------------- | ----------------- | -------------- |
| full grid        | `j` from 1 to n   | n × n = 16     |
| triangle         | `j` from 1 to `i` | 1+2+3+4 = 10   |
| every pair, once | `j` from `i + 1`  | 4 × 3 / 2 = 6  |

Starting the pair loop at `i + 1` avoids comparing an element with itself and
checking each pair twice.

## Results

Tested with `cxx` (GCC 13):

| Input | Grid runs     | Triangle runs | Exit |
| ----- | ------------- | ------------- | ---- |
| `3`   | 9             | 6             | 0    |
| `1`   | 1             | 1             | 0    |
| `9`   | 81            | 45            | 0    |
| `0`   | invalid input |               | 1    |
| `10`  | invalid input |               | 1    |
| `abc` | invalid input |               | 1    |

From n = 3 to n = 9 the input is 3 times bigger, but the grid does 9 times more
work (9 to 81): nesting multiplies cost.

## Exiting both loops

First pair summing to 10 in `{3, 7, 1, 6, 4}`:

| Version                                 | Pairs checked | Found                     |
| --------------------------------------- | ------------- | ------------------------- |
| inner `break` only                      | 7             | `3 + 7`, then `6 + 4` too |
| `break` + `&& !found` in the outer loop | 1             | `3 + 7`                   |

`break` leaves only the inner loop. The flag carries the result out so the outer
condition stops as well. (In Stage 03, a function with `return` is cleaner.)

## Traps

| Code                                                  | Result                                               |
| ----------------------------------------------------- | ---------------------------------------------------- |
| `for (int j{0}; j < 3; ++i)` inside an outer `i` loop | hangs (exit 124), no warning: `j` never changes      |
| `for (int i...)` inside `for (int i...)`              | warning: declaration of 'i' shadows a previous local |
| outer loop without `&& !found`                        | keeps searching after the first match                |
| inner loop starting at 0 for pairs                    | self-pairs and every pair twice                      |

## Best practices

- Name counters by meaning (`row`, `col`) so a wrong update stands out.
- Each loop updates only its own counter.
- Count the inner runs before nesting on real data sizes.
- Use a flag (or later `return`) to stop all levels.
- Start pair loops at `i + 1`.

## Key takeaway

The inner loop restarts for every outer run, so work multiplies. break leaves one
level: carry the result out with a flag.

## Standard

C++23.