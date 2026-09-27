#include <iostream>
#include <limits>

int main()
{
    // char: a 1-byte integer that std::cout prints as a character.
    char letter{'A'};
    std::cout << "letter as a character: " << letter << '\n';
    std::cout << "letter as a number:    " << static_cast<int>(letter) << '\n';

    // Whether plain char is signed is implementation-defined.
    std::cout << std::boolalpha;
    std::cout << "char is signed here:   " << std::numeric_limits<char>::is_signed << '\n';
    std::cout << "char:          " << static_cast<int>(std::numeric_limits<char>::min())
              << " to " << static_cast<int>(std::numeric_limits<char>::max()) << '\n';
    std::cout << "signed char:   " << static_cast<int>(std::numeric_limits<signed char>::min())
              << " to " << static_cast<int>(std::numeric_limits<signed char>::max()) << '\n';
    std::cout << "unsigned char: " << static_cast<int>(std::numeric_limits<unsigned char>::min())
              << " to " << static_cast<int>(std::numeric_limits<unsigned char>::max()) << '\n';

    // The same bits, 11001000, in two types. 0b marks a binary value (topic 14).
    unsigned char byte{0b11001000};
    char sameBits{static_cast<char>(0b11001000)};
    std::cout << "11001000 as unsigned char: " << static_cast<int>(byte) << '\n';
    std::cout << "11001000 as char:          " << static_cast<int>(sameBits) << '\n';

    // bool: stored in a byte, printed as 1 or 0 unless boolalpha is set.
    bool isReady{true};
    std::cout << std::noboolalpha << "isReady (default):   " << isReady << '\n';
    std::cout << std::boolalpha << "isReady (boolalpha): " << isReady << '\n';
    std::cout << "sizeof(bool): " << sizeof(bool) << '\n';

    // Traps shown in this lesson (uncomment to see the compiler's response):
    // char big{200};     // error: 200 does not fit a signed char
    // bool flag{5};      // error: a bool can only be 0 or 1
    // void nothing;      // error: no object can have type void

    return 0;
}