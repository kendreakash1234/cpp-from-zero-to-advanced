#include <iostream>

int main()
{
    int width{10};    // direct-list-initialization (preferred)
    int height = 20;  // copy-initialization
    int depth(30);    // direct-initialization
    int count{};      // value-initialization: guaranteed to be 0

    // Traps shown in this lesson (uncomment to see the compiler's response):
    // int broken{7.5};  // error: braces forbid narrowing (double -> int)
    // int result();     // declares a function, not a variable (vexing parse)
    // int mystery;      // no initializer: reading it is undefined behavior

    std::cout << "direct-list-initialization: " << width << '\n';
    std::cout << "copy-initialization:        " << height << '\n';
    std::cout << "direct-initialization:      " << depth << '\n';
    std::cout << "value-initialization:       " << count << '\n';

    return 0;
}