#include "policy_engine.h"
#include <cmath>

PolicyType PolicyEngine::choosePolicy(const std::vector<Task>& tasks) {

    int n = tasks.size();

    double totalBurst = 0;
    double maxBurst = 0;
    double minBurst = 1e9;

    int earliestArrival = 1e9;
    int latestArrival = 0;

    int minPriority = 1e9;
    int maxPriority = 0;

    for (auto& t : tasks) {
        totalBurst += t.burst;
        maxBurst = std::max(maxBurst, (double)t.burst);
        minBurst = std::min(minBurst, (double)t.burst);

        earliestArrival = std::min(earliestArrival, t.arrival);
        latestArrival = std::max(latestArrival, t.arrival);

        minPriority = std::min(minPriority, t.priority);
        maxPriority = std::max(maxPriority, t.priority);
    }

    double avgBurst = totalBurst / n;
    double arrivalSpread = latestArrival - earliestArrival;
    double prioritySpread = maxPriority - minPriority;

    // 🔥 Decision logic

    // Many short jobs
    if (avgBurst <= 20 && arrivalSpread == 0)
        return PolicyType::SJF;

    // Streaming arrivals with short jobs
    if (avgBurst <= 25 && arrivalSpread > 0)
        return PolicyType::SRTF;

    // Priority-sensitive workload
    if (prioritySpread >= 3)
        return PolicyType::PRIORITY;

    // Many processes → time-sharing
    if (n >= 6)
        return PolicyType::ROUND_ROBIN;

    // Default safe batch scheduler
    return PolicyType::FCFS;
}
