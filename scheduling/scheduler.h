#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <bits/stdc++.h>
using namespace std;

struct Task {
    string name;
    int burst;
    int priority;
    int arrival;
    int queue_level;
};

void FCFS(vector<Task> tasks);
void SJF(vector<Task> tasks);
void PriorityScheduling(vector<Task> tasks);
void RoundRobin(vector<Task> tasks, int quantum);
void MultiLevelQueue(vector<Task> tasks);

#endif
