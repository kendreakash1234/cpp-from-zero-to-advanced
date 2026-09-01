# Expressions

## Overview

This section introduces the fundamental concept of an **expression** in programming and C++.

The goal is to understand what an expression actually is before learning the different types of expressions.

---

## What is an Expression?

An **expression** is something in a program that can be evaluated to produce a **value**.

A simple example is:

```cpp
5 + 3
```

When this expression is evaluated, it produces the value:

```text
8
```

Conceptually:

```text
Expression
    ↓
Evaluation
    ↓
Value
```

For example:

```text
5 + 3
  ↓
  8
```

The expression and the resulting value are different concepts:

* `5 + 3` → expression
* `8` → value produced by the expression

---

## Expressions in C++

C++ uses expressions throughout programs to work with values.

For example:

```cpp
5
```

can be an expression that produces the value `5`.

A variable name can also be used as an expression.

For example:

```cpp
int score{29};
```

When `score` is used in a value-producing context:

```cpp
score
```

it can be evaluated to obtain the current value of the object:

```text
score
  ↓
29
```

Therefore, an important idea is:

> A variable name can be used as an expression.

---

## Why Do Expressions Exist?

Programs need to work with data and produce values during processing.

Expressions provide a way to describe operations or refer to existing data so that the program can obtain a value.

For example:

```cpp
first_value + second_value
```

uses existing values and produces another value.

Conceptually:

```text
first_value + second_value
          ↓
       evaluation
          ↓
          30
```

Expressions therefore form an important part of how programs process and work with data.

---

## Expression vs Value

It is important to distinguish between an **expression** and a **value**.

### Expression

An expression is something that can be evaluated to produce a value.

Example:

```cpp
5 + 3
```

### Value

A value is the actual data produced or held by an object.

Example:

```text
8
```

So:

```text
5 + 3 → expression
8     → resulting value
```

The expression describes what is evaluated, while the value is the result obtained from that evaluation.

---

## Value vs Variable vs Expression

### Value

A value is the actual data.

For example:

```text
10
20
29
50
```

These are values.

### Variable

A variable is a name associated with an object that has a value.

For example:

```cpp
int score{50};
```

Here:

```text
score → variable/name
50    → value
```

This is a beginner-level explanation. A more precise understanding of objects, names, and storage will be developed later in the learning journey.

### Expression

An expression is something that can be evaluated to produce a value.

For example:

```cpp
score
```

When `score` currently has the value `50`, using `score` as an expression can produce/access the value `50`.

---

## Practical Example

The following program was written and tested as part of this lesson:

```cpp
#include <iostream>

int main()
{
    int first_value = 10;
    int second_value = 20;

    int result{};

    result = first_value + second_value;

    std::cout << "Value " << result << "\n";

    return 0;
}
```

### How It Works

First, two variables are created:

```cpp
int first_value = 10;
int second_value = 20;
```

Their current values are:

```text
first_value  → 10
second_value → 20
```

The expression:

```cpp
first_value + second_value
```

uses those values.

Conceptually:

```text
first_value + second_value
        ↓
      10 + 20
        ↓
        30
```

Therefore, the expression produces the value:

```text
30
```

That resulting value is then used by the program when assigning to `result`.

After the assignment:

```text
result → 30
```

The program then prints the value of `result`.

---

## Variable Names as Expressions

A variable name can be used as an expression.

For example:

```cpp
int score{29};
```

When we use:

```cpp
score
```

as an expression, it can be evaluated to obtain the current value:

```text
score
  ↓
29
```

Similarly, in the practical example:

```cpp
first_value
```

and:

```cpp
second_value
```

can be used as expressions when they are used to provide their current values.

The larger expression:

```cpp
first_value + second_value
```

combines them and produces:

```text
30
```

---

## Important Learning Points

* An expression can be evaluated to produce a value.
* An expression and its resulting value are different concepts.
* `5 + 3` is an expression.
* Evaluating `5 + 3` produces the value `8`.
* A variable name can be used as an expression.
* If `score` currently has the value `29`, using `score` as an expression can produce/access that value.
* `first_value + second_value` is an expression.
* If `first_value` is `10` and `second_value` is `20`, the expression produces the value `30`.
* Expressions can use values and variables.
* Expressions can be combined to form larger expressions.

---

## Compiler and Testing

The program was compiled using C++17 with strict compiler warnings:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o main
```

The program was then executed with:

```bash
./main
```

### Output

```text
Value 30
```

The program compiled successfully and produced the expected output.

---

## Key Concept

The main idea learned in this lesson is:

```text
Expression
    ↓
Evaluation
    ↓
Value
```

For example:

```text
5 + 3
  ↓
  8
```

And with variables:

```text
first_value + second_value
          ↓
        10 + 20
          ↓
          30
```

### In one sentence

> An expression is something that can be evaluated to produce a value.

---

## Precision Note

The beginner-level explanation used here is:

> A variable is a name associated with data/value.

This is useful for understanding the basic idea at this stage.

A more precise explanation of variables, objects, names, storage, and related C++ concepts will be introduced later when those concepts are part of the roadmap.

The goal of this lesson is only to establish the fundamental concept of expressions.

---

## Learning Status

**Stage:** 00 — Programming Basics

**Topic:** Expressions

**Subtopic:** What is an expression?

**Status:** Completed

**Understanding:** 9/10

### What I can explain now

I can explain:

* what an expression is
* that an expression is evaluated to produce a value
* the difference between an expression and a value
* the difference between a value and a variable
* how a variable name can be used as an expression
* how `first_value + second_value` produces the value `30`

The different types/categories of expressions will be learned separately as part of the roadmap.
