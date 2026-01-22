#ifndef SRTF_H
#define SRTF_H

#include "../core/scheduler.h"

class SRTF : public Scheduler {
public:
    void run() override;
};

#endif
