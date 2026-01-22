#include "srtf.h"
#include<vector>
#include <climits>

using namespace std;
void SRTF::run() {

    int n = tasks.size();
    vector<int> remaining(n);

    for (int i = 0; i < n; i++)
        remaining[i] = tasks[i].burst;

    int completed = 0;
    int currentTime = 0;

    while (completed < n) {

        int idx = -1;
        int minRemaining = INT_MAX;

        // choose shortest remaining job
        for (int i = 0; i < n; i++) {
            if (tasks[i].arrival <= currentTime &&
                remaining[i] > 0 &&
                remaining[i] < minRemaining) {

                minRemaining = remaining[i];
                idx = i;
            }
        }

        // CPU idle
        if (idx == -1) {
            recordExecution(currentTime, "IDLE");
            currentTime++;
            continue;
        }

        // run for 1 time unit
        recordExecution(currentTime, tasks[idx].name);

        remaining[idx]--;
        currentTime++;

        // process finished
        if (remaining[idx] == 0) {
            finishTime[tasks[idx].name] = currentTime;
            completed++;
        }
    }
}
