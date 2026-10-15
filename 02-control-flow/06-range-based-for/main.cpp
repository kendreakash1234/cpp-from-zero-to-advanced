#include <iostream>
#include <string>

int main()
{
    std::string word;
    if (!(std::cin >> word)) {
        std::cerr << "invalid input\n";
        return 1;
    }

    // auto& makes c the actual character, so '*' is written into word.
    // With auto c (a copy), word would stay unchanged.
    int vowels{};
    int consonants{};
    for (auto& c : word) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            c = '*';
            ++vowels;
        } else if (c >= 'a' && c <= 'z') {
            ++consonants;
        }
    }
    std::cout << "word:       " << word << '\n';
    std::cout << "vowels:     " << vowels << '\n';
    std::cout << "consonants: " << consonants << '\n';

    // A braced list is a range too.
    int sum{};
    for (int x : {3, 1, 4, 1, 5}) {
        sum += x;
    }
    std::cout << "sum:        " << sum << '\n';

    // A string literal is a char array that ends with '\0', and the loop visits it.
    int literalChars{};
    for ([[maybe_unused]] char c : "hello") {
        ++literalChars;
    }
    int stringChars{};
    for ([[maybe_unused]] char c : std::string{"hello"}) {
        ++stringChars;
    }
    std::cout << "\"hello\" literal: " << literalChars << ", std::string: " << stringChars << '\n';

    return 0;

    // Traps shown in this lesson:
    // for (auto c : word) { c = '*'; }     // copy: word unchanged, no warning
    // const std::string s{...}; for (auto& c : s) { c = '*'; }
    //                                       // error: assignment of read-only reference 'c'
    // for (int x : v) { v.push_back(4); }   // UB: ASan reports heap-use-after-free
}