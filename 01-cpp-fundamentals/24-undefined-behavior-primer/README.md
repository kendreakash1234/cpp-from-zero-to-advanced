# 24 — Undefined Behavior Red-Flag Primer

## What is it?

**Undefined behavior (UB)** is code for which the C++ standard places **no
requirements** on what happens: a plausible value, a crash, different results at
different optimization levels, or code that seems to work for years.

## Why does it exist?

For speed and portability: C++ does not check every addition or index. The
programmer promises the program never does these things, and the compiler is
allowed to rely on that promise.

## The five Stage 01 red flags

Each one tested with three builds (GCC 13); `cxxt` combines all the tools.

| Red flag                  | `cxx`                           | UBSan + float-cast-overflow                                          | `-D_GLIBCXX_ASSERTIONS`                   |
| ------------------------- | ------------------------------- | -------------------------------------------------------------------- | ----------------------------------------- |
| `int count;` then read it | **warning: used uninitialized** | silent (printed 29538)                                               | warning only                              |
| `big + 1` (int)           | silent, -2147483648             | **signed integer overflow**                                          | silent                                    |
| `10 / divisor` (0)        | crash                           | **division by zero**, then crash                                     | crash                                     |
| `static_cast<int>(1e20)`  | silent, -2147483648             | **1e+20 is outside the range of representable values of type 'int'** | silent                                    |
| `values[3]` on 3 elements | silent, printed 0               | silent                                                               | **Assertion '__n < this->size()' failed** |

No single tool caught everything. One crash (the division) also hid the next two
red flags until that line was commented out.

## The surprise: same question, two answers

With input `2147483647`:

| Code                              | Result | Why                                                          |
| --------------------------------- | ------ | ------------------------------------------------------------ |
| `x + 1 > x`                       | true   | the compiler assumed no overflow and replaced it with `true` |
| `const int next{x + 1}; next > x` | false  | the addition ran and wrapped to -2147483648                  |

UBSan reported only the second: in the first, the compiler had removed the
addition, so there was nothing left to check at run time. **A sanitizer checks
the program the compiler built, not the code you wrote.**

## The fixes

| Red flag           | Fix                                                       |
| ------------------ | --------------------------------------------------------- |
| uninitialized read | `int count{};`                                            |
| signed overflow    | `long long` (not `long`: it is 4 bytes on 64-bit Windows) |
| division by zero   | check `divisor != 0` **before** dividing                  |
| float to int       | check the range with `std::numeric_limits<int>` first     |
| out of bounds      | a valid index, or `.at()` to report a bad one             |

A fix must **handle** the dangerous case, not remove the operation:
`static_cast<double>(huge)` "fixes" nothing, because it no longer converts to
`int` at all.

## Test alias

```bash
alias cxxt='g++ -Wall -Wextra -Wpedantic -Wshadow=local -std=c++23 -g -fsanitize=undefined,float-cast-overflow -D_GLIBCXX_ASSERTIONS'
```

`cxx` for everyday builds, `cxxt` for test builds.

## Example output

Built with `cxxt`: no warnings, no runtime errors.

```text
count:      0
big + 1:    2147483648
10 / divisor: refused, divisor is 0
huge as int: refused, 1e+20 does not fit int
last value: 3
```

## Common mistakes

| Mistake                               | Fix                                         |
| ------------------------------------- | ------------------------------------------- |
| "It printed the right answer"         | UB can change with any compiler or flag     |
| Relying on signed overflow wrapping   | It can be optimized away entirely           |
| Trusting one tool                     | Zero warnings **and** sanitizer test builds |
| Checking overflow after it happened   | Compare before the operation                |
| "Fixing" UB by removing the operation | Guard it so the program still does its job  |

## Key takeaway

UB is a broken promise to the compiler. Catch it with warnings, sanitizers, and
library assertions together, and fix it by guarding the dangerous case.

## Standard

C++23. Formal UB, implementation-defined, and unspecified behavior: Stage 15.

## Compile commands

```bash
g++ -Wall -Wextra -Wpedantic -Wshadow=local -std=c++23 main.cpp -o main
g++ -Wall -Wextra -Wpedantic -Wshadow=local -std=c++23 -g -fsanitize=undefined,float-cast-overflow -D_GLIBCXX_ASSERTIONS main.cpp -o main
```