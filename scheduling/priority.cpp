#include <bits/stdc++.h>
#include "scheduler.h"
using namespace std;

void PriorityScheduling(vector<Task> tasks) {
    int n = tasks.size();
    
    // Sort by priority (lower value = higher priority)
    sort(tasks.begin(), tasks.end(), [](Task &a, Task &b){
        return a.priority < b.priority;
    });

    vector<int> waiting(n), turnaround(n);
    int total_wait = 0, total_turn = 0;

    waiting[0] = 0;
    for(int i = 1; i < n; i++){
        waiting[i] = waiting[i - 1] + tasks[i - 1].burst;
    }

    for(int i = 0; i < n; i++){
        turnaround[i] = waiting[i] + tasks[i].burst;
        total_wait += waiting[i];
        total_turn += turnaround[i];
    }

    cout << "\n---------------- Priority Scheduling ----------------\n\n";

    cout << left << setw(20) << "Task Name"
         << setw(8)  << "Burst"
         << setw(10) << "Priority"
         << setw(10) << "Waiting"
         << setw(12) << "Turnaround" << "\n";

    cout << string(60, '-') << "\n";

    for(int i = 0; i < n; i++){
        cout << left << setw(20) << tasks[i].name
             << setw(8)  << tasks[i].burst
             << setw(10) << tasks[i].priority
             << setw(10) << waiting[i]
             << setw(12) << turnaround[i] << "\n";
    }

    cout << string(60, '-') << "\n";
    cout << "Total CPU Time: " << turnaround[n - 1] << "\n";
}
