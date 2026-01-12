#include <iostream>
#include <string>

// Program 11: Identify Valid Gmail
// Rules simplified:
// 1. Ends with "@gmail.com"
// 2. Has at least 6 characters before "@".

bool isValidGmail(const std::string& str) {
    std::string domain = "@gmail.com";
    if (str.length() <= domain.length()) return false;

    // Check suffix
    if (str.substr(str.length() - domain.length()) != domain) {
        return false;
    }

    // Check username length (min 6 chars recommended for gmail)
    std::string username = str.substr(0, str.length() - domain.length());
    if (username.length() < 6) return false;

    return true;
}

int main() {
    std::string input;
    std::cout << "Enter a Gmail address: ";
    std::cin >> input;

    if (isValidGmail(input)) {
        std::cout << "'" << input << "' is a VALID Gmail address." << std::endl;
    } else {
        std::cout << "'" << input << "' is an INVALID Gmail address." << std::endl;
    }

    std::cout << "\nexecuted by Aadarsha Jha (023BSCIT050)" << std::endl;
    return 0;
}
