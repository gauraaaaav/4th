#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int fcfs(vector<int> req, int head) {
	int total = 0;
	for (int r : req) {
		total += abs(head - r);
		head = r;
	}
	return total;
}

int scan(vector<int> req, int head, int size) {
	req.push_back(0);
	req.push_back(size - 1);
	sort(req.begin(), req.end());
	int idx = 0;
	for (int i = 0; i < req.size(); i++) if (req[i] >= head) {
			idx = i;
			break;
		}
	int total = 0, prev = head;
	for (int i = idx; i < req.size(); i++) {
		total += abs(req[i] - prev);
		prev = req[i];
	}
	for (int i = idx - 1; i >= 0; i--) {
		total += abs(req[i] - prev);
		prev = req[i];
	}
	return total;
}

int look(vector<int> req, int head) {
	sort(req.begin(), req.end());
	int idx = 0;
	for (int i = 0; i < req.size(); i++) if (req[i] >= head) {
			idx = i;
			break;
		}
	int total = 0, prev = head;
	for (int i = idx; i < req.size(); i++) {
		total += abs(req[i] - prev);
		prev = req[i];
	}
	for (int i = idx - 1; i >= 0; i--) {
		total += abs(req[i] - prev);
		prev = req[i];
	}
	return total;
}

int main() {
	int n, head, size, choice;
	cout << "Enter number of requests: ";
	cin >> n;
	vector<int> req(n);
	cout << "Enter requests: ";
	for (int i = 0; i < n; i++) cin >> req[i];
	cout << "Enter head position: ";
	cin >> head;
	cout << "Disk size (for SCAN): ";
	cin >> size;

	cout << "\nChoose Algorithm:\n1. FCFS\n2. SCAN\n3. LOOK\nChoice: ";
	cin >> choice;

	int total = 0;
	if (choice == 1) total = fcfs(req, head);
	else if (choice == 2) total = scan(req, head, size);
	else if (choice == 3) total = look(req, head);
	else cout << "Invalid choice!\n";

	if (choice >= 1 && choice <= 3)
		cout << "Total head movement = " << total << endl;
	return 0;
}
