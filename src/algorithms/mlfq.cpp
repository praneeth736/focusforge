#include "mlfq.h"
#include <iostream>

using namespace std;

void MLFQ::run() {

    // all tasks start in highest queue
    for (auto& t : tasks) {
        t.remaining = t.burst;
        q0.push(t);
    }

    int time = 0;

    while (!q0.empty() || !q1.empty() || !q2.empty()) {

        Task current;

        // ---------- Q0 ----------
        if (!q0.empty()) {
            current = q0.front();
            q0.pop();

            recordExecution(time, current.name);

            int run = min(Q0_QUANTUM, current.remaining);
            current.remaining -= run;
            time += run;

            if (current.remaining == 0) {
                finishTime[current.name] = time;
            } else {
                q1.push(current);
            }
        }

        // ---------- Q1 ----------
        else if (!q1.empty()) {
            current = q1.front();
            q1.pop();

            recordExecution(time, current.name);

            int run = min(Q1_QUANTUM, current.remaining);
            current.remaining -= run;
            time += run;

            if (current.remaining == 0) {
                finishTime[current.name] = time;
            } else {
                q2.push(current);
            }
        }

        // ---------- Q2 ----------
        else {
            current = q2.front();
            q2.pop();

            recordExecution(time, current.name);

            time += current.remaining;
            current.remaining = 0;

            finishTime[current.name] = time;
        }
    }
}
