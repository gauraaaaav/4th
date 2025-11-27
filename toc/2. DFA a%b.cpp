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
            if (ch == 'a') state = 1;
            else state = -1;
        } else if (state == 1) {
            if (ch == 'a') state = 1;
            else if(ch == 'b') state = 2;
        } else if (state == 2) {
            if (ch == 'a') state = 1;
            else if(ch == 'b') state = 2;
        }
    }
    
    if(state==2)
    cout<<"String accepted! yay";
    else
    cout<<"String rejected";
}
