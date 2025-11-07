#include <bits/stdc++.h>
#include "scheduling/scheduler.h"
using namespace std;


int main() {
    vector<Task> tasks = {
        {"OS Assignment", 60, 2},
        {"DSA Problems", 45, 1},
        {"Gym", 30, 3},
        {"Read Notes", 20, 2}
    };

    cout << "\nChoose Scheduling Algorithm:\n";
    cout << "1. FCFS\n";
    cout << "2. SJF\n";
    cout << "3. Priority Scheduling\n";
    int choice;
    cin >> choice;

    if(choice == 1) FCFS(tasks);
    else if(choice == 2) SJF(tasks);
    else if(choice == 3) PriorityScheduling(tasks);
    else cout << "Invalid input\n";

    return 0;
}