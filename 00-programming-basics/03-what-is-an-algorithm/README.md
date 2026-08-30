# BASICS · 03 — What is an Algorithm?

**Category:** BASICS
**Topic:** What is an Algorithm?
**Date:** 30 August 2026

## What I Learned

An algorithm is a finite, ordered sequence of clear steps used to solve a problem.

An algorithm focuses on the **logic needed to solve a problem**, rather than the syntax of a particular programming language.

A useful mental model is:

```text
Problem
   ↓
Algorithm / Logic
   ↓
Program
   ↓
Compilation
   ↓
Executable
   ↓
Execution
   ↓
Result
```

The same algorithm can be implemented in different programming languages because the algorithm itself is independent of a specific language.

I also learned that a good algorithm should have clear and unambiguous steps and should eventually terminate.

## Example Problem

**Problem:** Determine whether a number is positive, negative, or zero.

### Plain-English Algorithm

1. Ask the user to enter a number.
2. Receive the number.
3. Check whether the number is zero.
4. If the number is zero, display that the number is zero.
5. Otherwise, check whether the number is negative.
6. If the number is negative, display that the number is negative.
7. Otherwise, display that the number is positive.

The algorithm covers all three possible cases:

```text
Number
  │
  ├── 0      → Zero
  │
  ├── < 0    → Negative
  │
  └── > 0    → Positive
```

## C++ Practice

I implemented the algorithm in C++.

The program:

* Takes a number as input.
* Determines whether the number is zero, negative, or positive.
* Displays the corresponding result.

The implementation follows the algorithm directly:

```text
Input
  ↓
Check for zero
  ↓
Check for negative
  ↓
Otherwise positive
  ↓
Display result
```

## Testing

I tested the program with three different inputs:

### Test 1 — Zero

```text
Enter the number
0
Enter number is Zero
```

### Test 2 — Positive

```text
Enter the number
7
Entered number is Positive
```

### Test 3 — Negative

```text
Enter the number
-9
Entered number is Negative
```

All three test cases produced the expected result.

## Problem → Algorithm → Program → Execution

This exercise helped me understand how these concepts are connected.

**Problem:**
Determine whether a number is positive, negative, or zero.

**Algorithm:**
Describe the steps needed to determine the result.

**Program:**
Implement those steps using C++.

**Execution:**
Compile the C++ source code and run the resulting executable with actual input.

**Result:**
The program produces the appropriate output for the given number.

The C++ implementation maps directly to the algorithm without adding unnecessary logic.

## What I Learned From This Exercise

* An algorithm describes the logic for solving a problem.
* An algorithm is independent of a particular programming language.
* An algorithm consists of ordered steps.
* The steps should be clear and unambiguous.
* An algorithm should eventually terminate.
* A C++ program can implement an algorithm.
* I can test an algorithm implementation using different inputs.
* The problem → algorithm → program → execution relationship is important when understanding how a solution becomes working software.

## Technical Practice

I compiled the program using:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o main
```

The program compiled successfully without warnings.

I then executed it using:

```bash
./main
```

## Key Takeaway

The biggest lesson from this topic was that an algorithm is about **thinking through the solution before focusing on programming syntax**.

For this exercise, I first described the solution in plain-English steps and then translated those steps into C++.

This helped me see the relationship between:

```text
Problem
   ↓
Algorithm
   ↓
C++ Program
   ↓
Compilation
   ↓
Execution
   ↓
Result
```

## Repository Structure

```text
cpp-from-zero-to-advanced/
│
├── README.md
│
└── 00-programming-basics/
    ├── 01-what-is-programming/
    │   ├── main.cpp
    │   └── README.md
    │
    ├── 02-what-is-a-program/
    │   ├── main.cpp
    │   └── README.md
    │
    └── 03-what-is-an-algorithm/
        ├── main.cpp
        └── README.md
```

## Tools Used

* GitHub Codespaces
* G++ 13.3.0
* C++17
* Git / GitHub
