#ifndef SJF_H
#define SJF_H

#include "../core/scheduler.h"

class SJF : public Scheduler {
public:
    void run() override;
};

#endif
