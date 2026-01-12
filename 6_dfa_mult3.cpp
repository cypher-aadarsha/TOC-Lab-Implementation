#include <iostream>
#include <string>

// Program 6: DFA for "count of 0s is multiple of 3 OR count of 1s is multiple of 3"
// We need to track count of 0s mod 3 AND count of 1s mod 3.
// State can be represented as pair (c0, c1) where c0 = %3 of 0s, c1 = %3 of 1s.
// Total states: 3 * 3 = 9.
// Start state: (0, 0)
// Accepting states: Any (c0, c1) where c0 == 0 OR c1 == 0.

int main() {
    std::string input;
    std::cout << "Enter a string over {0, 1}: ";
    std::cin >> input;

    int c0 = 0; // count of 0s mod 3
    int c1 = 0; // count of 1s mod 3

    for (char c : input) {
        if (c == '0') {
            c0 = (c0 + 1) % 3;
        } else if (c == '1') {
            c1 = (c1 + 1) % 3;
        } else {
            std::cout << "Invalid character: " << c << std::endl;
            return 1;
        }
    }

    // Check acceptance condition
    if (c0 == 0 || c1 == 0) {
        std::cout << "String ACCEPTED (0s multiple of 3 OR 1s multiple of 3)." << std::endl;
    } else {
        std::cout << "String REJECTED." << std::endl;
    }

    std::cout << "\nexecuted by Aadarsha Jha (023BSCIT050)" << std::endl;
    return 0;
}
