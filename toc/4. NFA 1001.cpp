#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter a binary string: ";
    cin >> input;

    int state = 0;
    for(char ch:input){
	        if (state == 0 && ch == '1') state = 1;
            else if (state == 1 && ch == '0') state = 2;
            else if (state == 2 && ch == '0') state = 3;
            else if (state == 3 && ch == '1') state = 4;
            else state = -1;
    }
    
    if(state==4 && input.length() == 4)
    cout<<"String accepted! yay";
    else
    cout<<"String rejected";
}
