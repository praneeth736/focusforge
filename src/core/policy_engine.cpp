#include "policy_engine.h"

PolicyType PolicyEngine::choosePolicy(const std::vector<Task>& tasks) {

    int interactiveJobs = 0;
    int cpuJobs = 0;

    double avgBurst = 0;

    for (auto& t : tasks) {
        avgBurst += t.burst;

        if (t.burst <= 20)
            interactiveJobs++;
        else
            cpuJobs++;
    }

    avgBurst /= tasks.size();

    // Interactive workload → MLFQ
    if (interactiveJobs >= cpuJobs)
        return PolicyType::MLFQ;

    // Short jobs but arrival-based
    if (avgBurst <= 30)
        return PolicyType::SRTF;

    // Medium batch
    if (avgBurst <= 60)
        return PolicyType::SJF;

    // Long batch jobs
    return PolicyType::FCFS;
}
