#include <bits/stdc++.h>
using namespace std;

// Function to check if a string is odd palindrome using TM simulation
bool isOddPalindrome(string tape) {
    int n = tape.size();

    // Step 1: Check odd length
    if (n % 2 == 0) return false;

    int left = 0, right = n - 1;

    // Step 2: Simulate TM marking process
    while (left < right) {
        if (tape[left] != tape[right]) {
            return false; // reject if mismatch
        }
        left++;
        right--;
    }

    // Step 3: If middle element remains, it's an odd palindrome
    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isOddPalindrome(input))
        cout << "ACCEPTED: Odd Palindrome" << endl;
    else
        cout << "REJECTED" << endl;

    return 0;
}
