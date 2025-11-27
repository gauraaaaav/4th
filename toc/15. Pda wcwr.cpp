#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isAcceptedByPDA(const string& input) {
    stack<char> st;
    int i = 0;
    int n = input.length();

    // Push phase: push chars onto stack until 'c' is found
    while (i < n && input[i] != '0') {
        char ch = input[i];
        if (ch != '0' && ch != '1') return false; // only 0 or 1 allowed before c
        st.push(ch);
        i++;
    }

    // Check if 'c' is present and not at start or end
    if (i == 0 || i == n-1) return false;
    if (input[i] != '0') return false;

    i++; // skip 'c'

    // Pop and match phase: match W^r
    while (i < n) {
        if (st.empty()) return false; // more chars after c than in stack
        char top = st.top();
        st.pop();
        if (input[i] != top) return false; // mismatch
        i++;
    }

    // Accept if stack empty at end
    return st.empty();
}

int main() {
    string input = "11011";

    if (isAcceptedByPDA(input)) {
        cout << "Accepted by PDA\n";
    } else {
        cout << "Rejected by PDA\n";
    }

    return 0;
}
