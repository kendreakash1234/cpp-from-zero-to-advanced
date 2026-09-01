# Statements

## What is a Statement?

A **statement** is a complete instruction that tells a C++ program to perform an action.

Statements are the individual instructions that make up the executable part of a program.

A statement usually ends with a semicolon (`;`), although some statements such as `if`, `while`, and blocks have different syntax.

---

## Expression vs Statement

An important distinction is:

* **Expression** → produces a value.
* **Statement** → represents a complete instruction/action.

For example, an expression can calculate a value, while a statement can use that value to perform an operation such as assigning it to a variable.

A statement can contain one or more expressions.

### Simple mental model

**Expression → produces a value**

**Statement → tells the program to do something**

This distinction is important because expressions and statements are related, but they are not the same thing.

---

## What I Learned

I learned that a C++ program is made up of statements that are executed as instructions.

I also learned how expressions can be part of statements.

For example, an addition expression can calculate a value, and an assignment statement can store that value in a variable.

I practiced changing a variable's value and then using the updated value in another statement.

---

## Practical Exercise

I created a small C++ program that:

1. Declares two integer variables.
2. Assigns values to them.
3. Calculates their sum.
4. Stores the result.
5. Displays the result.
6. Changes one variable.
7. Calculates the sum again.
8. Displays the new result.

The program produced:

* First result: `30`
* Second result: `50`

This demonstrated that statements are executed as instructions and that later statements can work with values changed by earlier statements.

---

## Key Concepts

### 1. Statement

A complete instruction in a C++ program.

### 2. Expression

A construct that can be evaluated to produce a value.

### 3. Expression inside a Statement

Statements often use expressions to perform their work.

### 4. Statement Execution

Statements are executed as part of the program's flow, allowing the program to perform actions in sequence.

### 5. Semicolon

Many C++ statements end with `;`. It marks the end of the statement.

---

## Important Understanding

The most important distinction from this exercise is:

**Expressions produce values; statements perform complete instructions.**

For example:

**Expression**

`num1 + num2`

produces a value.

**Statement**

`result = num1 + num2;`

is a complete instruction that uses the expression's value and assigns it to `result`.

---

## What I Practiced

* Identifying expressions and statements.
* Understanding the difference between an expression and a statement.
* Using expressions inside statements.
* Executing multiple statements sequentially.
* Changing a variable and using its updated value in later statements.
* Compiling and testing the program with G++.

---

## Compilation

The program was compiled using:

`g++ -std=c++17 -Wall -Wextra -Wpedantic`

The program compiled successfully without warnings and produced the expected output.

---

## Key Takeaway

A C++ program is built from instructions called **statements**.

Expressions provide the values that many statements work with.

Understanding the relationship between:

**Expression → Value → Statement → Action**

is an important part of building a strong C++ programming foundation.

---

## Status

**Topic completed:** Statements

**Understanding:** I can distinguish an expression from a statement and explain how expressions can be used within statements.
