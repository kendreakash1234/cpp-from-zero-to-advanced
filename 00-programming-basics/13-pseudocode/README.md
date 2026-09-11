# Pseudocode

## Definition

Pseudocode is a clear, language-independent description of the steps in an algorithm. It is written for people to understand, not for a compiler to execute.

## Why it matters

Pseudocode separates problem-solving from programming-language syntax. It lets me organize the required input, processing, decisions, and output before translating the solution into C++17.

The general process is:

```text
Problem → Pseudocode → C++17 code
```

This can expose missing cases or incorrect logic before I spend time debugging source code.

## Basic structure

Pseudocode has no single official syntax, but it should be clear and consistent.

```text
START

INPUT value

IF condition THEN
    OUTPUT result
ELSE
    OUTPUT another result
END IF

STOP
```

Common instructions include:

- `START` and `STOP` to show the algorithm's boundaries
- `INPUT` to receive data
- `SET` to store or update a value
- `IF`, `ELSE IF`, and `ELSE` to make decisions
- `OUTPUT` to produce a result

## Example

Problem: Read one integer and report whether it is positive, negative, or zero.

```text
START

INPUT number

IF number < 0 THEN
    OUTPUT "Negative"
ELSE IF number > 0 THEN
    OUTPUT "Positive"
ELSE
    OUTPUT "Zero"
END IF

STOP
```

The first condition handles negative integers. If it is false, the second condition checks for a positive integer. If both conditions are false, the integer must be zero.

## C++17 translation

```cpp
if (number < 0)
{
    std::cout << number << " is negative.\n";
}
else if (number > 0)
{
    std::cout << number << " is positive.\n";
}
else
{
    std::cout << "The number is zero.\n";
}
```

The syntax changes during translation, but the algorithm remains the same.

## Common mistakes

- Writing vague instructions that cannot be implemented
- Using values that were never introduced by an input step
- Forgetting one possible branch of a decision
- Using conditions that fail when values are equal
- Mixing inconsistent pseudocode styles
- Treating pseudocode as compilable C++
- Adding unnecessary C++ implementation details too early

## Key takeaway

Pseudocode helps me convert a problem into precise logical steps before translating those steps into clean C++17 code.