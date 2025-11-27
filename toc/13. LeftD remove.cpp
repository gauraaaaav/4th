#include <iostream>
#include <string>

using namespace std;
void replaceLeftmostS(string &expr, const string &replacement) {
    size_t pos = expr.find('S');
    if (pos != string::npos) {
        expr.replace(pos, 1, replacement);
    }
}

void leftmostDerivation() {
    string expr = "S";
    cout << "Leftmost derivation steps for the string '-(ID*ID)+ID':\n";
    cout << "1: " << expr << "\n";
    replaceLeftmostS(expr, "S+S");
    cout << "2: " << expr << "\n";
    replaceLeftmostS(expr, "-S");
    cout << "3: " << expr << "\n";
    replaceLeftmostS(expr, "(S)");
    cout << "4: " << expr << "\n";
    replaceLeftmostS(expr, "S*S");
    cout << "5: " << expr << "\n";
    replaceLeftmostS(expr, "ID");
    cout << "6: " << expr << "\n";
    replaceLeftmostS(expr, "ID");
    cout << "7: " << expr << "\n";
    replaceLeftmostS(expr, "ID");
    cout << "8: " << expr << "\n";
}

int main() {
    leftmostDerivation();
    return 0;
}
