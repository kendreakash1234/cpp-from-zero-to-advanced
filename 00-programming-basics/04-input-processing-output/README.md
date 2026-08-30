# BASICS · 04 — Input → Processing → Output

**Category:** BASICS
**Topic:** Input → Processing → Output
**Date:** 30 August 2026

## What I Learned

A basic program can be understood through three stages:

```text
Input
  ↓
Processing
  ↓
Output
```

* **Input** is the data received by the program.
* **Processing** is the operation or logic performed on that data.
* **Output** is the result produced by the program.

This provides a simple way to understand what a program is doing with data.

## Example Problem

**Problem:** Calculate the final price of items after applying tax.

The program receives:

* Price
* Quantity
* Tax percentage

It then calculates the total price including tax and displays the result.

```text
Input
  ↓
Price + Quantity + Tax
  ↓
Processing
  ↓
Calculate total price including tax
  ↓
Output
  ↓
Final Price
```

## C++ Practice

I implemented the problem in C++.

The program:

* Takes the item price as input.
* Takes the quantity as input.
* Takes the tax percentage as input.
* Calculates the final price.
* Displays the final price.

The program was compiled and tested using G++ with C++17.

## Debugging Lesson — Integer Arithmetic

During the exercise, I encountered an important issue related to the types used in the calculation.

Initially, `price`, `quantity`, and `tax` were declared as `int`.

The calculation:

```cpp
price * quantity * tax / 100
```

was therefore performed using integer arithmetic.

For example:

```text
10 × 3 × 18 / 100
= 540 / 100
= 5
```

The fractional part was lost before the result was assigned to `double finalPrice`.

I fixed the issue by using `double` for the values that needed fractional arithmetic.

After the fix:

```text
10 × 3 × 18 / 100
= 5.4
```

and the final result became:

```text
Final price is 35.4
```

## Testing

I first tested:

```text
Price = 10
Quantity = 10
Tax = 18
```

which produced:

```text
Final price is 118
```

This test did not expose the integer-division problem because the intermediate result divided evenly.

I then tested:

```text
Price = 10
Quantity = 3
Tax = 18
```

The program produced:

```text
Final price is 35.4
```

This confirmed that the fractional value was being preserved.

## Important Concepts From Today

* Input is data received by a program.
* Processing is the work performed on the input.
* Output is the result produced by the program.
* `std::cin` can be used to receive input.
* `std::cout` can be used to display output.
* The types of operands can affect how an expression is evaluated.
* A variable being `double` does not automatically make every part of an expression floating-point.
* A program can compile successfully and still contain a logical error.
* Testing with carefully chosen inputs can expose bugs that normal test cases may not reveal.

## Key Takeaway

Today's biggest lesson was understanding the basic flow:

```text
Input → Processing → Output
```

I also learned that correct processing depends not only on the formula itself, but also on how the data involved in that calculation is represented.

A program compiling successfully is only one step. Testing the actual behavior is equally important.

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
    └── 04-input-processing-output/
        ├── main.cpp
        └── README.md
```

## Tools Used

* GitHub Codespaces
* G++ 13.3.0
* C++17
* Git / GitHub

---

**Next topic:** Continue to the next concept in the C++ From Zero to Advanced roadmap.
