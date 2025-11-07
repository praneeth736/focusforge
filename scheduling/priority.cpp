#include "scheduler.h"

void PriorityScheduling(vector<Task> tasks) {
    cout << "\n--- Priority Scheduling ---\n";
    
    // Lower value = higher priority
    sort(tasks.begin(), tasks.end(), [](auto &a, auto &b){
        return a.priority < b.priority;
    });

    int time = 0;
    for (auto &t : tasks) {
        cout << t.name 
             << " (Priority " << t.priority << ") "
             << " executed for " << t.burst << " units.\n";
        time += t.burst;
    }

    cout << "Total Time: " << time << "\n";
}
