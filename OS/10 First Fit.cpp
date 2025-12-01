#include <iostream>
#include <vector>
using namespace std;
int main() {
 int n, m;
 cout << "Enter number of memory blocks: ";
 cin >> n;
 vector<int> block(n);
 cout << "Enter sizes of blocks: ";
 for (int i = 0; i < n; i++) cin >> block[i];
 cout << "Enter number of processes: ";
 cin >> m;
 vector<int> process(m);
 cout << "Enter sizes of processes: ";
 for (int i = 0; i < m; i++) cin >> process[i];
 cout << "\nFIRST FIT Allocation:\n";
 for (int i = 0; i < m; i++) {
 bool allocated = false;
 for (int j = 0; j < n; j++) {
 if (block[j] >= process[i]) {
 cout << "Process " << i + 1 << " allocated to Block " << j + 1 << endl;
 block[j] -= process[i];
 allocated = true;
 break;
 }
 }
 if (!allocated) {
 cout << "Process " << i + 1 << " not allocated\n";
 }
 }
 return 0;
}