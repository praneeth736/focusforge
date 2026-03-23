#ifndef SCHEDULER_RESULT_H
#define SCHEDULER_RESULT_H

#include <string>
#include <vector>

struct ExecutionStep {
    int time;
    std::string task;
};

struct SchedulerResult {
    std::vector<ExecutionStep> timeline;
    double avgWaitingTime;
    double avgTurnaroundTime;
    int contextSwitches;
    int cpuIdleTime;
};

#endif
