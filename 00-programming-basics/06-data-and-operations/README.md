# Data and Operations

## What I Learned

Data is the information or values that a program works with.

Operations are the actions performed on that data to do some work and produce a result.

In C++, data can be stored in variables, and operations can be performed on those values.

### Simple mental model

```text
Data
  ↓
Operation
  ↓
Result
```

For example:

```text
Price = 12
Quantity = 1

12 × 1
  ↓
12
```

Here:

* `12` is data.
* `1` is data.
* `*` is the multiplication operation.
* `12` is the resulting value.

---

## Today's Exercise

I created a small C++ program that accepts the price and quantity of two products.

The program then multiplies the price by the quantity for each product and displays the result.

### Program flow

```text
Input
  ↓
Price 1 + Quantity 1
Price 2 + Quantity 2
  ↓
Processing
  ↓
price1 × quantity1
price2 × quantity2
  ↓
Output
  ↓
Total for each product
```

---

## Code

```cpp
#include<iostream>

int main()
{
    int price1{},quantity1{},result1{},price2{},quantity2{},result2{};

    std::cout<<"Enter the price of first product : ";
    std::cin>>price1;

    std::cout<<"Enter the quantity of first product : ";
    std::cin>>quantity1;

    std::cout<<"Enter the price of second product : ";
    std::cin>>price2;

    std::cout<<"Enter the quantity of second product : ";
    std::cin>>quantity2;

    result1 = price1 * quantity1;
    result2 = price2 * quantity2;

    std::cout<<"Final product of first product : "<<result1<<std::endl;
    std::cout<<"Final product of second product : "<<result2<<std::endl;

    return 0;
}
```

---

## Example Run

Input:

```text
Price 1 = 12
Quantity 1 = 1
Price 2 = 21
Quantity 2 = 2
```

Output:

```text
Final product of first product : 12
Final product of second product : 42
```

The calculations are:

```text
12 × 1 = 12
21 × 2 = 42
```

---

## Important Concepts Learned

* Data represents values/information that a program works with.
* Operations perform work on data.
* Multiplication is an arithmetic operation.
* Variables can store data.
* The result of an operation can be stored in another variable.
* Multiple pieces of data can be combined during processing.
* The type of data affects how operations are performed.
* `int` is suitable for whole-number values such as item quantities in this exercise.
* A simple program can follow the pattern:

```text
Input → Processing → Output
```

---

## Debugging / Learning Notes

One important lesson from the previous exercise was to pay attention to the types of operands involved in an operation.

For this exercise, all values are whole numbers, so using `int` is appropriate.

I also restored my compilation command to:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o main
```

The program compiled without warnings and produced the expected results.

---

## Tools Used

* C++
* C++17
* G++ compiler
* GitHub Codespaces

Compilation:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o main
```

Execution:

```bash
./main
```

---

## Key Takeaway

> Data is what a program works with, and operations are the actions performed on that data to produce a result.

This exercise helped me understand the relationship between **data, operations, and results** in a simple C++ program.

---

## Progress

**C++ From Zero to Advanced — Programming Basics**

* [x] What is Programming?
* [x] What is a Program?
* [x] What is an Algorithm?
* [x] Input → Processing → Output
* [x] Variables and State
* [x] Data and Operations
