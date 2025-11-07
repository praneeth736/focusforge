#include <bits/stdc++.h>
#include "scheduling/fcfs.cpp"
#include "scheduling/sjf.cpp"
#include "scheduling/priority.cpp"
#include "scheduling/roundrobin.cpp"
using namespace std;


int main() {
   
        vector<Task> tasks = {
    {"OS Assignment", 0, 60, 2},
    {"DSA Problems", 3, 45, 1},
    {"Gym", 5, 30, 3},
    {"Read Notes", 7, 20, 2}
};

    cout << "\nChoose Scheduling Algorithm:\n";
    cout << "1. FCFS\n";
    cout << "2. SJF\n";
    cout << "3. Priority Scheduling\n";
    cout<<"4. Round Robin\n";
    int choice;
    cin >> choice;

    if(choice == 1) FCFS(tasks);
    else if(choice == 2) SJF(tasks);
    else if(choice == 3) PriorityScheduling(tasks);
    else if(choice ==4) {
        int quantum;
        cout<<"Enter Time Quantum";
        cin>>quantum;
        RoundRobin(tasks,quantum);
    }
    else cout << "Invalid input\n";

    return 0;
}