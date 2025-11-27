#include <iostream>
#include <string>

using namespace std;

bool simulateTM(string tape) {
    int len = tape.length();

    // Must start with 'a' and end with 'b'
    if (len < 2 || tape[0] != 'a' || tape[len - 1] != 'b')
        return false;

    while (true) {
        // Step 1: Find the first 'a' to mark 'X'
        int i = 0;
        while (i < len && tape[i] != 'a') i++;
        if (i == len) break; // No more 'a'

        tape[i] = 'X'; // Mark 'a' as processed

        // Step 2: Find the first 'b' after position i to mark 'Y'
        int j = i + 1;
        while (j < len && tape[j] != 'b') j++;
        if (j == len) return false; // No matching 'b' found

        tape[j] = 'Y'; // Mark 'b' as processed
    }

    // Final check: no unprocessed 'a' or 'b' remains
    int xCount = 0, yCount = 0;
    for (char c : tape) {
        if (c == 'a' || c == 'b')
            return false; // unmatched character remains
        if (c == 'X')
            xCount++;
        if (c == 'Y')
            yCount++;
    }

    // Accept only if count of X and Y is equal and at least 1
    return (xCount > 0 && xCount == yCount);
}
// Check if input string is in the form a^+ b^+ (all a's before b's)
bool checkOrder(const string& s) {
    int i = 0;
    // Move through all a's
    while (i < s.length() && s[i] == 'a') i++;
    // Then all b's
    while (i < s.length() && s[i] == 'b') i++;
    // If i reached the end, order is correct
    return i == s.length();
}


int main() {
    string input;
    cout << "Enter the input string (a^n b^n): ";
    cin >> input;

    if (!checkOrder(input)) {
        cout << "String is rejected by the Turing Machine.\n";
        return 0;
    }

    if (simulateTM(input)) {
        cout << "String is accepted by the Turing Machine.\n";
    } else {
        cout << "String is rejected by the Turing Machine.\n";
    } 

    return 0;
}

