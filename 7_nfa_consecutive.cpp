#include <iostream>
#include <string>

// Program 7: NFA for "two consecutive a's OR two consecutive b's"
// Since we are coding, we can implement the logic of the DFA equivalent or simulate NFA paths.
// DFA logic is simpler:
// States to track:
// 0: Start / Nothing special
// 1: Seen 'a', waiting for another 'a'
// 2: Seen 'b', waiting for another 'b'
// 3: Accepted (Seen 'aa' or 'bb')

int main() {
    std::string input;
    std::cout << "Enter a string over {a, b}: ";
    std::cin >> input;

    int state = 0;
    for (char c : input) {
        switch (state) {
            case 0:
                if (c == 'a') state = 1;
                else if (c == 'b') state = 2;
                else { std::cout << "Invalid char"; return 1; }
                break;
            case 1: // Last char was 'a'
                if (c == 'a') state = 3; // 'aa' found
                else if (c == 'b') state = 2; // 'ab', now waiting for 'b' pair
                break;
            case 2: // Last char was 'b'
                if (c == 'a') state = 1; // 'ba', now waiting for 'a' pair
                else if (c == 'b') state = 3; // 'bb' found
                break;
            case 3:
                // Trap state (Accepted)
                break;
        }
    }

    if (state == 3) {
        std::cout << "String ACCEPTED (Contains 'aa' or 'bb')." << std::endl;
    } else {
        std::cout << "String REJECTED." << std::endl;
    }

    std::cout << "\nexecuted by Aadarsha Jha (023BSCIT050)" << std::endl;
    return 0;
}
