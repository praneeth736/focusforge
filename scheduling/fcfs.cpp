#include <iostream>
#include <vector>
#include <algorithm>
#include "../scheduling/scheduler.h"
using namespace std;

void FCFS(vector<Task> tasks) {
    cout << "\n--- FCFS Scheduling ---\n";

    int time = 0;
    for (auto &t : tasks) {
        cout << t.name << " executed for " << t.burst << " units.\n";
        time += t.burst;
    }

    cout << "Total Time: " << time << "\n";
}