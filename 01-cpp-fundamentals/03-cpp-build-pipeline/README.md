03 — The C++ build pipeline

Stage 01 — C++ Fundamentals
preprocessing → compilation → assembly → linking → executable

Definition

The build pipeline is the sequence of tools that turns your human-readable
main.cpp into a runnable program. The CPU cannot run C++ text, so four tools
translate and assemble it step by step.

Why it matters

C++ is compiled, not interpreted. Errors appear at different stages, and
knowing which stage failed tells you where to look:

Missing declaration → compiler error.
Missing definition → linker error.

The pipeline

  main.cpp            source (plain text)
     │  1) PREPROCESSOR   (g++ -E)   paste #include, expand #define, strip comments
     ▼
  main.i              translation unit (pure C++, no # directives)
     │  2) COMPILER       (g++ -S)   check syntax & types, translate to assembly
     ▼
  main.s              assembly (CPU instructions, human-readable)
     │  3) ASSEMBLER      (g++ -c)   assembly -> machine code
     ▼
  main.o              object file (machine code, not yet runnable)
     │  4) LINKER         (g++)      join objects + libraries, resolve references
     ▼
  app / main          executable  ->  loaded and run by the OS/CPU

The stages in plain words

Preprocessing — text only: pastes headers in, replaces macros, strips
   comments. Output is one "translation unit".
Compilation — checks syntax and types, translates to assembly. Syntax/type
   errors and undeclared names stop you here.
Assembly — turns assembly text into machine-code object files (.o).
Linking — combines all .o files + libraries and connects every function
   call to its definition. Missing/duplicate definitions stop you here.
Executable — a standalone file the OS loads into memory and runs.

See each stage yourself

g++ -std=c++23 -E main.cpp -o main.i    # 1. preprocess only
g++ -std=c++23 -S main.cpp -o main.s    # 2. compile to assembly
g++ -std=c++23 -c main.cpp -o main.o    # 3. assemble to object file
g++ main.o -o app                       # 4. link into executable
-E stop after preprocess · -S stop after compile · -c stop after assemble ·
-o name the output. (Note: flags are case-sensitive — -S ≠ -s, -c ≠ -C.)

Which stage catches which error

Stage
Catches
Example
Preprocessor
include file not found
#include <a.h> (missing file)
Compiler
syntax / type / undeclared name
int a = 9  (no ;)  ·  int a = "hi";
Linker
declared but never defined
int foo(); used, no body → undefined reference

Common mistakes

Calling the whole thing "compiling" — it is four tools, not one.
Confusing compiler errors (missing declaration) with linker errors
  (missing definition).
Editing the source but running the old executable — you must rebuild.
Thinking #include imports code like Python — it literally pastes text.

Key takeaway

.cpp → preprocess (paste/replace text) → compile (C++ → assembly, checks
types) → assemble (→ machine-code .o) → link (join pieces, resolve calls)
→ executable. The stage that fails tells you where the problem is.

Standard and compiler

g++ -Wall -Wextra -Wpedantic -std=c++23 main.cpp -o main
./main

Not compiled in the authoring environment (no compiler installed here). Run the
commands above to build and inspect each stage yourself.
