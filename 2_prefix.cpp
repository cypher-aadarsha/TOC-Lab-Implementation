#include <iostream>
#include <string>

// Program 2: Prefix Check
// Checks if S2 is a prefix of S1

bool isPrefix(const std::string& s1, const std::string& s2) {
    if (s2.length() > s1.length()) {
        return false;
    }
    return s1.substr(0, s2.length()) == s2;
}

int main() {
    std::string s1, s2;
    std::cout << "Enter string S1: ";
    std::cin >> s1;
    std::cout << "Enter string S2: ";
    std::cin >> s2;

    if (isPrefix(s1, s2)) {
        std::cout << "'" << s2 << "' IS a prefix of '" << s1 << "'" << std::endl;
    } else {
        std::cout << "'" << s2 << "' is NOT a prefix of '" << s1 << "'" << std::endl;
    }

    std::cout << "\nexecuted by Aadarsha Jha (023BSCIT050)" << std::endl;
    return 0;
}
