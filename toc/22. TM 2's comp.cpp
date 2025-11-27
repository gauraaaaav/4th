#include <bits/stdc++.h>
using namespace std;

// Function to simulate Turing Machine for Two's Complement check
bool isTwosComplement(string tape, int fixedLength) {
    // Step 1: Check length
    if (tape.size() != fixedLength) return false;

    // Step 2: Check if all characters are 0 or 1
    for (char c : tape) {
        if (c != '0' && c != '1') return false;
    }

    // Step 3: If passes checks ? Accept
    return true;
}

int main() {
    string input;
    int n;

    cout << "Enter fixed length (number of bits): ";
    cin >> n;

    cout << "Enter binary string: ";
    cin >> input;

    if (isTwosComplement(input, n))
        cout << "ACCEPTED: Valid Two's Complement Representation" << endl;
    else
        cout << "REJECTED" << endl;

    return 0;
}
