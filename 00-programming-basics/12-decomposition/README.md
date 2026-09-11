# Breaking a Problem Into Smaller Problems (Decomposition)

**Module:** BASICS · 12
**Standard:** C++17

---

## Definition
Decomposition is the skill of taking one big, fuzzy problem and splitting it
into small, clearly-defined sub-problems that are each easy to solve on their
own. You solve the small pieces, then combine them.

In C++, each sub-problem usually becomes its own **function** — a named,
self-contained piece that does exactly one thing.

---

## Why it matters
- Human working memory is small — you can only focus on one small thing at a time.
- Small functions are **readable, reusable, and testable**.
- Bugs stay **isolated**: you can test `isPrime()` without touching input or output.
- The opposite (everything crammed into `main()`) becomes tangled and hard to debug.

---

## Real-life analogy
You never "make dinner" in one step. You:

buy  ->  chop  ->  cook  ->  serve

Four small, checkable steps. Code works exactly the same way.

---

## The method
1. State the goal in one sentence.
2. Break it into major steps.
3. For each step ask: "Can I solve this directly?" If not, break it down further.
4. Solve each smallest piece (a function).
5. Combine the pieces in order.

---

## Syntax (a sub-problem as a function)
    returnType functionName(parameters) {
        // solves ONE sub-problem
        return result;
    }

---

## Examples
Two small, **separate** programs — each decomposed into functions.
(Key point: unrelated problems belong in separate programs, not one `main()`.)

**Rectangle tool**
getInput() -> validate() -> calcArea() / calcPerimeter() -> print()

**Prime check**
read number -> isPrime() -> print result

Each `main()` ends up reading like the plan itself: input -> validate ->
calculate -> output.

---

## Common mistakes
- Writing everything inside `main()`.
- Bundling **unrelated** problems (e.g. area + prime) into one `main()`.
- A "sub-problem" that secretly does 3 things (needs further breaking down).
- Using `<` instead of `<=` in `i * i <= x` — misses perfect squares (9, 25, 49).
- Reading a `double` and forcing it into an `int` (silent narrowing).
- Naming a validator so `true` is ambiguous — prefer `isValidDimension()`.

---

## Build & run
    g++ -Wall -Wextra -std=c++17 main.cpp -o main
    ./main

---

## Key takeaway
Break the problem down first -> one responsibility per function -> readable,
testable, debuggable code.