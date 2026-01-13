#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "task.h"
#include <vector>

class Scheduler {
protected:
    std::vector<Task> tasks;

public:
    virtual ~Scheduler() {}

    // Add a task to scheduler
    virtual void addTask(const Task& t) {
        tasks.push_back(t);
    }

    // Run the scheduling algorithm
    virtual void run() = 0;

    // Print stats (waiting time, turnaround, etc)
    virtual void printStats() = 0;
};

#endif
