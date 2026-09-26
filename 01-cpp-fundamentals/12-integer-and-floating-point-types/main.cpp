#include <iomanip>
#include <iostream>
#include <limits>

int main()
{
    // Integer ranges: signed and unsigned forms have the same size and the
    // same number of values; only the meaning of the bit patterns differs.
    std::cout << "short:              " << std::numeric_limits<short>::min()
              << " to " << std::numeric_limits<short>::max() << '\n';
    std::cout << "unsigned short:     " << std::numeric_limits<unsigned short>::min()
              << " to " << std::numeric_limits<unsigned short>::max() << '\n';
    std::cout << "int:                " << std::numeric_limits<int>::min()
              << " to " << std::numeric_limits<int>::max() << '\n';
    std::cout << "unsigned int:       " << std::numeric_limits<unsigned int>::min()
              << " to " << std::numeric_limits<unsigned int>::max() << '\n';
    std::cout << "long long:          " << std::numeric_limits<long long>::min()
              << " to " << std::numeric_limits<long long>::max() << '\n';
    std::cout << "unsigned long long: " << std::numeric_limits<unsigned long long>::min()
              << " to " << std::numeric_limits<unsigned long long>::max() << '\n';

    // Floating-point ranges: lowest() is the most negative value.
    std::cout << "float:              " << std::numeric_limits<float>::lowest()
              << " to " << std::numeric_limits<float>::max() << '\n';
    std::cout << "double:             " << std::numeric_limits<double>::lowest()
              << " to " << std::numeric_limits<double>::max() << '\n';

    // digits10: significant decimal digits guaranteed to survive storage.
    std::cout << "float digits10:     " << std::numeric_limits<float>::digits10 << '\n';
    std::cout << "double digits10:    " << std::numeric_limits<double>::digits10 << '\n';

    // Precision: only fractions built from halves (1/2, 1/4, ...) are exact.
    double tenth{0.1};
    double fifth{0.2};
    double threeTenths{0.3};
    double twoFifths{0.4};
    double half{0.5};

    std::cout << std::setprecision(17);
    std::cout << "0.1 is stored as " << tenth << '\n';
    std::cout << "0.2 is stored as " << fifth << '\n';
    std::cout << "0.3 is stored as " << threeTenths << '\n';
    std::cout << "0.4 is stored as " << twoFifths << '\n';
    std::cout << "0.5 is stored as " << half << '\n';

    // Traps shown in this lesson (uncomment to see the compiler's response):
    // int worldPopulation{8'000'000'000};  // error: too large for int
    // float big{16777217};                 // error: not exactly representable

    return 0;
}