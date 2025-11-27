#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isAcceptedByPDA(const string& input) {
    stack<char> st;
    int i = 0;
    int n = input.length();

    // Phase 1: Read 'a's and push to stack
    while (i < n && input[i] == 'a') {
        st.push('a');
        i++;
    }

    // There must be at least one 'a'
    if (st.empty()) return false;

    // Phase 2: Read 'b's and pop from stack
    while (i < n && input[i] == 'b') {
        if (st.empty()) return false; // more b's than a's
        st.pop();
        i++;
    }

    // Input should end after b's and stack should be empty
    return (i == n && st.empty());
}

int main() {
    string input = "aaaabbbb";
    cout<<"String:"<<input<<endl;

    if (isAcceptedByPDA(input)) {
        cout << "Accepted by PDA\n";
    } else {
        cout << "Rejected by PDA\n";
    }

    return 0;
}
