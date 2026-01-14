#ifndef PRIORITY_SCHEDULER_H
#define PRIORITY_SCHEDULER_H

#include "../core/scheduler.h"

class PriorityScheduler : public Scheduler {
public:
    void run() override;
    void printStats() override;
};

#endif
