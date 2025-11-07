#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "scheduler.h"
using namespace std;

void RoundRobin(vector<Task> tasks, int quantum) {

    sort(tasks.begin(), tasks.end(), [](Task &a, Task &b){
        return a.arrival < b.arrival;
    });

    queue<int> q;
    vector<int> remainingBurst(tasks.size());
    vector<int> completionTime(tasks.size(), 0);

    for(int i = 0; i < tasks.size(); i++)
        remainingBurst[i] = tasks[i].burst;

    int time = 0;
    int index = 0;

    while(index < tasks.size() && tasks[index].arrival <= time){
        q.push(index);
        index++;
    }

    if(q.empty()) {
        time = tasks[0].arrival;
        q.push(0);
        index = 1;
    }

    while(!q.empty()) {
        int i = q.front();
        q.pop();

        int exec = min(quantum, remainingBurst[i]);
        remainingBurst[i] -= exec;
        time += exec;

        while(index < tasks.size() && tasks[index].arrival <= time){
            q.push(index);
            index++;
        }

        if(remainingBurst[i] > 0){
            q.push(i);
        } else {
            completionTime[i] = time;
        }
    }

    cout << "\n---- Round Robin Scheduling ----\n";
    cout << "Task\tArrival\tBurst\tCompletion\n";
    for(int i = 0; i < tasks.size(); i++){
        cout << tasks[i].name << "\t"
             << tasks[i].arrival << "\t"
             << tasks[i].burst << "\t"
             << completionTime[i] << endl;
    }
}
