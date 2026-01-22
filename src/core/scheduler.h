#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "task.h"
#include <vector>
#include <map>
#include <iostream>

class Scheduler {
protected:
    std::vector<Task> tasks;

    // common stats storage
    std::vector<std::pair<int, std::string>> executionOrder;
    std::map<std::string, int> finishTime;

    int contextSwitches = 0;
    int idleTime = 0;
    std::string lastTask = "IDLE";

    // called by algorithms
    void recordExecution(int time, const std::string& taskName) {

        if (taskName != lastTask) {
            contextSwitches++;
            executionOrder.push_back({time, taskName});
            lastTask = taskName;
        }

        if (taskName == "IDLE") {
            idleTime++;
        }
    }

   void computeStats() {
    double totalWaiting = 0;
    double totalTurnaround = 0;

    for (auto& t : tasks) {
        int turnaround = finishTime[t.name] - t.arrival;
        int waiting = turnaround - t.burst;

        totalWaiting += waiting;
        totalTurnaround += turnaround;
    }

    std::cout << "\nExecution Timeline:\n";
    for (auto& e : executionOrder) {
        std::cout << "Time " << e.first << " -> " << e.second << "\n";
    }

    std::cout << "\nContext Switches: " << contextSwitches - 1 << "\n";
    std::cout << "CPU Idle Time: " << idleTime << "\n";

    std::cout << "\nAverage Waiting Time: "
              << totalWaiting / tasks.size() << "\n";

    std::cout << "Average Turnaround Time: "
              << totalTurnaround / tasks.size() << "\n";
}


public:
    virtual ~Scheduler() {}

    virtual void addTask(const Task& t) {
        tasks.push_back(t);
    }

    virtual void run() = 0;

    virtual void printStats() {
        computeStats();
    }
};

#endif
