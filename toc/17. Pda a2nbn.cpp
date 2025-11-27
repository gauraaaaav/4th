#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isAccepted(string input) {
    stack<char> st;
    int i = 0;
    int len = input.length();
    int a_count = 0;

    // First phase: process a's
    while (i < len && input[i] == 'a') {
        a_count++;
        i++;
    }

    // Check if number of a's is even
    if (a_count % 2 != 0 || a_count == 0) {
        return false;
    }

    int num_pairs = a_count / 2;

    // Push one X for each pair of a's
    for (int j = 0; j < num_pairs; j++) {
        st.push('X');
    }

    // Second phase: process b's
    while (i < len && input[i] == 'b') {
        if (st.empty()) {
            return false;
        }
        st.pop();
        i++;
    }

    // Final checks
    if (i == len && st.empty()) {
        return true;  // All input consumed and stack is empty
    } else {
        return false; // Either input left or stack not empty
    }
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
