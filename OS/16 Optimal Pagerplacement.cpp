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
 int pageFaults = 0;
 for (int i = 0; i < nPages; i++) {
 auto it = find(frames.begin(), frames.end(), pages[i]);
 if (it == frames.end()) {
 if ((int)frames.size() < nFrames) {
 frames.push_back(pages[i]);
 } else {
 int replaceIdx = -1, farthest = i+1;
 for (int j = 0; j < (int)frames.size(); j++) {
 int nextUse = nPages+1;
 for (int k = i+1; k < nPages; k++) {
 if (pages[k] == frames[j]) { nextUse = k; break; }
 }
 if (nextUse > farthest) {
 farthest = nextUse;
replaceIdx = j;
 }
 }
 frames[replaceIdx] = pages[i];
 }
 pageFaults++;
 }
 }
 cout << "\nTotal Page Faults = " << pageFaults << "\n";
 return 0;
}