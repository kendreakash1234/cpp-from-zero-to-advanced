# 09 — Comments

Text written for humans that the compiler throws away before it compiles anything.

---

## What a comment is

A comment is text the compiler ignores. It never reaches the compiled binary —
there is no runtime cost, no size cost, nothing. Comments exist only for the
people reading the code.

## The two syntaxes

| Syntax      | Name          | Ends at |
| ---         | ---           | --- |
| `// ...`    | line comment  | end of the line |
| `/* ... */` | block comment | the first `*/` |

// a line comment

/*
   a block comment,
   spanning several lines
*/
cpp

// a line comment

/*
   a block comment,
   spanning several lines
*/

## When comments disappear

Comments are removed early in translation, before the preprocessor handles
`#include` and `#define`, and long before code generation.

They are not deleted — **each comment is replaced by a single space**. That
distinction matters, because it means a comment can act as a separator:

cpp
int/* hi */x = 5;   // the compiler sees: int x = 5;

If comments were deleted outright, that line would read `intx = 5;` and fail.

## Gotcha 1 — block comments do not nest

The **first** `*/` closes the comment, no matter how many `/*` opened it.

cpp
/*  outer
    /* inner */
    int x = 5;
*/


The comment ends at the `*/` on line 2. `int x = 5;` is live code again, and the
final `*/` is a stray token the compiler rejects.

So block comments are a poor tool for commenting out a region of code — if that
region already contains a block comment, you get an error.

**Use instead:**

cpp
// int x = 5;        // every editor has a shortcut for this


cpp
#if 0
    int x = 5;       // preprocessor skips the whole region; nests safely
#endif

## Gotcha 2 — `//` and `/*` inside a string literal are not comments

cpp
std::string url  = "https://example.com";   // the // is part of the string
std::string path = "/* not a comment */";   // so is this


The compiler recognises string literals first, so comment markers inside quotes
are just ordinary characters.

## Good comments explain *why*, not *what*

cpp
i = i + 1;      // BAD  — restates the code, adds nothing


cpp
retryCount++;   // GOOD — back off before the 3rd attempt; the API rate-limits us


Clear names already say *what* the code does. A comment earns its place by
capturing what the code cannot say for itself: intent, trade-offs, constraints,
and the reason a non-obvious choice was made.

If a comment is needed to explain *what* a line does, treat that as a hint to
rewrite the line more clearly instead. A comment that has to compensate for
confusing code will go stale — and a stale comment is worse than no comment,
because the compiler never checks it.

---

## What this program does

Reads an integer from standard input and prints it back. On invalid input, the
extraction fails, `std::cin` enters a failed state, and the variable is set to
`0` — which the program reports before printing.

The source in `main.cpp` is where this topic actually lives: it uses both
comment syntaxes and follows the *why, not what* rule throughout.

## Build & run

bash
g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main
./main

## Sample runs

Enter the number: 5
number: 5

Enter the number: df
Invalid input: expected integer
number: 0

## Key takeaway

Comments cost nothing at runtime and everything in maintenance. Write them for
the *why*; let the code speak for the *what*.