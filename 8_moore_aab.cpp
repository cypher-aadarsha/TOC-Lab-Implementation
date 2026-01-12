#include <iostream>
#include <string>

// Program 8: Moore Machine counting substring "aab"
// Count is printed at the end.
// States:
// 0: Start, nothing matched
// 1: Seen 'a'
// 2: Seen 'aa'
// 3: Seen 'aab' (Count increments here, acts as accepting trigger, then transitions)
//
// Moore Machine output: Associated with state.
// We can simply count how many times we enter state 3.

int main() {
    std::string input;
    std::cout << "Enter a string over {a, b}: ";
    std::cin >> input;

    int state = 0;
    int count = 0;

    for (char c : input) {
        switch (state) {
            case 0:
                if (c == 'a') state = 1;
                else state = 0;
                break;
            case 1:
                if (c == 'a') state = 2;
                else state = 0;
                break;
            case 2:
                if (c == 'a') state = 2; // aa -> a (still 2 a's seen effectively)
                else if (c == 'b') {
                    state = 3;
                    count++; // Output '1' on entering state 3
                }
                break;
            case 3:
                // After 'aab'
                if (c == 'a') state = 1;
                else state = 0; // 'aabb' -> restart
                break;
        }
    }

    std::cout << "The substring 'aab' occurred " << count << " times." << std::endl;
    std::cout << "\nexecuted by Aadarsha Jha (023BSCIT050)" << std::endl;
    return 0;
}
