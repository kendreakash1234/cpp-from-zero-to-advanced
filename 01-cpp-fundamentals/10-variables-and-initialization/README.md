# 10 — Variables and Initialization

## What is it?

A **variable** is a named object: storage with a **type** that holds a **value**.

**Initialization** gives an object its first value at the moment it is created.
**Assignment** replaces the value of an object that already exists.

## Why does it matter?

C++ does not zero local variables automatically. A local variable without an
initializer holds an **indeterminate value**, and **reading it is undefined
behavior**. Initializing every variable when it is defined keeps the program in a
known, valid state.

## Initialization forms

| Form                       | Syntax        | Result for `int`                 | Allows narrowing? |
| Direct-list-initialization | `int x{10};`  | 10                               | No: compile error |
| Copy-initialization        | `int x = 10;` | 10                               | Yes, silently |
| Direct-initialization      | `int x(10);`  | 10                               | Yes, silently |
| Value-initialization       | `int x{};`    | 0 (guaranteed)                   | — |
| Default-initialization     | `int x;`      | Local: indeterminate. Global: 0  | — |

Prefer braces: they reject narrowing, and `{}` guarantees zero.

## Example

cpp
int width{10};    // direct-list-initialization (preferred)
int height = 20;  // copy-initialization
int depth(30);    // direct-initialization
int count{};      // value-initialization: guaranteed to be 0


Output:

text
direct-list-initialization: 10
copy-initialization:        20
direct-initialization:      30
value-initialization:       0


## How the program works

Each variable is created with a value at its definition, so every read in
`std::cout` is well-defined. The commented-out lines show three traps; uncomment
one at a time to see the compiler's response.

## Common mistakes

| Mistake                       | Problem                            | Fix                                              |
|---|---|---|
| `int total;` then reading it  | Undefined behavior                 | `int total{};`                                   |
| `int a, b = 0;`               | Only `b` is initialized            | One variable per definition                      |
| `int value();`                | Declares a function (vexing parse) | `int value{};`                                   |
| `int n = 3.9;`                | Silently stores 3 (truncation)     | `int n{3.9};` is rejected by the compiler        |
| Defining the same name twice in one scope | Redefinition error     | Define once; use assignment to change the value  |

## UB watch

Reading an uninitialized local variable is undefined behavior. In practice, the
same program printed `32766` when built with `-O0` and `0` with `-O2`. Neither
value is meaningful, and a result of `0` does not mean the variable was zeroed.

C++26 reclassifies this read as *erroneous behavior*. It is still a bug.

## Key takeaway

Initialize every variable when you define it, and prefer brace initialization.

## Standard

C++23 (brace initialization was introduced in C++11).

## Compile command

bash
g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main
