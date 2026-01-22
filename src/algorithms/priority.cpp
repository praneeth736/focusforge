#include "priority.h"
#include <algorithm>
#include <climits>

using namespace std;

void PriorityScheduler::run() {

    int n = tasks.size();
    vector<bool> done(n, false);

    int completed = 0;
    int time = 0;

    while (completed < n) {

        int idx = -1;
        int bestPriority = INT_MAX;

        // select highest priority job that has arrived
        for (int i = 0; i < n; i++) {
            if (!done[i] &&
                tasks[i].arrival <= time &&
                tasks[i].priority < bestPriority) {

                bestPriority = tasks[i].priority;
                idx = i;
            }
        }

        if (idx == -1) {
            recordExecution(time, "IDLE");
            time++;
            continue;
        }

        // run full burst (non-preemptive)
        recordExecution(time, tasks[idx].name);
        time += tasks[idx].burst;

        finishTime[tasks[idx].name] = time;
        done[idx] = true;
        completed++;
    }
}
