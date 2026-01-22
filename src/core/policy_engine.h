#ifndef POLICY_ENGINE_H
#define POLICY_ENGINE_H

#include <vector>
#include "task.h"

enum class PolicyType {
    FCFS,
    SJF,
    SRTF,
    PRIORITY,
    ROUND_ROBIN
};

class PolicyEngine {
public:
    static PolicyType choosePolicy(const std::vector<Task>& tasks);
};

#endif
