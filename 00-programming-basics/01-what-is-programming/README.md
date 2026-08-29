# BASICS · 01 — What is Programming?

**Category:** BASICS
**Topic:** What is Programming?
**Date:** 29 August 2026

## What I Learned

Programming is the process of solving a problem by expressing a solution as a sequence of instructions that can be understood and executed by a computer.

I learned that programming is not just about writing code. Before writing code, we need to understand the problem and think about how to solve it.

A useful mental model I learned today is:

```text
Problem
   ↓
Solution / Algorithm
   ↓
Program
   ↓
Execution
   ↓
Result
```

For example, if the problem is to determine whether someone is eligible to drive based on their age, I can first describe the solution in plain English before implementing it in C++.

## Example Problem

**Problem:** Determine whether a person is eligible to drive based on their age.

### Plain-English Algorithm

1. Ask the user for their age.
2. Receive and store the age entered by the user.
3. Check whether the age is valid.
4. If the age is negative or otherwise invalid, display an appropriate error message.
5. If the age is 18 or above, the person is eligible to drive.
6. Otherwise, the person is not eligible to drive.
7. Display the appropriate result.

## C++ Practice

I implemented the basic eligibility logic in C++.

The program:

* Takes an age as input.
* Checks whether the age is below 18.
* Displays whether the person is eligible to drive.

The implementation was compiled and tested using **G++ 13.3.0** with **C++17**.

## What I Learned From Debugging

While compiling my first version, I encountered several errors.

### Incorrect Header

I initially used:

```cpp
#include <iostream.h>
```

I learned that modern standard C++ uses:

```cpp
#include <iostream>
```

### Incorrect Return Statement

I also encountered an error caused by using:

```cpp
return;
```

inside a function returning `int`.

I corrected this and successfully compiled the program.

### Working Directory

I initially tried to compile `main.cpp` from the repository root even though the file was inside:

```text
00-programming-basics/01-what-is-programming/
```

I learned that the terminal's current directory matters when compiling a source file.

## Important Concepts From Today

* Programming is about solving problems, not just writing syntax.
* A problem should be understood before implementing it.
* A solution can first be described using plain-English steps.
* The same solution idea can be expressed as a program in a programming language.
* A running program can receive input, process it, and produce a result.
* Precise terminology matters when learning programming.
* Invalid input should be considered when designing a solution.

## Key Takeaway

The biggest lesson from Day 0 was that **programming starts with problem solving**.

Before worrying about complicated C++ features, I want to build the habit of understanding a problem, describing a solution clearly, and then implementing it.

## Repository Structure

```text
cpp-from-zero-to-advanced/
│
├── README.md
│
└── 00-programming-basics/
    └── 01-what-is-programming/
        ├── main.cpp
        └── README.md
```

## Tools Used

* GitHub Codespaces
* G++ 13.3.0
* C++17
* Git / GitHub

---

**Next topic:** BASICS · 02 — What is a Program?
