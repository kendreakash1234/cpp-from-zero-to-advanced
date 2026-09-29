#include <iostream>

int main()
{
    // const: read-only after initialization, so it must be initialized here.
    const int maxItems{50};
    const double taxRate{0.18};
    const char currency{'$'};

    // Input needs a modifiable variable; copy it into a const afterwards.
    int quantityInput{};
    std::cout << "Enter the quantity: ";
    std::cin >> quantityInput;
    const int orderedQuantity{quantityInput};   // value known only at run time

    std::cout << "max items:        " << maxItems << '\n';
    std::cout << "tax rate:         " << taxRate << '\n';
    std::cout << "currency:         " << currency << '\n';
    std::cout << "ordered quantity: " << orderedQuantity << '\n';

    // Traps shown in this lesson (uncomment to see the compiler's response):
    // const int limit;          // error: uninitialized 'const limit'
    // maxItems = 60;            // error: assignment of read-only variable 'maxItems'
    // maxItems += 1;            // error: assignment of read-only variable 'maxItems'
    // std::cin >> maxItems;     // error: no match for 'operator>>' ... discards qualifiers

    return 0;
}