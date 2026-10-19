# 01 — Function Declaration, Definition, and Call

## What is it?

A function is a named block of code that does one job. You define it once and call
it wherever that job is needed.

| Term        | What it is                   | Example                               |
| ----------- | ---------------------------- | ------------------------------------- |
| declaration | introduces the name and type | `int square(int x);`                  |
| definition  | a declaration plus the body  | `int square(int x) { return x * x; }` |
| call        | runs the function            | `square(7)`                           |

Every definition is also a declaration.

## Syntax

```cpp
returnType name(parameters)
{
    // body
    return value;   // gives the value back AND leaves the function
}
```

C++ compiles top to bottom: a function must be declared before its first call.

## What a call does

1. The argument is placed where the function expects it (usually a register).
2. The return address is saved, and execution jumps to the function.
3. A stack frame holds the function's local variables.
4. The body runs; the result goes in a register.
5. The frame is discarded, and execution continues after the call.

Small functions are often inlined by the optimizer, so the call costs nothing.

## Results

Tested with `cxx` (GCC 13), one loop calling each function for every value:

| Value        | `isPrime` | `countDigits` | `sign` |
| ------------ | --------- | ------------- | ------ |
| `0`          | false     | 1             | 0      |
| `1`          | false     | 1             | 1      |
| `2`          | true      | 1             | 1      |
| `97`         | true      | 2             | 1      |
| `121`        | false     | 3             | 1      |
| `-45`        | false     | 2             | -1     |
| `2147483647` | true      | 10            | 1      |

## Mistakes and what the compiler says

| Mistake                         | Result  | Message                                                 |
| ------------------------------- | ------- | ------------------------------------------------------- |
| call before the definition      | error   | 'twice' was not declared in this scope                  |
| missing return on one path      | warning | control reaches end of non-void function                |
| `greet;` without parentheses    | warning | statement is a reference, not call, to function 'greet' |
| function defined inside another | error   | a function-definition is not allowed here               |
| same function defined twice     | error   | redefinition of 'int f()'                               |
| return value ignored            | silent  | (no warning)                                            |

## UB watch: the missing return

`int sign(int x)` returning only for `x > 0`, then `sign(-5)`:

| Build  | Result                                                                                           |
| ------ | ------------------------------------------------------------------------------------------------ |
| `cxx`  | Illegal instruction (core dumped)                                                                |
| `cxxt` | runtime error: execution reached the end of a value-returning function without returning a value |

GCC places a trap where a non-void function falls off its end. Other compilers or
settings may silently return garbage instead. Every path must return a value.

## Formatting

From this stage, every file is formatted with `clang-format` using the repo's
`.clang-format` (4 spaces, function braces on their own line):

```bash
clang-format -i main.cpp
clang-format --dry-run --Werror main.cpp   # no output = formatted
```

## Key takeaway

Define before you call, return on every path, and remember that `return` also
leaves the function.

## Standard

C++23 (function rules unchanged since C++98).