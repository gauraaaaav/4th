#include <iostream>
#include <vector>
#include <string>
using namespace std;
void removeLeftRecursion(string nonTerminal, vector<string> productions) {
    vector<string> alpha; 
    vector<string> beta;  

    for (string prod : productions) {
        if (prod[0] == nonTerminal[0]) {
            alpha.push_back(prod.substr(1)); 
        } else {
            beta.push_back(prod);
        }
    }

    if (alpha.empty()) {
        cout << nonTerminal << " -> ";
        for (int i = 0; i < productions.size(); i++) {
            cout << productions[i];
            if (i != productions.size() - 1) cout << " | ";
        }
        cout << endl;
    } else {
        string newNonTerminal = nonTerminal + "'";
        cout << nonTerminal << " -> ";
        for (int i = 0; i < beta.size(); i++) {
            cout << beta[i] << newNonTerminal;
            if (i != beta.size() - 1) cout << " | ";
        }
        cout << endl;
        cout << newNonTerminal << " -> ";
        for (int i = 0; i < alpha.size(); i++) {
            cout << alpha[i] << newNonTerminal;
            if (i != alpha.size() - 1) cout << " | ";
        }
        cout << " | E" << endl;
    }
}

int main() {
    string E = "E";
    vector<string> productions_E = { "E+T", "T" };
    removeLeftRecursion(E, productions_E);
    string T = "T";
    vector<string> productions_T = { "T*F", "F" };
    removeLeftRecursion(T, productions_T);
    string F = "F";
    vector<string> productions_F = { "(E)", "ID" };
    removeLeftRecursion(F, productions_F);

    return 0;
}
