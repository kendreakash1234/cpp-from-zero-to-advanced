# 11 — Functions as Reusable Logic

## Definition
A **function** is a named block of code that performs one task. You **define** it
once and **call** it by name whenever needed. It can take **inputs** (parameters)
and return an **output** (a return value).

## Why it matters
Functions let you write logic once and reuse it — the DRY principle
(Don't Repeat Yourself). They break big problems into small, named, testable
pieces and provide **abstraction**: you can use a function without knowing how it
works internally (e.g. `std::sqrt`).

## Syntax
```cpp
return_type name(parameter_list) {
    // body
    return value;   // omit/return nothing when return_type is void
}
```
- **return type** — type of the value handed back (`void` = nothing).
- **parameters** — typed inputs.
- **return** — sends a value back and ends the function.

## Parameter vs argument
- **Parameter**: the variable in the definition — `int add(int a, int b)`.
- **Argument**: the value passed at the call — `add(3, 5)`.
- C++ passes arguments **by value**: the function works on a copy.

## Example
```cpp
bool isEven(int n) {
    return n % 2 == 0;   // a comparison already yields a bool
}

if (isEven(4)) std::cout << "Even\n";
```

## Common mistakes
- Forgetting to `return` from a non-void function (undefined behavior).
- Calling a function before it is declared (define above `main`, or use a prototype).
- Confusing `void` ("returns nothing") with "takes no inputs".
- Returning `true`/`false` from an `if` when the condition is already a bool.
- Integer overflow: `int factorial(int)` breaks beyond 12! — know the limit.

## Key takeaway
```
define once  →  call by name (pass arguments)  →  run body  →  return a value
```
Compiled with: `g++ -Wall -Wextra -std=c++17 main.cpp -o main`