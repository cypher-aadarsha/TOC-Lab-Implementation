#include <iostream>
#include <string>
#include <stack>

// Program 14: PDA for L = { a^n b^n | n >= 1 }
// Logic:
// 1. Push 'a' onto stack.
// 2. When 'b' comes, pop 'a'.
// 3. If stack empty when 'b' comes, REJECT (too many b's).
// 4. If stack not empty after processing string, REJECT (too many a's).
// 5. Order must be a's then b's. (No 'a' after 'b').

int main() {
    std::string input;
    std::cout << "Enter a string string over {a, b}: ";
    std::cin >> input;

    if (input.empty()) {
        std::cout << "REJECTED (n >= 1 condition)." << std::endl;
        return 0;
    }

    std::stack<char> s;
    bool seenB = false;

    for (char c : input) {
        if (c == 'a') {
            if (seenB) {
                // 'a' appearing after 'b' is invalid for a^n b^n
                std::cout << "REJECTED (Order invalid)." << std::endl;
                std::cout << "\nexecuted by Aadarsha Jha (023BSCIT050)" << std::endl;
                return 0;
            }
            s.push(c);
        } else if (c == 'b') {
            seenB = true;
            if (s.empty()) {
                std::cout << "REJECTED (More b's than a's)." << std::endl;
                std::cout << "\nexecuted by Aadarsha Jha (023BSCIT050)" << std::endl;
                return 0;
            }
            s.pop();
        } else {
             std::cout << "Invalid character." << std::endl;
             return 1;
        }
    }

    if (s.empty() && seenB) {
        std::cout << "ACCEPTED (a^n b^n matched)." << std::endl;
    } else {
        std::cout << "REJECTED (Counts do not match)." << std::endl;
    }

    std::cout << "\nexecuted by Aadarsha Jha (023BSCIT050)" << std::endl;
    return 0;
}
