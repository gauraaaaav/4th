#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
 int nFrames, nPages;
 cout << "Enter number of frames: ";
 cin >> nFrames;
 cout << "Enter number of pages: ";
 cin >> nPages;
 vector<int> pages(nPages);
 cout << "Enter page reference string:\n";
 for (int i = 0; i < nPages; i++) cin >> pages[i];
 vector<int> frames;
 vector<int> recent(nFrames, -1);
 int pageFaults = 0;
 for (int i = 0; i < nPages; i++) {
 auto it = find(frames.begin(), frames.end(), pages[i]);
 if (it == frames.end()) {
 if ((int)frames.size() < nFrames) {
 frames.push_back(pages[i]);
 } else {
 int lruIdx = 0, lruVal = i;
 for (int j = 0; j < (int)frames.size(); j++) {
 int lastUse = -1;
 for (int k = i-1; k >= 0; k--) {
 if (pages[k] == frames[j]) { lastUse = k; break; }
 }
 if (lastUse < lruVal) { lruVal = lastUse; lruIdx = j; }
 }
 frames[lruIdx] = pages[i];
 }
 pageFaults++;
 }
 }
 cout << "\nTotal Page Faults = " << pageFaults << "\n";
 return 0;
}