#ifndef POLICY_ENGINE_H
#define POLICY_ENGINE_H

#include "task.h"
#include <vector>

enum class PolicyType {
    FCFS,
    SJF
};

class PolicyEngine {
public:
    static PolicyType choosePolicy(const std::vector<Task>& tasks) {
        // If many short jobs → SJF
        int shortJobs = 0;
        for (auto& t : tasks) {
            if (t.burst <= 50) shortJobs++;
        }

        if (shortJobs > tasks.size() / 2)
            return PolicyType::SJF;
        else
            return PolicyType::FCFS;
    }
};

#endif
