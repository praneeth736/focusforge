#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "task.h"
#include "scheduler_result.h"
#include <vector>
#include <map>
#include <iostream>

class Scheduler {
protected:
std::vector<Task> tasks;
SchedulerResult result;

// execution tracking
std::vector<std::pair<int, std::string>> executionOrder;
std::map<std::string, int> finishTime;

int contextSwitches = 0;
int idleTime = 0;
std::string lastTask = "IDLE";

// record execution (called by algorithms)
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

// compute statistics
void computeStats() {
    double totalWaiting = 0;
    double totalTurnaround = 0;

    for (auto& t : tasks) {
        int turnaround = finishTime[t.name] - t.arrival;
        int waiting = turnaround - t.burst;

        totalWaiting += waiting;
        totalTurnaround += turnaround;
    }

    result.avgWaitingTime = totalWaiting / tasks.size();
    result.avgTurnaroundTime = totalTurnaround / tasks.size();
    result.contextSwitches = contextSwitches - 1;
    result.cpuIdleTime = idleTime;
}

public:
virtual ~Scheduler() {}

virtual void addTask(const Task& t) {
    tasks.push_back(t);
}

virtual void run() = 0;

// 🔥 NEW: Print execution timeline
virtual void printExecution() {
    std::cout << "\n=== Execution Timeline ===\n";

    for (auto& entry : executionOrder) {
        std::cout << "[t=" << entry.first << "] " << entry.second << " -> ";
    }

    std::cout << "END\n";
}

// 🔥 UPDATED: Print stats properly
virtual void printStats() {
    computeStats();

    std::cout << "\n=== STATS ===\n";
    std::cout << "Avg Waiting Time: " << result.avgWaitingTime << "\n";
    std::cout << "Avg Turnaround Time: " << result.avgTurnaroundTime << "\n";
    std::cout << "Context Switches: " << result.contextSwitches << "\n";
    std::cout << "CPU Idle Time: " << result.cpuIdleTime << "\n";
}

// 🔥 ADD THIS HERE (IMPORTANT)
const std::vector<std::pair<int, std::string>>& getExecutionOrder() const {
    return executionOrder;
}

SchedulerResult getResult() {
    return result;
}

};

#endif
