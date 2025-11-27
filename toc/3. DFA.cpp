#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter a binary string: ";
    cin >> input;

    int state = 0;

    for (char ch : input) {
        if (state == 0) {
            if (ch == '1') state = 1;
            else if (ch == '0') state = 3;
        } else if (state == 1) {
            if (ch == '0') state = 2;      // 10
            else if (ch == '1') state = 5;
            else state = -1;
        } else if (state == 2) {
            state = -1;
        } else if (state == 3) {
            if (ch == '1') state = 2;      // 01
            else if (ch == '0') state = 4;
            else state = -1;
        } else if (state == 4) {
            if (ch == '1') state = 2;      // 001
            else state = -1;
        } else if (state == 5) {
            if (ch == '0') state = 2;      // 110
            else state = -1;
        } else {
            state = -1;
        }

        if (state == -1)
            break;
    }

    if (state == 2)
        cout << "String accepted! yay";
    else
        cout << "String rejected";

    return 0;
}
