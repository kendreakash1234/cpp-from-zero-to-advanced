# Conditions

## What I Learned

A **condition** is an expression that is evaluated to determine a `true` or `false` outcome.

C++ uses `if` and `else` to make decisions based on that outcome.

```cpp
if (condition)
{
    // runs when condition is true
}
else
{
    // runs when condition is false
}
```

### Example

```cpp
int temperature{};

std::cin >> temperature;

if (temperature > 30)
{
    std::cout << "Hot\n";
}
else
{
    std::cout << "Not hot\n";
}
```

For:

```text
temperature = 8
```

the condition is false, so the `else` block executes:

```text
Not hot
```

For:

```text
temperature = 984
```

the condition is true, so the `if` block executes:

```text
Hot
```

I also practiced checking invalid integer input and tested a condition with positive, negative, and zero values.

One important mistake I encountered was accidentally writing:

```cpp
if (number = -14)
```

This performs an assignment instead of checking a condition, and the compiler warned me about using an assignment as a truth value.

## Key Takeaway

```text
Condition
    ↓
Evaluate
    ↓
true / false
    ↓
Decision
    ↓
Execute the appropriate block
```

**Main understanding:** A condition is an expression evaluated to determine a true/false outcome, which allows a program to make a decision.

## Compilation

```bash
g++ main.cpp -o main
```

Warnings:

```bash
g++ -Wall main.cpp -o main
```
