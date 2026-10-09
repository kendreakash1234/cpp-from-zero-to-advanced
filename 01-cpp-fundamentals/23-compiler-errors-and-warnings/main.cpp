#include <iostream>

// The debugged version of this lesson's broken program.
// Original bugs, fixed one at a time (rebuilding after each):
//   1. missing ';' after int total{10}  -> reported on the NEXT line, and hid 'count'
//   2. typo 'totl'                      -> also caused "unused variable 'total'"
//   3. -1 < unsigned limit              -> -Wsign-compare: limit is now a signed int
//   4. unused variable                  -> removed
int main()
{
    const int total{10};
    const int count{2};
    std::cout << "total / count: " << total / count << '\n';   // 5

    const int limit{5};
    std::cout << std::boolalpha << "-1 < limit: " << (-1 < limit) << '\n';   // true

    return 0;
}