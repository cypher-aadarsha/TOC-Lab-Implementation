#include <iostream>
#include <string>

// Program 3: Suffix Check
// Checks if S2 is a suffix of S1; distinguishes proper/improper

int main() {
    std::string s1, s2;
    std::cout << "Enter string S1: ";
    std::cin >> s1;
    std::cout << "Enter string S2: ";
    std::cin >> s2;

    bool is_suffix = false;
    if (s2.length() <= s1.length()) {
        if (s1.substr(s1.length() - s2.length()) == s2) {
            is_suffix = true;
        }
    }

    if (is_suffix) {
        if (s1 == s2) {
            std::cout << "'" << s2 << "' is an IMPROPER suffix of '" << s1 << "'" << std::endl;
        } else {
            std::cout << "'" << s2 << "' is a PROPER suffix of '" << s1 << "'" << std::endl;
        }
    } else {
        std::cout << "'" << s2 << "' is NOT a suffix of '" << s1 << "'" << std::endl;
    }

    std::cout << "\nexecuted by Aadarsha Jha (023BSCIT050)" << std::endl;
    return 0;
}
