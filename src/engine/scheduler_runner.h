#ifndef SCHEDULER_RUNNER_H
#define SCHEDULER_RUNNER_H

#include <vector>
#include <string>

#include "../core/task.h"
#include "../core/policy_engine.h"

class SchedulerRunner {
public:
    static void run(
        std::vector<Task>& tasks,
        PolicyType policy,
        int quantum = 4
    );
};

#endif
