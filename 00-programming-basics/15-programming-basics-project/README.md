15 — Programming Basics Project (Capstone)

Stage 00 — Programming Basics

The final module of Stage 00. It combines every Programming Basics concept into a
single working program: input → processing → output, variables as state, data and
operations, expressions, statements, conditions, repetition, a reusable function,
and problem decomposition.



What it does

Read integers from the user until a sentinel value 0 is entered. Then print:

sum of all numbers
min and max
total count of numbers entered
even count (how many were even)
average

If the very first entry is 0, no numbers were entered, so the program reports an
error and exits (this also prevents a divide-by-zero).



Why it matters

Concepts learned in isolation don't prove you can build anything. A capstone
connects them and exposes the gaps that only appear when the pieces work together —
which is the shape of every real program: read input, hold state in variables,
drive logic with conditions and loops, and reuse logic with functions.



Stage 00 — all 15 topics explained

This capstone is the place where every Programming Basics topic comes together.
Below is a short, honest explanation of each — and exactly where it shows up in
main.cpp.

1. What is programming?
Giving a computer a precise, ordered set of instructions to solve a problem. This
project turns the plain request "summarise some numbers" into exact steps.

2. What is a program?
The complete set of instructions that runs from start to finish. main() is the
entry point; the program ends when it returns from main.

3. What is an algorithm?
A finite, unambiguous sequence of steps that produces the right output for valid
input. The algorithm here is: read → accumulate → report. It is written out as
pseudocode below before any C++.

4. Input → Processing → Output
Every program has this shape.
Input: std::cin >> N reads each number.
Processing: the loop updates sum, min, max, counts.
Output: std::cout prints the results.

5. Variables as stored state
A variable is a named box that remembers a value between steps. sum,
total_count, even_count, min, and max carry state across loop passes —
which is why they are initialized before the loop, not inside it.

6. Data and operations
Data are the values (integers like N, sum); operations act on them
(+, +=, %, comparisons </>). sum += N and N % 2 are operations on
integer data.

7. Expressions
An expression computes a value. static_cast<double>(sum) / total_count produces
the average; x % 2 == 0 produces a bool. Expressions are the "compute" part of
processing.

8. Statements
A statement is a complete instruction the program executes, usually ending in ;.
sum += N;, total_count++;, and each std::cout << ...; are statements. A
program is a sequence of statements.

9. Conditions
A condition chooses between paths based on a true/false test. if (max < N),
if (min > N), and if (isEven(N)) decide whether to update a value or a counter.

10. Repetition
A loop repeats statements so a few lines can process unlimited data. The
while (N != 0) loop keeps reading and processing until the sentinel 0 arrives.

11. Functions as reusable logic
A function is a named, reusable block. bool isEven(int x) names one idea
(x % 2 == 0) once and is called wherever needed, instead of repeating the test.

12. Breaking a problem into smaller problems (decomposition)
The big task splits into sub-tasks: (a) read a value, (b) accumulate into running
totals, (c) after the loop, compute the average and print. Each sub-task is simple
on its own.

13. Pseudocode
Language-neutral steps that capture the plan before syntax. The pseudocode section
below is the algorithm expressed in readable intent — no std::cin, no types.

14. Flowcharts and basic program flow
Control flows top-to-bottom, branches at conditions, and loops back at the sentinel
read. The flow: read → (loop: process → read) → check empty → compute → print.

15. Basic problem-solving exercises (this project)
The capstone itself — applying the five-step method (understand, examples,
decompose, algorithm, trace) to build and verify one program that uses topics 1–14.

Quick concept map

Concept
Where it appears
Input → Processing → Output
read N, loop and compute, print results
Variables as state
sum, total_count, even_count, min, max
Data & operations
sum += N, N % 2
Expressions
static_cast<double>(sum) / total_count
Statements
each executed line
Conditions
if (max < N), if (isEven(N))
Repetition
sentinel while (N != 0) loop
Function as reusable logic
isEven(int x)
Decomposition
split into read → accumulate → report



Algorithm (pseudocode)

FUNCTION isEven(x)
    RETURN (x mod 2 = 0)

READ N
sum <- 0 ; total <- 0 ; evens <- 0
max <- INT_MIN            // lowest, so any value updates it
min <- INT_MAX            // highest, so any value updates it

WHILE N != 0 DO
    sum <- sum + N
    total <- total + 1
    IF N > max THEN max <- N
    IF N < min THEN min <- N
    IF isEven(N) THEN evens <- evens + 1
    READ N

IF total = 0 THEN
    PRINT "count should not be zero" ; STOP

average <- sum / total          // double division
PRINT sum, min, max, total, evens, average



Example run

Enter the number : 3
Enter the number and to exit press 0 : 5
Enter the number and to exit press 0 : 9
Enter the number and to exit press 0 : -8
Enter the number and to exit press 0 : 5
Enter the number and to exit press 0 : 0
Sum = 14
min = -8
max = 9
total count = 5
even count = 1
average = 2.8



Common mistakes

Initializing accumulators/counters inside the loop — they reset every pass.
max = 0 / min = 0 — wrong for all-negative or all-positive input. Use
  std::numeric_limits<int>::min() for max and ::max() for min (the cross is
  intentional).
Computing the average inside the loop instead of once after it.
Integer average: int a = sum / count truncates. Use
  static_cast<double>(sum) / count.
Forgetting the empty-input case → divide by zero.
Processing the sentinel value itself: read before testing the condition.



Key takeaway

A program transforms input state into output state one statement at a time. Loops
let a few statements process unlimited data, and functions let you name and reuse an
idea.



Standard and compiler

Stage 00 is pre-syntax, so the algorithm is language-neutral; main.cpp is a modern
C++ translation. It was compiled and run successfully with GCC and also builds under
the C++23 baseline:

g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main
./main

Files

15-programming-basics-project/
├── main.cpp        final verified program
├── README.md       this file