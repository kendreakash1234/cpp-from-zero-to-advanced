#include <iostream>
#include <string>
#include <vector>

int main()
{
    // std::string: a sequence of characters that knows its size.
    const std::string city{"Pune"};
    std::cout << city << ", size " << city.size()
              << ", first '" << city[0] << "', last '" << city.back() << "'\n";   // size 4, 'P', 'e'

    const std::string label{city + ", India"};
    std::cout << label << ", size " << label.size() << '\n';                       // size 11

    // A literal is not a std::string: make one side a std::string to use +.
    const std::string joined{std::string{"C"} + "++"};
    std::cout << "joined: " << joined << '\n';                                     // C++

    // std::vector<int>: a sequence of ints that can grow.
    std::vector<int> temps{28, 31, 26};
    temps.push_back(33);
    std::cout << "temps: size " << temps.size() << ", front " << temps.front()
              << ", back " << temps.back() << ", temps[1] " << temps[1]
              << ", temps.at(1) " << temps.at(1) << '\n';                          // 4, 28, 33, 31, 31

    // Parentheses vs braces construct different things.
    const std::vector<int> a(4);   // four elements, all 0
    const std::vector<int> b{4};   // one element: 4
    std::cout << "a(4): size " << a.size() << ", a[0] " << a[0] << '\n';            // 4, 0
    std::cout << "b{4}: size " << b.size() << ", b[0] " << b[0] << '\n';            // 1, 4

    const std::string s1(3, 'x');  // "xxx"
    const std::string s2{3, 'x'};  // two chars: char(3) and 'x'
    std::cout << "s1(3, 'x'): size " << s1.size() << ", s2{3, 'x'}: size " << s2.size() << '\n';  // 3, 2

    // Traps shown in this lesson (uncomment to see the result):
    // std::cout << temps[10];     // UB: printed 0 silently; -D_GLIBCXX_ASSERTIONS aborts
    // std::cout << temps.at(10);  // throws std::out_of_range with index and size
    // auto bad = "C" + "++";      // error: invalid operands of types 'const char [2]' and 'const char [3]'

    return 0;
}