#include "round_robin.h"
#include <iostream>
#include <queue>

using namespace std;

void RoundRobin::run() {
    queue<Task> q;
    for (auto& t : tasks) q.push(t);

    int currentTime = 0;
    cout << "\nExecution Order (Round Robin):\n";

    while (!q.empty()) {
        Task t = q.front();
        q.pop();

        int exec = min(quantum, t.burst);
        cout << "Time " << currentTime << " -> " << t.name << " (runs " << exec << ")\n";

        currentTime += exec;
        t.burst -= exec;

        if (t.burst > 0)
            q.push(t);
    }
}

void RoundRobin::printStats() {
    cout << "\nRound Robin stats skipped for now (we will add later)\n";
}
