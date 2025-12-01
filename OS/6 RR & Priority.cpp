#include <iostream>
#include <queue>
using namespace std;

struct Process {
    int pid, bt, at, priority, wt = 0, tat = 0, rt;
};

// Round Robin Scheduling
void roundRobin(Process p[], int n, int quantum) {
    cout << "\n--- Round Robin Scheduling ---\n";
    queue<int> q; int time = 0, completed = 0;
    for (int i = 0; i < n; i++) p[i].rt = p[i].bt;

    q.push(0); bool inQueue[20] = {false}; inQueue[0] = true;

    while (completed < n) {
        int i = q.front(); q.pop(); inQueue[i] = false;
        int exec = min(p[i].rt, quantum);
        time += exec; p[i].rt -= exec;

        if (p[i].rt == 0) {
            completed++;
            p[i].tat = time - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
        }
        for (int j = 0; j < n; j++)
            if (p[j].at <= time && p[j].rt > 0 && !inQueue[j]) {
                q.push(j); inQueue[j] = true;
            }
        if (p[i].rt > 0) { q.push(i); inQueue[i] = true; }
    }

    float avgWT=0, avgTAT=0;
    cout << "PID\tBT\tAT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].pid << "\t" << p[i].bt << "\t" << p[i].at
             << "\t" << p[i].wt << "\t" << p[i].tat << "\n";
        avgWT += p[i].wt; avgTAT += p[i].tat;
    }
    cout << "Average WT = " << avgWT/n << "\nAverage TAT = " << avgTAT/n << "\n";
}

// Preemptive Priority Scheduling
void priorityPreemptive(Process p[], int n) {
    cout << "\n--- Preemptive Priority Scheduling ---\n";
    int time = 0, completed = 0;
    for (int i = 0; i < n; i++) p[i].rt = p[i].bt;

    while (completed < n) {
        int idx=-1, best=1e9;
        for (int i=0;i<n;i++)
            if (p[i].at<=time && p[i].rt>0 && p[i].priority<best) 
                best=p[i].priority, idx=i;

        if (idx==-1) { time++; continue; }
        p[idx].rt--; time++;
        if (p[idx].rt==0) {
            completed++;
            p[idx].tat=time-p[idx].at;
            p[idx].wt=p[idx].tat-p[idx].bt;
        }
    }

    float avgWT=0, avgTAT=0;
    cout << "PID\tBT\tAT\tPr\tWT\tTAT\n";
    for (int i=0;i<n;i++) {
        cout << p[i].pid << "\t" << p[i].bt << "\t" << p[i].at
             << "\t" << p[i].priority << "\t" << p[i].wt << "\t" << p[i].tat << "\n";
        avgWT+=p[i].wt; avgTAT+=p[i].tat;
    }
    cout << "Average WT = " << avgWT/n << "\nAverage TAT = " << avgTAT/n << "\n";
}

int main() {
    int n; cout << "Enter number of processes: "; cin >> n;
    Process p[20];
    for (int i=0;i<n;i++) {
        cout << "\nProcess " << i+1 << ":\n";
        p[i].pid=i+1;
        cout<<"BT: ";cin>>p[i].bt;
        cout<<"AT: ";cin>>p[i].at;
        cout<<"Priority: ";cin>>p[i].priority;
    }
    int q; cout << "\nEnter Time Quantum: "; cin >> q;
    roundRobin(p,n,q);
    priorityPreemptive(p,n);
}
