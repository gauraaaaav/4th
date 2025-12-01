#include <iostream>
#include <vector>
using namespace std;

void sequentialAllocation(int n) {
    vector<int> blocks(n, 0);
    int start, len;
    cout << "Enter starting block and length: ";
    cin >> start >> len;
    if (start + len > n) {
        cout << "Allocation not possible!\n";
        return;
    }
    for (int i = start; i < start + len; i++) blocks[i] = 1;
    cout << "Blocks allocated from " << start << " to " << start + len - 1 << endl;
}

void indexedAllocation(int n) {
    vector<int> blocks(n, 0);
    int indexBlock, count;
    cout << "Enter index block: ";
    cin >> indexBlock;
    cout << "Enter number of blocks to allocate: ";
    cin >> count;
    vector<int> allocated(count);
    cout << "Enter block numbers: ";
    for (int i = 0; i < count; i++) {
        cin >> allocated[i];
        if (allocated[i] >= n) {
            cout << "Invalid block number!\n";
            return;
        }
        blocks[allocated[i]] = 1;
    }
    cout << "Index Block: " << indexBlock << "\nBlocks: ";
    for (int b : allocated) cout << b << " ";
    cout << endl;
}

void linkedAllocation(int n) {
    vector<int> next(n, -1);
    int start, len;
    cout << "Enter start block and length: ";
    cin >> start >> len;
    int prev = start;
    for (int i = 1; i < len; i++) {
        int blk;
        cout << "Enter next block: ";
        cin >> blk;
        if (blk >= n) {
            cout << "Invalid block number!\n";
            return;
        }
        next[prev] = blk;
        prev = blk;
    }
    cout << "File blocks linked starting from " << start << endl;
}

int main() {
    int n, choice;
    cout << "Enter total number of blocks: ";
    cin >> n;
    cout << "\nChoose Allocation Strategy:\n";
    cout << "1. Sequential\n2. Indexed\n3. Linked\n";
    cin >> choice;

    switch (choice) {
        case 1: sequentialAllocation(n); break;
        case 2: indexedAllocation(n); break;
        case 3: linkedAllocation(n); break;
        default: cout << "Invalid choice!\n";
    }
    return 0;
}
