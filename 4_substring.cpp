#include <iostream>
#include <string>

// Program 4: Substring Check
// Checks if S2 is a substring of S1; distinguishes proper/improper

int main() {
    std::string s1, s2;
    std::cout << "Enter string S1: ";
    std::cin >> s1;
    std::cout << "Enter string S2: ";
    std::cin >> s2;

    size_t found = s1.find(s2);
    if (found != std::string::npos) {
        if (s1 == s2) {
            std::cout << "'" << s2 << "' is an IMPROPER substring of '" << s1 << "'" << std::endl;
        } else {
            std::cout << "'" << s2 << "' is a PROPER substring of '" << s1 << "'" << std::endl;
        }
    } else {
        std::cout << "'" << s2 << "' is NOT a substring of '" << s1 << "'" << std::endl;
    }

    std::cout << "\nexecuted by Aadarsha Jha (023BSCIT050)" << std::endl;
    return 0;
}
