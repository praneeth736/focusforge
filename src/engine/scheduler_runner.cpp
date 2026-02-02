#include "scheduler_runner.h"

#include "../algorithms/fcfs.h"
#include "../algorithms/sjf.h"
#include "../algorithms/srtf.h"
#include "../algorithms/priority.h"
#include "../algorithms/round_robin.h"
#include "../algorithms/mlfq.h"

#include <iostream>

using namespace std;

void SchedulerRunner::run(
    vector<Task>& tasks,
    PolicyType policy,
    int quantum
) {
    Scheduler* scheduler = nullptr;

    cout << "\n[KERNEL]\n";

    switch (policy) {

        case PolicyType::MLFQ:
            cout << "Scheduler: MLFQ\n";
            scheduler = new MLFQ();
            break;

        case PolicyType::SRTF:
            cout << "Scheduler: SRTF\n";
            scheduler = new SRTF();
            break;

        case PolicyType::ROUND_ROBIN:
            cout << "Scheduler: Round Robin\n";
            scheduler = new RoundRobin(quantum);
            break;

        case PolicyType::PRIORITY:
            cout << "Scheduler: Priority\n";
            scheduler = new PriorityScheduler();
            break;

        case PolicyType::SJF:
            cout << "Scheduler: SJF\n";
            scheduler = new SJF();
            break;

        default:
            cout << "Scheduler: FCFS\n";
            scheduler = new FCFS();
            break;
    }

    for (auto& t : tasks) {
        scheduler->addTask(t);
    }

    scheduler->run();
    scheduler->printStats();

    delete scheduler;
}
