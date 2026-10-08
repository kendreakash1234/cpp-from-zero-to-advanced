# 20 — Block Scope

## What is it?

A **block** is code between `{` and `}`. A variable defined inside a block has
**block scope**: its name can be used from its definition to the closing brace of
that block, and nowhere else.

## Why does it matter?

Scope limits where a name is visible, so variables cannot be misused far from
where they belong. In C++, a local variable's **lifetime** also ends at its
block's `}`, which is the foundation of RAII (Stage 12).

## Rules

Tested with `cxx` (GCC 13, `-std=c++23`):

| Code                       | Result                                    |
| -------------------------- | ----------------------------------------- |
| `{ int y{2}; } y = 3;`     | error: 'y' was not declared in this scope |
| `w = 5; int w{};`          | error: 'w' was not declared in this scope |
| `int z{1}; int z{2};`      | error: redeclaration of 'int z'           |
| `int x{1}; { x = 2; }`     | allowed: inner blocks see outer names     |
| `int x{1}; { int x{10}; }` | allowed: shadowing, a separate object     |

## Shadowing

```cpp
int count{0};
{
    count = 5;          // changes the outer count
    int count{9};       // a new count hides the outer one from here on
}
// outer count is 5
```

Output: `5`, `9`, `5`. The inner `count` is a separate object; the outer one is
only hidden, never changed by it.

Shadowing compiles **without a warning** under `-Wall -Wextra -Wpedantic`:

| Build            | Result                                                   |
| ---------------- | -------------------------------------------------------- |
| `cxx`            | no warning                                               |
| `cxx -Wshadow`   | warning: declaration of 'count' shadows a previous local |
| `-Wshadow=local` | same warning, reported as `-Wshadow=compatible-local`    |

`-Wshadow=local` was added to the `cxx` alias: it reports one local hiding another
without the noise full `-Wshadow` produces later with class members.

## Scope vs lifetime

| Concept  | Meaning                  | When         |
| -------- | ------------------------ | ------------ |
| Scope    | where a name can be used | compile time |
| Lifetime | when an object exists    | run time     |

For local variables both end at the same `}`; they diverge later (static locals,
dynamic memory).

## Example output

```text
outer count at start:  0
after count = 5 inside: 5
inner temporary:        42
outer count at end:    5
```

## Common mistakes

| Mistake                             | Problem                        | Fix                                  |
| ----------------------------------- | ------------------------------ | ------------------------------------ |
| Using a variable after its block    | Its scope ended at `}`         | Define it in the block that needs it |
| `int total{5};` meant as assignment | Silent shadowing               | Build with `-Wshadow=local`          |
| Using a name before its definition  | Scope starts at the definition | Define first                         |
| Two definitions in one block        | Redeclaration error            | Assign instead                       |
| All variables at the top            | Larger scope than needed       | Smallest scope, closest to first use |

## Key takeaway

A name lives from its definition to its block's closing brace. Keep scopes small,
and let the compiler report shadowing.

## Standard

C++23 (block scope rules are unchanged since the first standard).

## Compile command

```bash
g++ -Wall -Wextra -Wpedantic -Wshadow=local -std=c++23 main.cpp -o main
```