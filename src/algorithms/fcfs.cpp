#include "fcfs.h"
#include <algorithm>
#include <iostream>

using namespace std;
#include "fcfs.h"
#include <algorithm>

void FCFS::run() {

    // Sort processes by arrival time
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.arrival < b.arrival;
    });

    int currentTime = 0;

    for (auto& t : tasks) {

        // CPU idle handling
        if (currentTime < t.arrival) {
            recordExecution(currentTime, "IDLE");
            currentTime = t.arrival;
        }

        // Task starts execution
        recordExecution(currentTime, t.name);

        // Non-preemptive execution
        currentTime += t.burst;

        // Task completed
        finishTime[t.name] = currentTime;
    }
}

