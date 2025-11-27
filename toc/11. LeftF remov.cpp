#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Original productions for E
    vector<string> productions = {"iEtsAs", "iEts"};

    // Step 1: Find common prefix
    string prefix = productions[0];
    for (int i = 1; i < productions.size(); i++) {
        int j = 0;
        // Find common prefix between prefix and productions[i]
        while (j < prefix.size() && j < productions[i].size() && prefix[j] == productions[i][j]) {
            j++;
        }
        prefix = prefix.substr(0, j);
    }

    cout << "Common prefix for E's productions: " << prefix << endl;

    // Step 2: Extract suffixes after the common prefix
    vector<string> suffixes;
    for (auto &prod : productions) {
        if (prod.size() > prefix.size()) {
            suffixes.push_back(prod.substr(prefix.size()));
        } else {
            // empty suffix means epsilon
            suffixes.push_back("e");
        }
    }

    // Step 3: Print left-factored grammar
    cout << "After removing left factoring:\n";
    cout << "E -> " << prefix << "E'" << endl;
    cout << "E' -> ";
    for (int i = 0; i < suffixes.size(); i++) {
        cout << suffixes[i];
        if (i != suffixes.size() - 1) cout << " | ";
    }
    cout << endl;
    cout << "A -> a\n";

    return 0;
}
