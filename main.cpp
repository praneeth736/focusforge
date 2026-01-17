#include <iostream>
#include <vector>

#include "src/core/task.h"
#include "src/core/policy_engine.h"
#include "src/algorithms/fcfs.h"
#include "src/algorithms/sjf.h"
#include "src/algorithms/priority.h"
#include "src/algorithms/round_robin.h"
#include "src/algorithms/srtf.h"



using namespace std;

int main() {
    int n;
    cout << "Enter number of tasks: ";
    cin >> n;

    cout << "\nChoose Scheduler:\n";
    cout << "1. FCFS\n";
    cout << "2. SJF\n";
    cout << "3. Priority\n";
    cout << "4. Round Robin\n";
    cout << "5. AUTO\n";
    cout << "6. SRTF (Preemptive SJF)\n";

    int choice;
    cin >> choice;

    vector<Task> allTasks;

    for (int i = 0; i < n; i++) {
        Task t;
        cout << "\nTask " << i + 1 << " Name: ";
        cin >> t.name;

        cout << "Burst Time: ";
        cin >> t.burst;
        t.remaining = t.burst;

        cout << "Priority: ";
        cin >> t.priority;

        cout << "Arrival Time: ";
        cin >> t.arrival;

        cout << "Queue Level: ";
        cin >> t.queue_level;

        allTasks.push_back(t);
    }

    Scheduler* scheduler = nullptr;

    if (choice == 1) scheduler = new FCFS();
    else if (choice == 2) scheduler = new SJF();
    else if (choice == 3) scheduler = new PriorityScheduler();
    else if (choice == 4) {
    int q;
    cout << "Enter time quantum: ";
    cin >> q;
    scheduler = new RoundRobin(q);
    }
    else if (choice == 5) {
    auto policy = PolicyEngine::choosePolicy(allTasks);
    scheduler = (policy == PolicyType::SJF) ? (Scheduler*)new SJF() : (Scheduler*)new FCFS();
    }
    else if (choice == 6) scheduler = new SRTF();
    else {
        cout << "Invalid choice\n";
        return 0;
    }

    for (auto& t : allTasks) {
        scheduler->addTask(t);
    }

    scheduler->run();
    scheduler->printStats();

    delete scheduler;
    return 0;
}
