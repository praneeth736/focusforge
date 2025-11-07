#include <bits/stdc++.h>
using namespace std;

struct Task {
    string name;
    int duration;   // burst time
    int priority;   // numeric priority
    string category;
};

int main() {
    vector<Task> tasks;

    tasks.push_back({"OS Assignment", 60, 8, "Study"});
    tasks.push_back({"DSA Practice", 40, 7, "Study"});
    tasks.push_back({"Gym", 60, 5, "Health"});

    cout << "\nTasks successfully added! (No scheduling yet)\n";
}
