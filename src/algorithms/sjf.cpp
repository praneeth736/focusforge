#include "sjf.h"
#include <algorithm>
#include <iostream>
#include<climits>

using namespace std;

void SJF::run() {

    int currentTime = 0;
    int completed = 0;
    int n = tasks.size();

    vector<bool> done(n, false);

    while (completed < n) {

        int idx = -1;
        int minBurst = INT_MAX;

        // select shortest arrived job
        for (int i = 0; i < n; i++) {
            if (!done[i] &&
                tasks[i].arrival <= currentTime &&
                tasks[i].burst < minBurst) {

                minBurst = tasks[i].burst;
                idx = i;
            }
        }

        // no job ready → CPU idle
        if (idx == -1) {
            recordExecution(currentTime, "IDLE");
            currentTime++;
            continue;
        }

        // run job
        recordExecution(currentTime, tasks[idx].name);

        currentTime += tasks[idx].burst;

        finishTime[tasks[idx].name] = currentTime;

        done[idx] = true;
        completed++;
    }
}