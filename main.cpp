#include <iostream>
#include "src/core/task.h"
#include "src/algorithms/fcfs.h"
#include "src/algorithms/sjf.h"

using namespace std;

int main() {
    int n;
    cout << "Enter number of tasks: ";
    cin >> n;

    cout << "Choose Scheduler:\n1. FCFS\n2. SJF\n";
    int choice;
    cin >> choice;

    Scheduler* scheduler;

    if (choice == 1)
        scheduler = new FCFS();
    else
        scheduler = new SJF();

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

        scheduler->addTask(t);
    }

    scheduler->run();
    scheduler->printStats();

    delete scheduler;
    return 0;
}
