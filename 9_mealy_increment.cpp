#include <iostream>
#include <string>
#include <algorithm>

// Program 9: Mealy Machine incrementing binary number
// Input assumed to be binary string.
// Processing usually done from LSB to MSB for addition.
// Since input comes MSB first usually, we reverse, process, reverse back.
// States:
// 0: Carry = 1 (Initial state for increment)
// 1: Carry = 0 (No more carry to propagate)

int main() {
    std::string input;
    std::cout << "Enter a binary number: ";
    std::cin >> input;

    std::string output = "";
    int state = 0; // 0 represents Carry=1 effectively for +1 operation

    // Process from LSB (end of string) to MSB (start)
    for (int i = input.length() - 1; i >= 0; i--) {
        char c = input[i];
        if (state == 0) { // Carry is 1
            if (c == '0') {
                output += '1';
                state = 1; // Carry becomes 0
            } else if (c == '1') {
                output += '0';
                state = 0; // Carry remains 1
            } else {
                 std::cout << "Invalid binary string" << std::endl; return 1;
            }
        } else { // State 1: Carry is 0, just copy
             output += c;
        }
    }

    if (state == 0) {
        output += '1'; // Overflow carry
    }

    // Reverse output to get correct order
    std::reverse(output.begin(), output.end());

    std::cout << "Incremented value: " << output << std::endl;
    std::cout << "\nexecuted by Aadarsha Jha (023BSCIT050)" << std::endl;
    return 0;
}
