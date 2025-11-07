# FocusForge · Personal Task Scheduler Inspired by Operating Systems

FocusForge is a time and task management tool that applies **CPU scheduling principles** to real-life workload planning.  
Instead of simply listing tasks, FocusForge schedules them intelligently — similar to how an operating system schedules processes — helping maintain consistency, fairness, and focus across study, work, and personal goals.

---

## 🌟 Core Concept

Every task has:
- A duration (how long it takes)
- A priority (how important or urgent it is)
- A category (Study, Work, Personal, etc.)

FocusForge treats these tasks like processes and schedules them using well-established OS scheduling algorithms to produce **a balanced and optimized task plan**.

---

## 🧭 Scheduling Strategies Supported

| Scheduling Method | Behavior | Best For |
|------------------|----------|----------|
| **FCFS (First Come First Serve)** | Executes tasks in the order they were added | Simple daily planning |
| **SJF (Shortest Job First)** | Prioritizes tasks taking less time | Quick task clearing / momentum |
| **Priority Scheduling** | Runs urgent or important tasks first | Deadlines and exam prep |
| **Round Robin (Pomodoro Style)** | Cycles between tasks at fixed intervals | Avoiding burnout and fatigue |
| **Multi-Level Queue** | Separates tasks into categories/queues | Balancing different life domains |

---

## 🎯 Why Use FocusForge?

- Prevents spending all your time on just one subject or activity
- Reduces procrastination by enforcing structure
- Makes workload feel lighter by distributing effort
- Helps maintain **balance** across learning, work, and personal life
- Turns emotional decision-making into **logical scheduling**

---

## 🖥️ How to Run

```bash
g++ main.cpp -o focusforge
./focusforge
