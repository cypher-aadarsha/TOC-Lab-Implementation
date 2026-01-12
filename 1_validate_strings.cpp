#include <iostream>
#include <string>
#include <regex>

// Program 1: Validate Strings
// Validates if a string consists only of characters 'a' and 'b'

bool isValidString(const std::string& str) {
    for (char c : str) {
        if (c != 'a' && c != 'b') {
            return false;
        }
    }
    return true;
}

int main() {
    std::string input;
    std::cout << "Enter a string to validate (alphabet {a, b}): ";
    if (std::cin >> input) {
        if (isValidString(input)) {
            std::cout << "The string '" << input << "' is VALID over {a, b}." << std::endl;
        } else {
            std::cout << "The string '" << input << "' is INVALID over {a, b}." << std::endl;
        }
    } else {
        std::cout << "No input provided." << std::endl;
    }

    std::cout << "\nexecuted by Aadarsha Jha (023BSCIT050)" << std::endl;
    return 0;
}
