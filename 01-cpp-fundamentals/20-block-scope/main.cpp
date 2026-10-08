#include <iostream>

int main()
{
    int count{0};
    std::cout << "outer count at start:  " << count << '\n';   // 0

    {
        // Inner blocks see outer names: this changes the outer count.
        count = 5;
        std::cout << "after count = 5 inside: " << count << '\n';   // 5

        // A name declared here exists only until this block's closing brace.
        const int temporary{42};
        std::cout << "inner temporary:        " << temporary << '\n';   // 42
    }   // temporary's scope and lifetime end here

    std::cout << "outer count at end:    " << count << '\n';   // 5

    // Traps shown in this lesson (uncomment to see the compiler's response):
    // { int count{9}; }        // warning with -Wshadow=local: shadows a previous local
    // temporary = 1;           // error: 'temporary' was not declared in this scope
    // w = 5; int w{};          // error: 'w' was not declared in this scope
    // int count{1};            // error: redeclaration of 'int count'

    return 0;
}