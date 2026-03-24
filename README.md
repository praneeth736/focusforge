# 🚀 FocusForge – Intelligent OS Scheduler Simulator

FocusForge is a **kernel-style CPU scheduling simulator** built in C++ that models how operating systems manage processes using classic scheduling algorithms.

Instead of a basic implementation, FocusForge provides a **unified scheduling engine**, execution tracing, and performance analysis — along with a lightweight frontend for visualization.

---

## 🧠 Project Overview

FocusForge simulates how an operating system schedules tasks (processes) using multiple algorithms and dynamically selects the best policy based on workload.

Each task includes:

* Name
* Burst Time
* Priority
* Arrival Time
* Queue Level

The system then schedules tasks and produces a **time-based execution trace** similar to real OS schedulers.

---

## ⚙️ Features

### 🔹 Scheduling Algorithms

* FCFS (First Come First Serve)
* SJF (Shortest Job First)
* SRTF (Shortest Remaining Time First)
* Priority Scheduling
* Round Robin
* MLFQ (Multi-Level Feedback Queue)

---

### 🔹 Intelligent AUTO Mode

* Automatically selects the best scheduling policy
* Based on workload characteristics
* Demonstrates **policy-driven scheduling design**

---

### 🔹 Execution Tracing

* Time-based execution log:

```
[t=0] T1 -> [t=4] T2 -> [t=6] T3 -> ...
```

* Tracks:

  * Context switches
  * CPU idle time
  * Task transitions

---

### 🔹 Performance Metrics

* Average Waiting Time
* Average Turnaround Time
* Context Switch Count
* CPU Idle Time

---

### 🔹 Visualization (Frontend)

* Simple React UI to display scheduler output
* Reads execution logs from backend (`output.txt`)
* Demonstrates **separation of computation and visualization**

---

## 🏗️ System Design

FocusForge follows a clean architecture inspired by OS design:

* **Policy Engine** → decides which scheduling algorithm to use
* **Scheduler Runner** → executes scheduling (kernel-style)
* **Scheduler Classes** → implement individual algorithms
* **Execution Logger** → tracks timeline and stats
* **Frontend** → visualizes output

---

## ▶️ How to Run

### 🔧 Backend (C++)

```bash
build
focusforge.exe
```

Follow CLI instructions to:

* Add tasks
* Choose scheduling mode (AUTO / Manual)
* View execution results

---

### 🖥️ Frontend (React)

```bash
cd frontend
npm install
npm run dev
```

* Click **"Show Output"** to visualize execution
* Make sure backend is run before viewing

---

## 💡 Key Concepts Demonstrated

* CPU Scheduling Algorithms
* Multi-Level Feedback Queue (MLFQ)
* Policy vs Mechanism Design
* Execution Tracing (OS-style logging)
* Performance Metrics Analysis
* Backend–Frontend separation

---

## 🎯 Purpose of the Project

This project is designed to:

* Demonstrate strong understanding of **Operating Systems concepts**
* Simulate real-world CPU scheduling behavior
* Showcase system design thinking beyond basic implementations
* Provide a foundation for further extensions (APIs, visualization, real-time scheduling)

---

## 🚀 Future Improvements (Optional)

* Full frontend-backend integration (API-based)
* Gantt chart visualization
* Real-time simulation
* Process preemption visualization

---

## 👨‍💻 Author

**Praneeth**

---

## ⭐ Final Note

FocusForge focuses on **correct system design and execution logic**, with visualization as a supporting layer — similar to how real operating systems separate computation from monitoring tools.

---
