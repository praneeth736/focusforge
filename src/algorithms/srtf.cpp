#include "srtf.h"
#include <climits>

void SRTF::run() {
    int time = 0;
    int completed = 0;
    int n = tasks.size();

    while (completed < n) {

        Task* current = nullptr;
        int minRemaining = INT_MAX;

        for (auto& t : tasks) {
            if (t.arrival <= time &&
                t.remaining > 0 &&
                t.remaining < minRemaining) {

                minRemaining = t.remaining;
                current = &t;
            }
        }

        if (current == nullptr) {
            time++;
            continue;
        }

        executionOrder.push_back({time, current->name});
        current->remaining--;
        time++;

        if (current->remaining == 0) {
            completed++;
            finishTime[current->name] = time;
        }
    }
}
