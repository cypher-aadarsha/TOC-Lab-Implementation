#include <iostream>
#include <string>
#include <regex>

// Program 12: Identify Valid MAC Address
// Format: HH:HH:HH:HH:HH:HH where H is a hex digit (0-9, A-F, a-f)

bool isValidMac(const std::string& str) {
    // Regex for MAC address
    // ^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$
    // Supports both : and - as separators
    const std::regex macRegex("^([0-9A-Fa-f]{2}[:]){5}([0-9A-Fa-f]{2})$");
    return std::regex_match(str, macRegex);
}

int main() {
    std::string input;
    std::cout << "Enter a MAC address (e.g., 00:1A:2B:3C:4D:5E): ";
    std::cin >> input;

    if (isValidMac(input)) {
        std::cout << "'" << input << "' is a VALID MAC address." << std::endl;
    } else {
        std::cout << "'" << input << "' is an INVALID MAC address." << std::endl;
    }

    std::cout << "\nexecuted by Aadarsha Jha (023BSCIT050)" << std::endl;
    return 0;
}
