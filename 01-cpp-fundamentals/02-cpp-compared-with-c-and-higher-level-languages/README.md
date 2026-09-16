02 — C++ compared with C and higher-level languages

Stage 01 — C++ Fundamentals

Definition

C++ sits between two neighbours: the lower-level language C, and
higher-level languages like Python and Java. It keeps C's speed and control,
adds tools to organise large programs (classes, templates, the STL), and
trades away the automatic conveniences (like a garbage collector) that high-level
languages give you.

Why it matters

Every language balances control vs convenience. Knowing where C++ sits tells you
when to reach for it and explains why its code looks the way it does.

more control / faster                     more convenience / safer defaults
Assembly ── C ── C++ ───────────────────── Java / C# ── Python


What C++ adds over C: classes, templates, the STL (vector, string, map),
references, overloading, and RAII for safe resource cleanup.

What C++ keeps from C that Python hides: pointers, manual memory, direct
hardware access, and compile-to-native execution.

One example, three styles (sum a list)

C: raw array + manual loop, you track the size yourself.
C++: std::vector<int> + range-based for — high-level and fast (see main.cpp).
Python: sum(numbers) — one line, but slower and memory-managed for you.

Common mistakes

Saying "C/C++" as if it is one language — related, but distinct.
Assuming C++ frees memory for you like Java/Python — by default it does not; RAII
  and smart pointers are the C++ way.
Thinking higher-level is always worse — for many tasks, speed of writing wins.
Writing only "C with classes" and never using std::string, std::vector, RAII.

Key takeaway

C++ is the language that reaches across the spectrum: it can be as low-level as C or
as expressive as a high-level language — compiled, with memory managed by object
lifetime (RAII) instead of a garbage collector.

Standard and compiler

g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main
./main
