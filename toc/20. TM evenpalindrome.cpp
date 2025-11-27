#include <bits/stdc++.h>
using namespace std;

bool isEvenPalindrome(string w) {
    int n = w.size();
    if (n % 2 != 0) return false; // odd length -> reject

    int left = 0, right = n - 1;
    while (left < right) {
        if (w[left] != w[right]) return false; // mismatch
        left++;
        right--;
    }
    return true; // all matched
}

int main() {
    vector<string> tests = {"abba", "abccba", "abcd", "aabbccbbaa", "abcba"};
    for (auto &s : tests) {
        cout << s << " -> "
             << (isEvenPalindrome(s) ? "Accepted" : "Rejected") << endl;
    }
    return 0;
}
