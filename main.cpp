#include <bits/stdc++.h>
#include "scheduling/scheduler.h"
using namespace std;

int main() {

    vector<Task> tasks;
    int n;
    cout << "Enter number of tasks: ";
    cin >> n;

    tasks.resize(n);

    cout << "\nEnter Task Details:\n";
    for(int i = 0; i < n; i++) {
        cout << "\nTask " << i+1 << " Name: ";
        cin >> tasks[i].name;

        cout << "Burst Time: ";
        cin >> tasks[i].burst;

        cout << "Priority (1 = Highest): ";
        cin >> tasks[i].priority;

        cout << "Arrival Time: ";
        cin >> tasks[i].arrival;

        cout << "Queue Level (0 = High, 1 = Medium, 2 = Low): ";
        cin >> tasks[i].queue_level;
    }

    cout << "\nChoose Scheduling Algorithm:\n";
    cout << "1. FCFS\n";
    cout << "2. SJF\n";
    cout << "3. Priority Scheduling\n";
    cout << "4. Round Robin\n";
    cout << "5. Multi-Level Queue Scheduling\n";

    int choice;
    cin >> choice;

    if(choice == 1) FCFS(tasks);
    else if(choice == 2) SJF(tasks);
    else if(choice == 3) PriorityScheduling(tasks);
    else if(choice == 4) {
        int quantum;
        cout << "Enter Time Quantum: ";
        cin >> quantum;
        RoundRobin(tasks, quantum);
    }
    else if(choice == 5) MultiLevelQueue(tasks);
    else cout << "Invalid input\n";

    return 0;
}
