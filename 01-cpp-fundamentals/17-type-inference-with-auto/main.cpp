#include <iostream>

int main()
{
    // auto deduces the type from the initializer, once, at compile time.
    auto count{42};           // int
    auto total{3000000000};   // long: the literal is too big for int
    auto price{19.99};        // double
    auto ratio{0.5f};         // float: the f suffix decides
    auto grade{'A'};          // char
    auto ready{true};         // bool

    std::cout << "sizeof(count): " << sizeof(count) << '\n';
    std::cout << "sizeof(total): " << sizeof(total) << '\n';
    std::cout << "sizeof(price): " << sizeof(price) << '\n';
    std::cout << "sizeof(ratio): " << sizeof(ratio) << '\n';
    std::cout << "sizeof(grade): " << sizeof(grade) << '\n';
    std::cout << "sizeof(ready): " << sizeof(ready) << '\n';

    // The type never changes: assignment converts, it does not re-deduce.
    auto n{5};
    n = 3.9;
    std::cout << "n after n = 3.9: " << n << '\n';

    // auto drops top-level const: copy is a separate, modifiable int.
    const int limit{10};
    auto copy{limit};
    copy = 20;
    std::cout << "copy: " << copy << '\n';

    // Traps shown in this lesson (uncomment to see the compiler's response):
    // auto x;                          // error: 'auto x' has no initializer
    // auto y{1, 2};                    // error: requires exactly one element
    // const auto fixed{limit};
    // fixed = 20;                      // error: assignment of read-only variable

    return 0;
}