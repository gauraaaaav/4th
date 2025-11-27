
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

        switch (current) {
            case q0:
                if (ch == 'a')
                    current = q1;
                else
                    current = q0; // or use invalid state if you prefer
                break;
            case q1:
                if (ch == 'b')
                    current = q2;
                else
                    current = q0;
                break;
            case q2:
                if (ch == 'a')
                    current = q3;
                else
                    current = q0;
                break;
            case q3:
                if (ch == 'b')
                    current = q4;
                else
                    current = q0;
                break;
            case q4:
                if (ch == 'a')
                    current = q5;
                else
                    current = q0;
                break;
            case q5:
                // After reaching q5, any extra input makes it invalid
                current = q0;
                break;
        }
    }

    // Check if final state is q5
    if (current == q5)
        accepted = true;

    if (accepted)
        cout << "Accepted" << endl;
    else
        cout << "Rejected" << endl;

    return 0;
}

