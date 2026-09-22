#include <iostream>   // std::cout lives in namespace std

// Our own namespace: groups geometry helpers, avoids name clashes.
namespace geometry {
    int area(int w, int h) {   // full name is geometry::area
        return w * h;
    }
}

// Two namespaces with the SAME function name — legal, they don't collide.
namespace metric {
    double length() { return 5; }   // metric::length
}
namespace imperial {
    double length() { return 6; }   // imperial::length
}

int main()
{
    // Qualified names: :: reaches inside a namespace.
    std::cout << geometry::area(5, 4) << "\n";   // 20

    std::cout << metric::length()   << "\n";     // 5
    std::cout << imperial::length() << "\n";     // 6

    // using-declaration: bring ONE name into scope.
    using metric::length;
    std::cout << length() << "\n";               // 5  (resolves to metric)

    // NOTE: adding `using imperial::length;` here too would make an
    // unqualified length() call AMBIGUOUS -> compiler error, because both
    // metric::length and imperial::length would be equally valid candidates.

    return 0;
}