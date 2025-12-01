#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// ---------- Single Level Directory ----------
void singleLevel() {
    int n;
    cout << "Enter number of files: ";
    cin >> n;
    vector<string> files;
    for (int i = 0; i < n; i++) {
        string fname;
        cout << "Enter file name: ";
        cin >> fname;
        files.push_back(fname);
    }
    cout << "\nFiles in Directory:\n";
    for (auto &f : files) cout << f << endl;
}

// ---------- Two Level Directory ----------
void twoLevel() {
    int users;
    cout << "Enter number of users: ";
    cin >> users;
    map<string, vector<string>> dir;
    for (int i = 0; i < users; i++) {
        string uname;
        cout << "Enter user name: ";
        cin >> uname;
        int fcount;
        cout << "Enter number of files for " << uname << ": ";
        cin >> fcount;
        vector<string> files;
        for (int j = 0; j < fcount; j++) {
            string fname;
            cout << "Enter file name: ";
            cin >> fname;
            files.push_back(fname);
        }
        dir[uname] = files;
    }
    cout << "\nTwo Level Directory:\n";
    for (auto &u : dir) {
        cout << u.first << ":\n";
        for (auto &f : u.second) cout << "  " << f << endl;
    }
}

// ---------- Hierarchical Directory ----------
struct Directory {
    string name;
    vector<string> files;
    vector<Directory> subdirs;
};

void display(Directory d, string indent="") {
    cout << indent << d.name << "/\n";
    for (auto &f : d.files) cout << indent << "  " << f << endl;
    for (auto &sd : d.subdirs) display(sd, indent + "  ");
}

void hierarchical() {
    Directory root;
    root.name = "root";
    root.files = {"file1", "file2"};
    Directory sub1; sub1.name = "subdir1"; sub1.files = {"a.txt"};
    Directory sub2; sub2.name = "subdir2"; sub2.files = {"b.txt"};
    root.subdirs.push_back(sub1);
    root.subdirs.push_back(sub2);
    cout << "\nHierarchical Directory Structure:\n";
    display(root);
}

// ---------- Main ----------
int main() {
    int choice;
    cout << "Choose a technique to simulate:\n";
    cout << "1. Single Level Directory\n";
    cout << "2. Two Level Directory\n";
    cout << "3. Hierarchical Directory\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch(choice) {
        case 1: singleLevel(); break;
        case 2: twoLevel(); break;
        case 3: hierarchical(); break;
        default: cout << "Invalid choice" << endl;
    }
    return 0;
}
