#include <iostream>
#include <vector>
using namespace std;
int main() {
 int memSize, pageSize, n;
 cout << "Enter total memory size: ";
 cin >> memSize;
 cout << "Enter page size: ";
 cin >> pageSize;
 cout << "Enter number of processes: ";
 cin >> n;
 vector<int> proc(n);
 for (int i = 0; i < n; i++) {
 cout << "Enter memory required for process " << i + 1 << ": ";
 cin >> proc[i];
 }
 int frames = memSize / pageSize;
 cout << "\nTotal frames in memory: " << frames << endl;
 for (int i = 0; i < n; i++) {
 int pages = (proc[i] + pageSize - 1) / pageSize;
 if (pages <= frames) {
 cout << "Process " << i + 1 << " allocated with " << pages << " pages\n";
 frames -= pages;
 } else {
 cout << "Process " << i + 1 << " cannot be allocated (not enough frames)\n";
 }
 }
 return 0;
}