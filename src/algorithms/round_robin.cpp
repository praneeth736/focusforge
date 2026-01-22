#include "round_robin.h"
#include <queue>
#include <vector>

using namespace std;

void RoundRobin::run() {

    int n = tasks.size();
    vector<int> remaining(n);

    for (int i = 0; i < n; i++)
        remaining[i] = tasks[i].burst;

    queue<int> readyQueue;

    int currentTime = 0;
    int completed = 0;

    // initially push arrived tasks
    for (int i = 0; i < n; i++) {
        if (tasks[i].arrival == 0)
            readyQueue.push(i);
    }

    while (completed < n) {

        if (readyQueue.empty()) {
            recordExecution(currentTime, "IDLE");
            currentTime++;
            continue;
        }

        int idx = readyQueue.front();
        readyQueue.pop();

        int execTime = min(quantum, remaining[idx]);

        for (int t = 0; t < execTime; t++) {
            recordExecution(currentTime, tasks[idx].name);
            remaining[idx]--;
            currentTime++;

            // add newly arrived processes
            for (int i = 0; i < n; i++) {
                if (tasks[i].arrival == currentTime)
                    readyQueue.push(i);
            }

            if (remaining[idx] == 0)
                break;
        }

        if (remaining[idx] == 0) {
            finishTime[tasks[idx].name] = currentTime;
            completed++;
        } else {
            readyQueue.push(idx);
        }
    }
}
