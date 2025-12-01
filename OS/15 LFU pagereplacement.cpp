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
 vector<int> freq(nPages, 0);
 int pageFaults = 0;
 for (int i = 0; i < nPages; i++) {
 auto it = find(frames.begin(), frames.end(), pages[i]);
 if (it != frames.end()) {
 freq[pages[i]]++;
 } else {
 if ((int)frames.size() < nFrames) {
 frames.push_back(pages[i]);
 freq[pages[i]]++;
 } else {
 int minFreq = freq[frames[0]], idx = 0;
 for (int j = 1; j < (int)frames.size(); j++) {
 if (freq[frames[j]] < minFreq) {
 minFreq = freq[frames[j]];
idx = j;
 }
 }
 frames[idx] = pages[i];
 freq[pages[i]]++;
 }
 pageFaults++;
 }
 }
 cout << "\nTotal Page Faults = " << pageFaults << "\n";
 return 0;
}