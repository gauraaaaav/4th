#include <iostream>
#include <vector>
using namespace std;
int main() {
 int nBlocks, nProcesses;
 cout << "Enter number of memory blocks: ";
 cin >> nBlocks;
 cout << "Enter number of processes: ";
 cin >> nProcesses;
 vector<int> blockSize(nBlocks), processSize(nProcesses), allocation(nProcesses, -1);
 cout << "Enter block sizes:\n";
 for (int i = 0; i < nBlocks; i++) cin >> blockSize[i];
 cout << "Enter process sizes:\n";
 for (int i = 0; i < nProcesses; i++) cin >> processSize[i];
 for (int i = 0; i < nProcesses; i++) {
 int worstIdx = -1;
 for (int j = 0; j < nBlocks; j++) {
 if (blockSize[j] >= processSize[i]) {
 if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
 worstIdx = j;
 }
 }
 if (worstIdx != -1) {
 allocation[i] = worstIdx;
 blockSize[worstIdx] -= processSize[i];
 }
 }
 cout << "\nProcess No.\tProcess Size\tBlock No.\n";
 for (int i = 0; i < nProcesses; i++) {
 cout << i+1 << "\t\t" << processSize[i] << "\t\t";
 if (allocation[i] != -1) cout << allocation[i] + 1;
 else cout << "Not Allocated";
 cout << "\n";
 }
 return 0;
}