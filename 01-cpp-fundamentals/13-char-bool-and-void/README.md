# 13 — char, bool, and void

## What is it?

- **`char`**: the smallest integer type, exactly 1 byte. It stores a number (a
  character code); `std::cout` prints it as the character with that code.
- **`bool`**: holds `true` or `false`. It is an integral type: `true` converts
  to 1 and `false` to 0.
- **`void`**: means "no value". It is an incomplete type, so no object can have it.

## Why does it matter?

Text is stored as numbers, conditions need a yes/no type, and the type system
needs a way to say "nothing here". `char` is also C++'s byte type, and its
signedness differs between platforms, which is a real portability trap.

## char stores numbers

`char letter{'A'};` and `char code{65};` store the same `char` value: 65, the bit
pattern `01000001`. Both print as `A` because the type is `char`. Converting to
`int` prints the number: `static_cast<int>(letter)` gives 65.

## Three narrow character types

`char`, `signed char`, and `unsigned char` are three distinct types. Plain `char`
behaves like one of the other two; the platform decides which.

| Type            | Range here (x86-64 Linux) | Range on ARM Linux | Use                  |
| --------------- | ------------------------- | ------------------ | -------------------- |
| `char`          | −128 to 127 (signed)      | 0 to 255           | text                 |
| `signed char`   | −128 to 127               | −128 to 127        | small signed numbers |
| `unsigned char` | 0 to 255                  | 0 to 255           | raw bytes            |

The same bits in two types, measured here:

| Bits `11001000`         | Working       | Value |
| ----------------------- | ------------- | ----- |
| as `unsigned char`      | 128 + 64 + 8  | 200   |
| as `char` (signed here) | −128 + 64 + 8 | −56   |

**Use `unsigned char` for raw bytes.** Its meaning is the same on every platform.

## bool

| Code                                      | Output |
| ----------------------------------------- | ------ |
| `std::cout << isReady;`                   | `1`    |
| `std::cout << std::boolalpha << isReady;` | `true` |
| `sizeof(bool)`                            | `1`    |

`std::boolalpha` changes only the printing, not the value, and stays in effect
until `std::noboolalpha`.

## Example output

```text
letter as a character: A
letter as a number:    65
char is signed here:   true
char:          -128 to 127
signed char:   -128 to 127
unsigned char: 0 to 255
11001000 as unsigned char: 200
11001000 as char:          -56
isReady (default):   1
isReady (boolalpha): true
sizeof(bool): 1
```

## Common mistakes

| Mistake                       | Problem                                         | Fix                          |
| ----------------------------- | ----------------------------------------------- | ---------------------------- |
| `char` for raw bytes          | Bytes ≥ 128 are negative where `char` is signed | `unsigned char`              |
| `char c{200};`                | 200 does not fit a signed `char`                | `unsigned char c{200};`      |
| `char cf{11001000};`          | Decimal eleven million, not binary              | `0b11001000` (topic 14)      |
| Printing a `char` as a number | `std::cout` prints the character                | `static_cast<int>(c)`        |
| `bool flag{5};`               | A `bool` can only be 0 or 1                     | `bool flag{true};`           |
| `void nothing;`               | `void` has no value and no size                 | `void` is not an object type |

## Key takeaway

`char` stores numbers, `bool` stores yes or no, and `void` stores nothing. Use
`unsigned char` for raw bytes, because plain `char` signedness depends on the platform.

## Standard

C++23 (binary literals `0b` since C++14; conversion of out-of-range values to
signed types is defined as keeping the bit pattern since C++20).

## Compile command

```bash
g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main
```