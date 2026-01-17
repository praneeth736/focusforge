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

    void computeStats() {
        double totalWaiting = 0;
        double totalTurnaround = 0;

        for (auto& t : tasks) {
            int turnaround = finishTime[t.name] - t.arrival;
            int waiting = turnaround - t.burst;

            totalWaiting += waiting;
            totalTurnaround += turnaround;
        }

        std::cout << "\nExecution Order:\n";
        for (auto& e : executionOrder) {
            std::cout << "Time " << e.first << " -> " << e.second << "\n";
        }

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
