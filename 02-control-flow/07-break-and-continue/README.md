# 07 — break and continue

## What is it?

| Statement  | Effect                                               |
| ---------- | ---------------------------------------------------- |
| `break`    | leave the innermost loop **or `switch`** immediately |
| `continue` | skip the rest of this run; go to the next one        |

## Where continue jumps

| Loop              | After `continue`                                |
| ----------------- | ----------------------------------------------- |
| classic `for`     | the update (`++i`), then the condition          |
| range-based `for` | the next element                                |
| `while`           | the condition: code below `continue` is skipped |
| `do while`        | the condition at the bottom                     |

## Score filter results

Negatives skipped with `continue`; the first score above 100 stops the loop with
`break`. Tested with `cxx` (GCC 13); every prediction matched:

| Input         | Accepted | Sum | Negatives | Ended           |
| ------------- | -------- | --- | --------- | --------------- |
| `10 20 30`    | 3        | 60  | 0         | reached the end |
| `10 -5 20`    | 2        | 30  | 1         | reached the end |
| `10 150 20`   | 1        | 10  | 0         | stopped at 150  |
| `-1 -2`       | 0        | 0   | 2         | reached the end |
| (empty)       | 0        | 0   | 0         | reached the end |
| `50 -3 200 7` | 1        | 50  | 1         | stopped at 200  |

`stoppedEarly` records why the loop ended: after a `break`, the code below the
loop cannot otherwise tell.

## Traps

| Code                                                            | Result                                                        |
| --------------------------------------------------------------- | ------------------------------------------------------------- |
| `while (x > 0) { print; if (x == 8) { continue; } x--; }`       | printed `x = 8` forever: `continue` skipped `x--`, no warning |
| the same with `x--` before `continue`                           | `8 7 6 5 4 3 2 1 0`                                           |
| `switch` with `break` inside a `for` loop                       | the loop kept running: `break` left only the `switch`         |
| `do { ++i; if (i == 2) { continue; } print i; } while (i < 3);` | `1 3`: continue jumps to the condition                        |
| `break;` outside a loop or switch                               | error: break statement not within loop or switch              |

## Best practices

- Put `continue` guards at the top of the body, like guard clauses.
- In a `while` loop, update before any `continue`, or use a `for` loop.
- To leave a loop from inside a `switch`, use a flag, a `return`, or restructure.
- Record whether a search loop found something.
- Avoid many scattered `continue`s in a long body.

## Key takeaway

`break` leaves the innermost loop or switch; `continue` skips to the next run, and
in a `while` loop it skips your update too.

## Standard

C++23 (both statements unchanged since the first standard).