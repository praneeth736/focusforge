#ifndef FCFS_H
#define FCFS_H

#include "../core/scheduler.h"

class FCFS : public Scheduler {
public:
    void run() override;
    void printStats() override;
};

#endif
