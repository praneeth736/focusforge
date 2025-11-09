#include <bits/stdc++.h>
#include "scheduler.h"
using namespace std;

void RoundRobin(vector<Task> tasks, int quantum) {
    int n = tasks.size();
    vector<int> rem(n), waiting(n, 0), turnaround(n, 0);

    for(int i = 0; i < n; i++)
        rem[i] = tasks[i].burst;

    int time = 0;
    bool done;

    while (true) {
        done = true;

        for(int i = 0; i < n; i++) {
            if(rem[i] > 0) {
                done = false;

                int run = min(quantum, rem[i]);
                rem[i] -= run;
                time += run;

                if(rem[i] == 0)
                    turnaround[i] = time;
            }
        }
        if(done) break;
    }

    for(int i = 0; i < n; i++)
        waiting[i] = turnaround[i] - tasks[i].burst;

    cout << "\n---------------- Round Robin Scheduling ----------------\n";
    cout << "Time Quantum = " << quantum << "\n\n";

    cout << left << setw(20) << "Task Name"
         << setw(8)  << "Burst"
         << setw(10) << "Waiting"
         << setw(12) << "Turnaround" << "\n";

    cout << string(52, '-') << "\n";

    for(int i = 0; i < n; i++){
        cout << left << setw(20) << tasks[i].name
             << setw(8)  << tasks[i].burst
             << setw(10) << waiting[i]
             << setw(12) << turnaround[i] << "\n";
    }

    cout << string(52, '-') << "\n";
    cout << "Total CPU Time: " << time << "\n";
}
