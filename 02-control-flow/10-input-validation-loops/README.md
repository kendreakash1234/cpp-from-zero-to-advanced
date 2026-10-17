# 10 — Input Validation Loops

## What is it?

A loop that keeps asking until the input is valid, and only then lets the program
continue. It combines `std::cin` reads, `clear()`, `ignore()`, guards, loops, and `break`.

## The three exits

| Exit                 | When                              | Result                              |
| -------------------- | --------------------------------- | ----------------------------------- |
| 1. valid input       | the read succeeds and is in range | continue with the value             |
| 2. end of input      | `std::cin.eof()` is true          | `no more input`, exit 1             |
| 3. too many attempts | the attempt limit is reached      | `too many invalid attempts`, exit 1 |

"not a number", "out of range", and "trailing characters" are retries, not exits.

## The order inside the loop

1. Read. On success: check trailing characters (`peek()`), then the range.
2. On failure: check `eof()` first (exit 2), otherwise report and `clear()`.
3. On every retry path: `ignore()` the rest of the line, so each attempt starts fresh.

`clear()` must come before `ignore()`: a failed stream skips `ignore()` too.

## Menu results

Tested with `cxx` (GCC 13), input piped with `printf`:

| Input            | Attempts                             | Result                    | Exit |
| ---------------- | ------------------------------------ | ------------------------- | ---- |
| `2`              | accepted                             | Subtract                  | 0    |
| `abc` `9` `4`    | not a number, out of range, accepted | Quit                      | 0    |
| `x` `y` `z`      | not a number ×3                      | too many invalid attempts | 1    |
| `abc` (then end) | not a number, then end of input      | no more input             | 1    |
| (empty)          | end of input                         | no more input             | 1    |
| `0` `5` `1`      | out of range, out of range, accepted | Add                       | 0    |
| `2x` `3`         | trailing characters, accepted        | Multiply                  | 0    |

`0 5 1` is the boundary test: a first version used `choice >= 0` and accepted 0.

## Why the classic loop is not enough

```cpp
while (!(std::cin >> x)) { std::cin.clear(); std::cin.ignore(...); }
```

| Input                  | Result                                   |
| ---------------------- | ---------------------------------------- |
| `abc`, then `7`        | prints 7                                 |
| `abc`, then input ends | hangs forever: `timeout 2` gave exit 124 |

Typing at the keyboard hides the bug, because there is always more input coming.
Piped input or Ctrl+D exposes it.

## Traps

| Mistake                      | Result                                                       |
| ---------------------------- | ------------------------------------------------------------ |
| no `eof()` check             | infinite loop when the input ends                            |
| `clear()` without `ignore()` | `abc` then `2`: all 3 attempts reread `abc`; 2 never reached |
| `ignore()` before `clear()`  | the failed stream skips `ignore()`                           |
| no attempt limit             | bad scripted input loops forever                             |
| type checked, range not      | `200` is a valid `int`, not a valid age                      |
| no trailing check            | `2x` accepted as 2                                           |

## Testing note

Escaping C++ through `printf` is fragile: `'\\n'` produced a multi-character
constant. Write test files with a quoted heredoc (`cat > a.cpp << 'EOF'`).

## Best practices

- Three exits: valid, end of input, attempt limit.
- `clear()` before `ignore()`; `ignore()` on every retry path.
- Validate the type, the range, and trailing characters.
- Test with piped input, including input that ends early.
- Final errors to `std::cerr`, with a non-zero exit code.

## Key takeaway

Re-prompt until valid, but always have a way out: the user may stop typing, and
the input may simply end.

## Standard

C++23.