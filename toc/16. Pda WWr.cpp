#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isAcceptedByPDA(const string& input) {
    int n = input.length();

    // If length is odd, can't be WW^r
    if (n % 2 != 0) return false;

    stack<char> st;
    int half = n / 2;

    // Push first half onto stack
    for (int i = 0; i < half; i++) {
        char ch = input[i];
        if (ch != 'a' && ch != 'b') return false; // invalid char
        st.push(ch);
    }

    // Match second half with stack top
    for (int i = half; i < n; i++) {
        char ch = input[i];
        if (ch != 'a' && ch != 'b') return false; // invalid char

        if (st.empty()) return false;

        char top = st.top();
        st.pop();

        if (ch != top) return false;
    }

    // Accept if stack empty after matching
    return st.empty();
}

int main() {
    string input = "abba";

    if (isAcceptedByPDA(input)) {
        cout << "Accepted by PDA\n";
    } else {
        cout << "Rejected by PDA\n";
    }

    return 0;
}
