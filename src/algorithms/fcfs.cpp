#include "fcfs.h"
#include <algorithm>
#include <iostream>

using namespace std;

void FCFS::run() {
    // Sort tasks by arrival time
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.arrival < b.arrival;
    });

    int currentTime = 0;
    cout << "\nExecution Order:\n";

    for (auto& t : tasks) {
        if (currentTime < t.arrival)
            currentTime = t.arrival;

        cout << "Time " << currentTime << " -> " << t.name << endl;
        currentTime += t.burst;
    }
}

void FCFS::printStats() {
    int currentTime = 0;
    double totalWait = 0;
    double totalTurnaround = 0;

    for (auto& t : tasks) {
        if (currentTime < t.arrival)
            currentTime = t.arrival;

        int wait = currentTime - t.arrival;
        int turnaround = wait + t.burst;

        totalWait += wait;
        totalTurnaround += turnaround;

        currentTime += t.burst;
    }

    cout << "\nAverage Waiting Time: " << totalWait / tasks.size();
    cout << "\nAverage Turnaround Time: " << totalTurnaround / tasks.size() << endl;
}
