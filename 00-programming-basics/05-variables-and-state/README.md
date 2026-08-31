# BASICS · 05 — Variables and State

**Category:** BASICS
**Topic:** Variables and State
**Date:** 31 August 2026

## What I Learned

A **variable** is a name associated with a stored value.

A variable allows a program to store a value and refer to that value using a name.

For example:

```cpp
int balance{1000};
```

Here:

* `int` is the type.
* `balance` is the variable name.
* `1000` is the value stored in the variable.

A variable's value can change while the program is running.

When the stored value changes, the **state of the variable changes**.

## Variable State

I learned to think about a variable as having a current state represented by its current stored value.

In the example:

```cpp
int balance{1000};
```

the initial state is:

```text
balance → 1000
```

After:

```cpp
balance += 500;
```

the state changes to:

```text
balance → 1500
```

After:

```cpp
balance -= 300;
```

the state changes again:

```text
balance → 1200
```

The same variable is being used throughout the program; its stored value is changing.

## Practical Example

I created a simple program that represents a balance changing over time.

The program:

1. Creates a variable named `balance` with an initial value of `1000`.
2. Displays the initial balance.
3. Adds `500` to the balance.
4. Displays the updated balance.
5. Subtracts `300` from the balance.
6. Displays the updated balance again.

The state changes can be visualized as:

```text
Initial state
balance → 1000

       ↓ +500

New state
balance → 1500

       ↓ -300

New state
balance → 1200
```

## C++ Practice

The exercise was implemented using:

```cpp
int balance{1000};

std::cout << balance << '\n';

balance += 500;

std::cout << balance << '\n';

balance -= 300;

std::cout << balance << '\n';
```

Expected output:

```text
1000
1500
1200
```

## Important Concepts From Today

* A variable is a name associated with a stored value.
* A variable has a type and a current value.
* A variable can be used multiple times in a program.
* The value stored in a variable can change.
* When the stored value changes, the state of that variable changes.
* `+=` can update a variable by adding a value.
* `-=` can update a variable by subtracting a value.
* The same variable can represent different states at different points during program execution.

## Key Takeaway

The important idea I learned today is that a variable is not just a name or just a value.

It is a named piece of stored data whose current value represents its **state**.

For example:

```text
balance → 1000
balance → 1500
balance → 1200
```

Only one variable named `balance` is being used. Its value changes, so its state changes as the program executes.

## Tools Used

* GitHub Codespaces
* G++
* C++17
* Git / GitHub

## Repository Structure

```text
cpp-from-zero-to-advanced/
│
├── README.md
│
└── 00-programming-basics/
    ├── 01-what-is-programming/
    ├── 02-what-is-a-program/
    ├── 03-what-is-an-algorithm/
    ├── 04-input-processing-output/
    └── 05-variables-and-state/
        ├── main.cpp
        └── README.md
```

---

**Next topic:** Continue to the next topic in the BASICS roadmap.
