#include <iostream>

int main()
{
    // Initialization creates the object; assignment changes an existing one.
    int balance{1000};
    std::cout << "initialized:    " << balance << '\n';

    balance = 1500;
    std::cout << "assigned 1500:  " << balance << '\n';

    // Compound assignment: balance += 250 means balance = balance + 250.
    balance += 250;
    std::cout << "after += 250:   " << balance << '\n';
    balance -= 100;
    std::cout << "after -= 100:   " << balance << '\n';

    // Chained assignment groups right to left: a = (b = 42).
    int a{10};
    int b{20};
    a = b = 42;
    std::cout << "a = b = 42:     a = " << a << ", b = " << b << '\n';

    // Plain assignment narrows silently: 7.8 becomes 7.
    int p{};
    p = 7.8;
    std::cout << "p = 7.8 gives:  " << p << '\n';

    // Each assignment changes only its left side.
    int x{1};
    int y{2};
    int z{3};
    x = y;   // x 2, y 2, z 3
    y = z;   // x 2, y 3, z 3
    z = x;   // x 2, y 3, z 2
    std::cout << "trace result:   x = " << x << ", y = " << y << ", z = " << z << '\n';

    // Traps shown in this lesson (uncomment to see the compiler's response):
    // p = {7.8};        // error: braces reject narrowing
    // 5 = balance;      // error: lvalue required as left operand of assignment
    // balance + = 5;    // error: += is one token, no space allowed

    return 0;
}