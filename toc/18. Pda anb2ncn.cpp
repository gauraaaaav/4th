#include <iostream>
#include <stack>
#include <string>

using namespace std;

// PDA simulation for L = { a^n b^2n c^n | n >= 1 }
bool isAccepted(string input) {
    stack<char> st;
    int i = 0, len = input.length();
    int a_count = 0, b_count = 0, c_count = 0;

    // Step 1: process 'a's → just count them
    while (i < len && input[i] == 'a') {
        a_count++;
        i++;
    }
    if (a_count == 0) return false;  // must have at least 1 'a'

    // Step 2: process 'b's → for every 2 b's, push one Z
    int b_seen = 0;
    while (i < len && input[i] == 'b') {
        b_count++;
        b_seen++;

        if (b_seen == 2) {
            st.push('Z');  // one Z for each pair of b's
            b_seen = 0;
        }
        i++;
    }

    // Must be exactly 2n b's
    if (b_count != 2 * a_count) return false;

    // Step 3: process 'c's → pop one Z per c
    while (i < len && input[i] == 'c') {
        c_count++;
        if (st.empty() || st.top() != 'Z') return false;
        st.pop();
        i++;
    }

    // c count must equal a count
    if (c_count != a_count) return false;

    // Final check: all input consumed & stack empty
    return (i == len && st.empty());
}

int main() {
    string input;
    cout << "Enter the string: ";
    cin >> input;

    if (isAccepted(input)) {
        cout << "String is accepted by the PDA.\n";
    } else {
        cout << "String is rejected by the PDA.\n";
    }

    return 0;
}
