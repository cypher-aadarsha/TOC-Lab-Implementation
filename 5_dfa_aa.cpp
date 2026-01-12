#include <iostream>
#include <string>

// Program 5: DFA for substring "aa" over {a, b}
// States:
// 0: Start, no 'a' seen recently
// 1: Seen one 'a'
// 2: Seen 'aa' (Accepting / Trap state)

int main() {
    std::string input;
    std::cout << "Enter a string over {a, b}: ";
    std::cin >> input;

    int state = 0;
    for (char c : input) {
        switch (state) {
            case 0:
                if (c == 'a') state = 1;
                else if (c == 'b') state = 0;
                else {
                     std::cout << "Invalid character: " << c << std::endl;
                     return 1;
                }
                break;
            case 1:
                if (c == 'a') state = 2;
                else if (c == 'b') state = 0;
                else {
                    std::cout << "Invalid character: " << c << std::endl;
                    return 1;
                }
                break;
            case 2:
                // Once valid assignment, stay in state 2 (Trap state for acceptance)
                if (c == 'a' || c == 'b') state = 2;
                else {
                     std::cout << "Invalid character: " << c << std::endl;
                     return 1;
                }
                break;
        }
    }

    if (state == 2) {
        std::cout << "String ACCEPTED: Contains substring 'aa'." << std::endl;
    } else {
        std::cout << "String REJECTED: Does not contain substring 'aa'." << std::endl;
    }

    std::cout << "\nexecuted by Aadarsha Jha (023BSCIT050)" << std::endl;
    return 0;
}
