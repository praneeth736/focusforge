#include <bits/stdc++.h>
#include "../scheduling/scheduler.h"
using namespace std;

// Shortest Job First Scheduling
void SJF(vector<Task> tasks) {
    // Sort by burst time
    sort(tasks.begin(), tasks.end(), [](Task a, Task b){
        return a.burst < b.burst;
    });

    cout << "\n--- SJF Schedule ---\n";
    int time = 0, waitingTime = 0;

    for (auto &t : tasks) {
        cout << "Run: " << t.name << " (" << t.burst << " mins)\n";
        waitingTime += time;
        time += t.burst;
    }

    cout << "\nAverage Waiting Time: " << (float)waitingTime / tasks.size() << " mins\n";
}
