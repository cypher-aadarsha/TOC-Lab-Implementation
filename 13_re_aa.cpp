#include <iostream>
#include <string>
#include <regex>

// Program 13: Implement RE for structure (a+b)*aa(a+b)*
// Equivalent to finding substring "aa" anywhere in a string of {a,b}.

int main() {
    std::string input;
    std::cout << "Enter a string over {a, b}: ";
    std::cin >> input;

    // Regex pattern: ^(a|b)*aa(a|b)*$
    const std::regex pattern("^[ab]*aa[ab]*$");

    if (std::regex_match(input, pattern)) {
        std::cout << "String MATCHES the pattern (a+b)*aa(a+b)*" << std::endl;
    } else {
        std::cout << "String does NOT match the pattern." << std::endl;
    }

    std::cout << "\nexecuted by Aadarsha Jha (023BSCIT050)" << std::endl;
    return 0;
}
