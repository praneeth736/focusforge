#ifndef PRIORITY_H
#define PRIORITY_H

#include "../core/scheduler.h"

class PriorityScheduler : public Scheduler {
public:
    void run() override;
};

#endif
