#include <iostream>
#include <string>
#include <regex>
using namespace std;

// DFA function
bool dfa_accepts_1001(const string &input) {
    int state = 0;
    for (char c : input) {
        switch (state) {
            case 0: state = (c == '1') ? 1 : 5; break;
            case 1: state = (c == '0') ? 2 : 5; break;
            case 2: state = (c == '0') ? 3 : 5; break;
            case 3: state = (c == '1') ? 4 : 5; break;
            case 4: state = 5; break; // already accepted, any extra char ? dead
            case 5: return false; // trap state
        }
    }
    return (state == 4);
}

int main() {
    string str;
    cout << "Enter a binary string: ";
    cin >> str;

    // Using DFA
    if (dfa_accepts_1001(str))
        cout << "Accepted by DFA" << endl;
    else
        cout << "Rejected by DFA" << endl;

    // Using Regular Expression
    regex re("^1001$");
    if (regex_match(str, re))
        cout << "Accepted by Regular Expression" << endl;
    else
        cout << "Rejected by Regular Expression" << endl;

    return 0;
}
