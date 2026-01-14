#include <iostream>
#include <vector>

#include "src/core/task.h"
#include "src/core/policy_engine.h"
#include "src/algorithms/fcfs.h"
#include "src/algorithms/sjf.h"

using namespace std;

int main() {
    int n;
    cout << "Enter number of tasks: ";
    cin >> n;

    cout << "\nChoose Scheduler:\n";
    cout << "1. FCFS\n";
    cout << "2. SJF\n";
    cout << "3. AUTO\n";

    int choice;
    cin >> choice;

    vector<Task> allTasks;

    for (int i = 0; i < n; i++) {
        Task t;
        cout << "\nTask " << i + 1 << " Name: ";
        cin >> t.name;

        cout << "Burst Time: ";
        cin >> t.burst;

        cout << "Priority: ";
        cin >> t.priority;

        cout << "Arrival Time: ";
        cin >> t.arrival;

        cout << "Queue Level: ";
        cin >> t.queue_level;

        allTasks.push_back(t);
    }

    Scheduler* scheduler = nullptr;

    if (choice == 1) {
        scheduler = new FCFS();
    } 
    else if (choice == 2) {
        scheduler = new SJF();
    } 
    else if (choice == 3) {
        auto policy = PolicyEngine::choosePolicy(allTasks);

        if (policy == PolicyType::SJF) {
            cout << "\n[AUTO] Selected SJF policy\n";
            scheduler = new SJF();
        } else {
            cout << "\n[AUTO] Selected FCFS policy\n";
            scheduler = new FCFS();
        }
    }
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
