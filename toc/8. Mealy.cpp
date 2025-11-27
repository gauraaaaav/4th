
#include <iostream>
using namespace std;

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;

    // Define states
    enum State { q0, q1, q2, q3, q4, q5 };
    State current = q0;

    bool accepted = false;

    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];
        int output = 0; // default output

        switch (current) {
            case q0:
                if (ch == 'a') {
                    current = q1;
                    output = 0;
                } else {
                    current = q0;
                    output = 0;
                }
                break;
            case q1:
                if (ch == 'b') {
                    current = q2;
                    output = 0;
                } else if (ch == 'a') {
                    current = q1;
                    output = 0;
                } else {
                    current = q0;
                }
                break;
            case q2:
                if (ch == 'b') {
                    current = q3;
                    output = 0;
                } else if (ch == 'a') {
                    current = q1;
                    output = 0;
                } else {
                    current = q0;
                }
                break;
            case q3:
                if (ch == 'a') {
                    current = q4;
                    output = 0;
                } else if (ch == 'b') {
                    current = q0;
                    output = 0;
                } else {
                    current = q0;
                }
                break;
            case q4:
                if (ch == 'a') {
                    current = q5;
                    output = 1; // found full "abbaa"
                } else if (ch == 'b') {
                    current = q2;
                    output = 0;
                } else {
                    current = q0;
                }
                break;
            case q5:
                // after match, extra input ignored
                current = q5;
                output = 0;
                break;
        }

        // Check if we produced output=1 on this transition
        if (output == 1)
            accepted = true;
    }

    if (accepted)
        cout << "Accepted" << endl;
    else
        cout << "Rejected" << endl;

    return 0;
}
