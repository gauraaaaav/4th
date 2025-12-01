#include <iostream>
#include <vector>
#include <queue>
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
 queue<int> q;
 vector<int> frames;
 int pageFaults = 0;
 for (int i = 0; i < nPages; i++) {
 bool found = false;
 for (int f : frames) {
 if (f == pages[i]) { found = true; break; }
 }
 if (!found) {
 if ((int)frames.size() < nFrames) {
 frames.push_back(pages[i]);
 q.push(pages[i]);
 } else {
 int remove = q.front();
 q.pop();
 for (int k = 0; k < (int)frames.size(); k++) {
 if (frames[k] == remove) {
 frames[k] = pages[i];
break;
 }
 }
 q.push(pages[i]);
 }
 pageFaults++;
 }
 }
 cout << "\nTotal Page Faults = " << pageFaults << "\n";
 return 0; }