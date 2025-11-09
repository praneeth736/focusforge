#include <bits/stdc++.h>
#include "scheduler.h"
using namespace std;

void MultiLevelQueue(vector<Task> tasks) {
    vector<Task> highQ, mediumQ, lowQ;

    // Divide tasks into queues based on queue_level
    for (auto &t : tasks) {
        if (t.queue_level == 0)
            highQ.push_back(t);
        else if (t.queue_level == 1)
            mediumQ.push_back(t);
        else
            lowQ.push_back(t);
    }

    cout << "\n================ MULTI-LEVEL QUEUE SCHEDULING ================\n";

    // HIGH PRIORITY QUEUE -> FCFS
    cout << "\n>>> Queue 1 (High Priority) : FCFS Scheduling\n";
    if (!highQ.empty())
        FCFS(highQ);
    else
        cout << "(No tasks in this queue)\n";

    // MEDIUM PRIORITY QUEUE -> SJF
    cout << "\n>>> Queue 2 (Medium Priority) : SJF Scheduling\n";
    if (!mediumQ.empty())
        SJF(mediumQ);
    else
        cout << "(No tasks in this queue)\n";

    // LOW PRIORITY QUEUE -> ROUND ROBIN
    cout << "\n>>> Queue 3 (Low Priority) : Round Robin Scheduling\n";
    if (!lowQ.empty())
        RoundRobin(lowQ, 5); // Quantum = 5
    else
        cout << "(No tasks in this queue)\n";

    cout << "\n==============================================================\n";
}
