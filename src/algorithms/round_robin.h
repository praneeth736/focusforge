#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include "../core/scheduler.h"

class RoundRobin : public Scheduler {
    int quantum;
public:
    RoundRobin(int q) : quantum(q) {}
    void run() override;
    void printStats() override;
};

#endif
