# 06 — Range-Based for

## What is it?

A loop that visits **every element** of a range, with no index (C++11):

```cpp
for (char c : text) { ... }   // "for each c in text"
```

It works on `std::string`, `std::vector`, braced lists, arrays, and every Standard
Library container. Without an index, there are no bounds to get wrong: no off-by-one.

## Copy, reference, or const reference

| Form                                 | Loop variable is                 | Use for                        |
| ------------------------------------ | -------------------------------- | ------------------------------ |
| `for (char c : s)`                   | a copy of each element           | reading small values           |
| `for (auto& c : s)`                  | the element itself               | modifying elements             |
| `for (const auto& x : v)`            | the element, read-only           | reading larger values, no copy |
| `for (int x : {3, 1, 4})`            | each value of a braced list      | quick fixed lists              |
| `for (std::size_t i{0}; char c : s)` | each char, plus an index (C++20) | when a position is needed      |

A **reference** is another name for an existing object.

## Copy vs reference

Replacing vowels in `programming` (tested with `cxx`, GCC 13):

| Loop                   | `word` afterwards                     |
| ---------------------- | ------------------------------------- |
| `for (auto c : word)`  | `programming` (unchanged, no warning) |
| `for (auto& c : word)` | `pr*gr*mm*ng`                         |

## Results

| Input         | Word          | Vowels | Consonants | Exit |
| ------------- | ------------- | ------ | ---------- | ---- |
| `programming` | `pr*gr*mm*ng` | 3      | 8          | 0    |
| `aeiou`       | `*****`       | 5      | 0          | 0    |
| `xyz`         | `xyz`         | 0      | 3          | 0    |
| `a`           | `*`           | 1      | 0          | 0    |
| (empty)       | invalid input | -      | -          | 1    |

The braced list `{3, 1, 4, 1, 5}` sums to 14.

## The string literal surprise

| Loop                                  | Runs                                   |
| ------------------------------------- | -------------------------------------- |
| `for (char c : "hello")`              | 6: the literal ends with a hidden `\0` |
| `for (char c : std::string{"hello"})` | 5                                      |

## How it works

The compiler rewrites it as an iterator loop. `begin` and `end` are computed
**once**, before the first run:

```cpp
for (auto first = begin(range), last = end(range); first != last; ++first) {
    auto& c = *first;   // or a copy
    ...
}
```

## Traps

| Code                                        | Result                                                                           |
| ------------------------------------------- | -------------------------------------------------------------------------------- |
| `'0'` instead of `'o'` in the vowel test    | `programming` counted 2 vowels: the compiler cannot catch a valid but wrong char |
| `for (auto c : word) { c = '*'; }`          | changes a copy: `word` is unchanged                                              |
| `auto&` over a `const std::string`          | error: assignment of read-only reference 'c'                                     |
| `v.push_back(...)` inside `for (int x : v)` | plain build printed garbage; ASan: heap-use-after-free                           |
| `for (std::string s : names)`               | copies every string: use `const auto&`                                           |

## Best practices

- Prefer range-based `for` when you need every element and no position.
- `auto&` to modify, `const auto&` to read anything larger than a number.
- Never add or remove elements of the container you are looping over.
- Need an index, a step, or reverse order? Use the classic `for`.

## Key takeaway

One `&` decides whether the loop changes the container. Choose copy, `auto&`, or
`const auto&` on purpose.

## Standard

C++23 (range-based `for` since C++11; init statement since C++20).