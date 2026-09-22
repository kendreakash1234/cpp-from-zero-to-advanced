# 08 — std::cout, std::cerr, std::cin

## Concept
`cout`, `cerr`, `cin` are **stream objects** in namespace `std`, declared in
`<iostream>`. They map to the OS's three standard channels:

| Stream | Channel         | Direction | Default |
|--------|-----------------|-----------|---------|
| cin    | standard input  | in        | keyboard |
| cout   | standard output | out       | screen  |
| cerr   | standard error  | out       | screen  |

## Why cerr is separate from cout
Both print to the screen, but they are different channels. When output is
redirected (`./main > out.txt`) only `cout` goes to the file; `cerr` stays on
screen — so errors never get buried inside your data. `cerr` is also
unbuffered, so errors appear immediately.

## Operators
- `<<` insertion — push data into an output stream.
- `>>` extraction — pull a whitespace-delimited token into a variable.
- Both chain because each returns the stream again.

## Handling bad input
`std::cin >> num` fails if the text isn't a number. Recover with **both**:
- `clear()`  — reset the error flag.
- `ignore(max, '\n')` — discard the leftover bad characters from the buffer.
Using only one leaves the stream broken (duplicate errors / 0 result).

## `\n` vs `std::endl`
`"\n"` writes a newline (fast, buffered). `std::endl` also **flushes** the
buffer (slower). Default to `"\n"`; use `endl` only when you need an immediate flush.

## Build & run

g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main

./main

```
## Sample runs

Enter two numbers: 4 5
Sum = 9

Enter two numbers: dfge
Expected a number