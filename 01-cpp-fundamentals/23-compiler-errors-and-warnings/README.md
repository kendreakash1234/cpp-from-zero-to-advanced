# 23 — Reading Compiler Errors and Warnings

## What is it?

A **diagnostic** is a message from the compiler about your code.

| Kind         | Meaning                                        | Builds?                |
| ------------ | ---------------------------------------------- | ---------------------- |
| error        | not valid C++                                  | no                     |
| warning      | valid C++, but probably a bug                  | yes, and the bug ships |
| note         | extra context, often containing the fix        | n/a                    |
| linker error | compiling worked, but the pieces don't connect | no                     |

## Anatomy of a diagnostic

```text
typo.cpp:5:18: error: 'cont' was not declared in this scope; did you mean 'count'?
    5 |     std::cout << cont << '\n';
      |                  ^~~~
      |                  count
```

| Part                    | Meaning                         |
| ----------------------- | ------------------------------- |
| `typo.cpp:5:18`         | file : line : column            |
| `error:`                | the kind                        |
| `did you mean …?`       | a suggestion, not always right  |
| `^~~~`                  | the caret: the exact characters |
| `count` under the caret | a fix-it hint                   |

## The method

1. Read the **first** error first; later errors are often caused by it.
2. Location, then message, then caret.
3. If the reported line looks fine, check the line **before** it.
4. Read the notes: they often contain the fix.
5. Treat suggestions as hints.
6. Rebuild after each fix.
7. Aim for zero warnings.

## Debug log: the broken program

Built with `cxx` after each single fix:

| Build | Fix applied                     | Errors | Warnings | What changed                                        |
| ----- | ------------------------------- | ------ | -------- | --------------------------------------------------- |
| 1     | (none)                          | 3      | 3        | `;` reported on line 6; `count` not declared        |
| 2     | add `;` after `int total{10}`   | 1      | 3        | the `count` error vanished: it was a cascade        |
| 3     | `totl` → `total`                | 0      | 2        | "unused variable 'total'" vanished: same root cause |
| 4     | signed `limit`, remove `unused` | 0      | 0        | clean                                               |

Two lessons from the log:

- One missing `;` caused two errors: `int count{2};` was swallowed into the broken
  statement, so `count` was never declared.
- One typo caused an error **and** a warning: with `totl`, the real `total` was
  never used.

## Other diagnostics

| Situation                      | Output                                                                                              |
| ------------------------------ | --------------------------------------------------------------------------------------------------- |
| missing `;` on line 3          | `error: expected ',' or ';' before 'return'` on line 4                                              |
| `std::strng`                   | `did you mean 'string'?`, then `'name' was not declared; did you mean 'tzname'?` (wrong suggestion) |
| missing `#include <iostream>`  | note: `did you forget to '#include <iostream>'?` with `+++ \|+#include <iostream>`                  |
| `int mian()` instead of `main` | `undefined reference to 'main'` / `collect2: error: ld returned 1 exit status`                      |
| warnings with `-Werror`        | `[-Werror=sign-compare]` … `all warnings being treated as errors`, no executable                    |

A linker error has no file or line: compilation succeeded, and the linker could
not find something it needed.

## Flags

| Flag             | Effect                             |
| ---------------- | ---------------------------------- |
| `-Wall -Wextra`  | the main warning sets              |
| `-Wpedantic`     | warn about non-standard extensions |
| `-Wshadow=local` | a local hiding another local       |
| `-Wconversion`   | lossy implicit conversions         |
| `-Werror`        | warnings become errors             |
| `-fmax-errors=1` | stop after the first error         |

## Stale binaries

A failed build does not delete the old executable. To test that a build really
fails:

```bash
rm -f main
cxx -Werror main.cpp -o main
ls main          # No such file or directory
```

## Common mistakes

| Mistake                             | Fix                                     |
| ----------------------------------- | --------------------------------------- |
| Fixing the last error first         | Start at the top                        |
| Staring at the reported line        | Check the line before it                |
| Ignoring warnings because it builds | Treat them as bugs; use `-Werror` in CI |
| Trusting every suggestion           | `tzname` was wrong                      |
| Reading a linker error as syntax    | `ld returned 1` means a missing piece   |
| Opening `main` in the editor        | That's the binary; edit `main.cpp`      |

## Key takeaway

Read the first error first, check the line above, read the notes, and keep the
build at zero warnings.

## Standard

C++23. Diagnostics shown are from GCC 13.

## Compile command

```bash
g++ -Wall -Wextra -Wpedantic -Wshadow=local -std=c++23 main.cpp -o main
```