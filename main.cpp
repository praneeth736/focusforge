#include <iostream>
#include <vector>
#include <algorithm>

#include "src/core/task.h"
#include "src/core/policy_engine.h"
#include "src/algorithms/mlfq.h"
#include "src/algorithms/fcfs.h"
#include "src/algorithms/sjf.h"
#include "src/algorithms/priority.h"
#include "src/algorithms/round_robin.h"
#include "src/algorithms/srtf.h"

using namespace std;

int main() {

    vector<Task> allTasks;

    while (true) {

        cout << "\n===== FocusForge Scheduler Kernel =====\n";
        cout << "1. Add tasks & run scheduler\n";
        cout << "2. Remove a task\n";
        cout << "3. Remove all tasks\n";
        cout << "4. Exit\n";
        cout << "Select option: ";

        int option;
        cin >> option;

        // =====================================================
        // ADD TASKS AND RUN
        // =====================================================
        if (option == 1) {

            int n;
            cout << "\nEnter number of tasks: ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                Task t;

                cout << "\nTask " << allTasks.size() + 1 << " Name: ";
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

            if (allTasks.empty()) {
                cout << "No tasks available.\n";
                continue;
            }

            cout << "\nRun Scheduler Using:\n";
            cout << "1. AUTO (kernel decides)\n";
            cout << "2. Manual algorithm selection\n";
            cout << "Choice: ";

            int mode;
            cin >> mode;

            Scheduler* scheduler = nullptr;

            // ================= AUTO MODE =================
            if (mode == 1) {

                PolicyType policy = PolicyEngine::choosePolicy(allTasks);

                cout << "\n[AUTO MODE]\n";

                if (policy == PolicyType::MLFQ) {
                    cout << "Selected: MLFQ (Linux-style adaptive scheduler)\n";
                    scheduler = new MLFQ();
                }
                else if (policy == PolicyType::SRTF) {
                    cout << "Selected: SRTF (preemptive short jobs)\n";
                    scheduler = new SRTF();
                }
                else if (policy == PolicyType::ROUND_ROBIN) {
                    cout << "Selected: Round Robin (interactive workload)\n";
                    scheduler = new RoundRobin(4);
                }
                else if (policy == PolicyType::SJF) {
                    cout << "Selected: SJF (batch workload)\n";
                    scheduler = new SJF();
                }
                else {
                    cout << "Selected: FCFS (long CPU-bound workload)\n";
                    scheduler = new FCFS();
                }
            }

            // ================= MANUAL MODE =================
            else {

                cout << "\nChoose Algorithm:\n";
                cout << "1. FCFS\n";
                cout << "2. SJF\n";
                cout << "3. Priority\n";
                cout << "4. Round Robin\n";
                cout << "5. SRTF\n";
                cout << "6. MLFQ\n";
                cout << "Choice: ";

                int c;
                cin >> c;

                if (c == 1) scheduler = new FCFS();
                else if (c == 2) scheduler = new SJF();
                else if (c == 3) scheduler = new PriorityScheduler();
                else if (c == 4) scheduler = new RoundRobin(4);
                else if (c == 5) scheduler = new SRTF();
                else if (c == 6) scheduler = new MLFQ();
                else {
                    cout << "Invalid choice.\n";
                    continue;
                }
            }

            for (auto& t : allTasks)
                scheduler->addTask(t);

            scheduler->run();
            scheduler->printStats();

            delete scheduler;
        }

        // =====================================================
        // REMOVE ONE TASK
        // =====================================================
        else if (option == 2) {

            if (allTasks.empty()) {
                cout << "\nNo tasks to remove.\n";
                continue;
            }

            cout << "\nCurrent tasks:\n";
            for (auto& t : allTasks)
                cout << " - " << t.name << "\n";

            cout << "Enter task name to remove: ";
            string name;
            cin >> name;

            auto it = remove_if(
                allTasks.begin(),
                allTasks.end(),
                [&](const Task& t) {
                    return t.name == name;
                }
            );

            if (it == allTasks.end()) {
                cout << "Task not found.\n";
            } else {
                allTasks.erase(it, allTasks.end());
                cout << "Task removed successfully.\n";
            }
        }

        // =====================================================
        // CLEAR ALL TASKS
        // =====================================================
        else if (option == 3) {
            allTasks.clear();
            cout << "\nAll tasks removed.\n";
        }

        // =====================================================
        // EXIT
        // =====================================================
        else if (option == 4) {
            cout << "\nShutting down FocusForge kernel...\n";
            break;
        }

        else {
            cout << "Invalid option.\n";
        }
    }

    return 0;
}
