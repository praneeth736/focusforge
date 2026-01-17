#ifndef TASK_H
#define TASK_H

#include <string>

struct Task {
    std::string name;
    int burst;
    int priority;
    int arrival;
    int queue_level;
    int remaining;
};

#endif
