#include <iostream>
#include <string>
#include <cctype>

// Program 10: Identify Valid C Identifiers
// Rules:
// 1. Must start with a letter (A-Z, a-z) or underscore (_).
// 2. Subsequent characters can be letters, digits (0-9), or underscores.
// 3. Keywords are typically not identifiers, but we'll focus on syntax here.

bool isValidIdentifier(const std::string& str) {
    if (str.empty()) return false;

    // Check first character
    if (!isalpha(str[0]) && str[0] != '_') {
        return false;
    }

    // Check remaining characters
    for (size_t i = 1; i < str.length(); ++i) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return false;
        }
    }

    // (Optional) Check key words - omitted for simplicity in basic validation task
    return true;
}

int main() {
    std::string input;
    std::cout << "Enter a potential C identifier: ";
    std::cin >> input;

    if (isValidIdentifier(input)) {
        std::cout << "'" << input << "' is a VALID C identifier." << std::endl;
    } else {
        std::cout << "'" << input << "' is an INVALID C identifier." << std::endl;
    }

    std::cout << "\nexecuted by Aadarsha Jha (023BSCIT050)" << std::endl;
    return 0;
}
