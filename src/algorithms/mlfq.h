#ifndef MLFQ_H
#define MLFQ_H

#include "../core/scheduler.h"
#include <queue>

class MLFQ : public Scheduler {
private:
    std::queue<Task> q0;
    std::queue<Task> q1;
    std::queue<Task> q2;

    const int Q0_QUANTUM = 4;
    const int Q1_QUANTUM = 8;

public:
    void run() override;
};

#endif
