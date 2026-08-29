# BASICS · 02 — What is a Program?

**Category:** BASICS
**Topic:** What is a Program?
**Date:** 30 August 2026

## What I Learned

A **program** is a set of instructions written in a programming language to make a computer perform a specific task.

I learned that programming starts with a problem and that the solution can be expressed as logic and then implemented as a program.

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
Execution
   ↓
Result
```

An algorithm describes the logic for solving a problem, while a program is a specific implementation of that logic in a programming language.

## Example Program

For today's exercise, I created a simple program that collects information about a person.

The program:

* Asks the user for their name.
* Receives the name.
* Asks for their age.
* Receives the age.
* Asks for their role.
* Receives the role.
* Displays the collected information.

## C++ Practice

I implemented the program using:

* `std::string` for text data.
* `int` for the age.
* `std::cin` for input.
* `std::getline()` for reading text input.
* `std::cout` for output.

I also learned that `std::cin >> age` leaves the newline character in the input stream, which can affect a following `std::getline()`.

For this exercise, I used:

```cpp
std::cin.ignore();
```

to consume the remaining newline before reading the role.

## What I Learned From Debugging

### Standard Library Namespace

I learned that standard library names should be explicitly qualified with `std::`.

For example:

```cpp
std::string
std::cout
std::cin
std::getline
```

This is clearer than relying on `using namespace std;`.

### `std::getline()` and `std::cin`

I learned that:

```cpp
std::cin >> age;
```

and:

```cpp
std::getline(std::cin, role);
```

handle input differently.

After extracting the age, the newline entered by the user remains in the input stream. I needed to account for that before using `std::getline()`.

### `std::endl` vs Newline

I also learned that `std::endl` does more than insert a newline: it also flushes the output stream.

For normal newline output, I will prefer:

```cpp
'\n'
```

and use `std::endl` only when an explicit flush is actually required.

## Important Concepts From Today

* A program is an implementation of logic written in a programming language.
* A program can receive input, process information, and produce output.
* Algorithms describe problem-solving logic independently of a particular programming language.
* C++ standard library names are normally accessed through the `std::` namespace.
* `std::cin` and `std::getline()` have different input behavior.
* Small implementation details can affect how a program behaves.
* Compiling with warnings helps identify potential problems early.

## What I Practiced

I created and tested a small C++ program that displays information about a person.

Example:

```text
Enter the name of user : JOHN D
Enter the age of user : 29
Enter the role of user : Software Developer

Name : JOHN D
Age : 29
Role : Sr. Software Developer
```

The program was compiled using:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o main
```

and executed successfully in **GitHub Codespaces**.

## Key Takeaway

Today's main lesson was understanding what a **program** actually represents.

A program takes a set of instructions and turns them into an executable process that can receive input, perform its intended work, and produce a result.

I also learned that writing code is only part of the process. Understanding how the pieces of a program work together is equally important.

## Repository Structure

```text
cpp-from-zero-to-advanced/
│
├── README.md
│
└── 00-programming-basics/
    │
    ├── 01-what-is-programming/
    │   ├── main.cpp
    │   └── README.md
    │
    └── 02-what-is-a-program/
        ├── main.cpp
        └── README.md
```

## Tools Used

* GitHub Codespaces
* G++ 13.3.0
* C++17
* Git / GitHub

---

**Next topic:** BASICS · 03 — What is an Algorithm?
