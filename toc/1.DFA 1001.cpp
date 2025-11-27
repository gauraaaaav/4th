#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter a binary string: ";
    cin >> input;

    int state = 0;
    for(char ch:input){
	        if (state == 0) {
            if (ch == '1') state = 1;
            else state = -1;
        } else if (state == 1) {
            if (ch == '0') state = 2;
            else state = -1;
        } else if (state == 2) {
            if (ch == '0') state = 3;
            else state = -1;
        } else if (state == 3) {
            if (ch == '1') state = 4;
            else state = -1;
        } else {
            state = -1; 
        }
    }
    
    if(state==4)
    cout<<"String accepted! yay";
    else
    cout<<"String rejected";
}
