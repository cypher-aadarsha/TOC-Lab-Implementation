#include <iostream>
#include <string>
#include <vector>

// Program 15: Turing Machine for L = { a^n b^n c^n | n >= 1 }
// Logic (Multi-pass approach):
// 1. Mark 'a' as 'X'.
// 2. Move right to find first 'b', mark as 'Y'.
// 3. Move right to find first 'c', mark as 'Z'.
// 4. Returns start, repeat.
// 5. If all marked correctly and tape is empty of original chars, ACCEPT.

int main() {
    std::string input_str;
    std::cout << "Enter a string over {a, b, c}: ";
    std::cin >> input_str;
    
    // Use vector as tape for mutability
    std::vector<char> tape(input_str.begin(), input_str.end());
    
    if (tape.empty()) {
         std::cout << "REJECTED." << std::endl; return 0;
    }

    // Checking proper order first: all a's, then all b's, then all c's
    // Not strictly TM logic (TM discovers this during traversal), but valid for simulation
    
    while (true) {
        bool foundA = false, foundB = false, foundC = false;
        
        // Find and mark first unregistered 'a'
        for (size_t i = 0; i < tape.size(); i++) {
            if (tape[i] == 'a') {
                tape[i] = 'X'; foundA = true; break;
            } else if (tape[i] != 'X' && tape[i] != 'Y' && tape[i] != 'Z') {
                // If we see b or c before a (and logic implies we are looking for a), 
                // it might be we are done with a's. 
                break;
            }
        }
        
        // Find and mark first unregistered 'b'
        for (size_t i = 0; i < tape.size(); i++) {
             if (tape[i] == 'b' && foundA) { // Must have found A to look for matching B
                tape[i] = 'Y'; foundB = true; break;
             } 
        }

        // Find and mark first unregistered 'c'
        for (size_t i = 0; i < tape.size(); i++) {
             if (tape[i] == 'c' && foundB) { // Must have found B to look for matching C
                tape[i] = 'Z'; foundC = true; break;
             } 
        }

        if (foundA && foundB && foundC) {
            continue; // Cycle complete, try next triplet
        } else if (!foundA && !foundB && !foundC) {
            // No more triplets found.
            // Check if any original chars remain
            for (char c : tape) {
                if (c == 'a' || c == 'b' || c == 'c') {
                    std::cout << "REJECTED." << std::endl; // Leftover characters
                    std::cout << "\nexecuted by Aadarsha Jha (023BSCIT050)" << std::endl;
                    return 0;
                }
            }
            std::cout << "ACCEPTED (Matched a^n b^n c^n)." << std::endl; // All clean
            break;
        } else {
            // Incomplete triplet (e.g. found A but no B)
            std::cout << "REJECTED." << std::endl;
            break;
        }
    }

    std::cout << "\nexecuted by Aadarsha Jha (023BSCIT050)" << std::endl;
    return 0;
}
