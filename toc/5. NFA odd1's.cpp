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
            else if (state == 1 && ch == '1') state = 0;
            else state = -1;
    }
    
    if(state==1)
    cout<<"String accepted! yay";
    else
    cout<<"String rejected";
}
