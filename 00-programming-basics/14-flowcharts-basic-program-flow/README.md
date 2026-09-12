Flowcharts and Basic Program Flow
1. What Is a Flowchart?
A flowchart is a visual representation of an algorithm. It shows the steps of a program and the order in which they are executed.

Program flow is the path followed by a program from start to end.

A flowchart is not executable code. It is used to plan, understand, and verify the logic before implementing it in C++17.

2. Why Use Flowcharts?
Flowcharts help me:

arrange instructions in the correct order;
identify input, processing, decisions, and output;
visualize different execution paths;
verify that every decision has a valid outcome;
translate the algorithm into C++17 code.
The overall process is:

Problem
   ↓
Flowchart
   ↓
Check the Logic
   ↓
C++17 Program

3. Basic Flowchart Shapes
Shape	Name	Purpose	Example
⬭	Terminator	Start or end of the program	Start, End
▱	Parallelogram	Input or output	Input number, Display result
▭	Rectangle	Processing or calculation	Calculate total
◇	Diamond	Decision / condition	Is number even?
→	Arrow	Shows the direction of flow	Input → Process

Easy way to remember
Oval          → Start / End
Parallelogram → Input / Output
Rectangle     → Process
Diamond       → Decision
Arrow         → Flow direction

4. Basic Program Flow
A simple program generally follows:

   ⬭
 Start
   |
   v
 ▱ Input
   |
   v
 ▭ Process
   |
   v
 ▱ Output
   |
   v
  ⬭
  End

When a decision is required, the flow splits into different paths:

              Yes
               ↓
           ┌─────────┐
           │ Action A│
           └────┬────┘
                │
                ↓
Start → Input → ◇ Decision
                │
                ↓
           ┌─────────┐
           │ Action B│
           └─────────┘
              No

The diamond determines which path the program follows.

5. Example: Even or Odd
Suppose the problem is:

Take an integer as input and determine whether it is even or odd.

Flowchart
             ⬭
           Start
             |
             v
       ▱ Input number
             |
             v
   ▭ isEven = number % 2 == 0
             |
             v
        ◇ isEven?
         /       \
       Yes        No
        |          |
        v          v
 ▱ Output       ▱ Output
   "Even"         "Odd"
        |          |
        └────┬─────┘
             |
             v
             ⬭
            End

6. How Each Shape Is Used
Step	Shape	What happens
1	⬭	Start the program
2	▱	Input an integer
3	▭	Process number % 2 == 0
4	◇	Decide whether the result is true or false
5	▱	Output "Even" if Yes
6	▱	Output "Odd" if No
7	⬭	End the program

7. Understanding the Decision
The diamond contains a condition, not an action.

◇ Is number % 2 == 0?

The program checks the remainder after dividing the number by 2.

Condition	Result
number % 2 == 0	Even
number % 2 != 0	Odd

For example:

10 % 2 = 0  → Even
7 % 2 = 1   → Odd
0 % 2 = 0   → Even

So 0 is also even.

8. Flowchart → C++17
The flowchart can be translated directly into C++17:

const bool isEven{number % 2 == 0};

if (isEven)
{
    std::cout << number << " is even.\n";
}
else
{
    std::cout << number << " is odd.\n";
}

Mapping
Flowchart	C++17
⬭ Start	Beginning of main()
▱ Input	std::cin >> number
▭ Process	const bool isEven{...};
◇ Decision	if (isEven)
▱ Output	std::cout
⬭ End	return 0;

Important: The arrows do not become C++ statements. They simply show the order of execution.

9. Common Flowchart Mistakes
Using the wrong shape for a step.
Using a rectangle for input or output.
Putting an action instead of a condition inside a diamond.
Forgetting to label decision branches as Yes/No.
Leaving one possible result without a path.
Failing to connect paths to the end.
Drawing arrows in the wrong direction.
Writing C++ code that does not match the flowchart.
10. Key Takeaway
The main idea is:

Problem
   ↓
Identify Input
   ↓
Identify Processing
   ↓
Identify Decisions
   ↓
Identify Output
   ↓
Draw Flowchart
   ↓
Verify the Logic
   ↓
Write C++17 Code

Flowchart = visual plan of the program
C++17 = implementation of that plan