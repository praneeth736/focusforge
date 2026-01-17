# FocusForge Engineering Log

## Day 1 – Core Scheduler Refactor
- Extracted Task model (process control block)
- Added Scheduler interface (kernel abstraction)
- Implemented FCFS as pluggable engine
- Connected main.cpp to new scheduler

OS Concepts:
- Task = Process Control Block
- Scheduler = Kernel scheduling policy
- FCFS = Non-preemptive scheduling

Result:
FocusForge now runs scheduling algorithms using a real OS-style engine.


## Day 2 – Multi-Policy Kernel & Auto Scheduling

Today FocusForge was upgraded from a single-policy scheduler to a **multi-policy OS kernel**.

### What was added
- Implemented **SJF (Shortest Job First)** as a kernel scheduling policy  
- Implemented **Priority Scheduling** (lower number = higher priority)  
- Implemented **Round Robin** with configurable time quantum  
- Added a **Policy Engine** that chooses a scheduling policy automatically  
- Extended main.cpp to support:
  - FCFS
  - SJF
  - Priority
  - Round Robin
  - AUTO mode

### OS Concepts Implemented
- **Scheduling Policies**  
  FCFS, SJF, Priority, and Round Robin are now independent **policy modules** plugged into the same kernel.

- **Policy vs Mechanism Separation**  
  The Scheduler class provides the scheduling mechanism (task list, run loop, statistics).  
  Each algorithm only implements the policy (who should run next).

- **AUTO Mode = Workload-aware Scheduling**  
  FocusForge now analyzes workload patterns (CPU burst lengths) to automatically choose:
  - SJF when many short jobs exist  
  - FCFS when most jobs are long  

  This mimics how Linux, Kubernetes, and cloud schedulers adapt to workload instead of using a fixed algorithm.

### What FocusForge is now
FocusForge is no longer a collection of algorithms.
It is now a **kernel-driven scheduling engine** with:
- Pluggable scheduling policies
- Intelligent policy selection
- OS-style architecture

This mirrors how real operating systems and distributed systems schedule CPU and jobs.

## Day 3 – Preemptive Scheduling (SRTF)

Today FocusForge entered **true operating system territory** by implementing a
**preemptive CPU scheduler**.

### What was added
- Implemented **SRTF (Shortest Remaining Time First)** scheduling
- Added support for **task preemption**
- Introduced `remaining` burst time per task
- Integrated SRTF into the existing kernel scheduler
- Connected SRTF to main.cpp as a selectable policy
- Reused kernel statistics system (no duplicate logic)

---

### OS Concepts Implemented

#### Preemptive Scheduling
Unlike previous algorithms, SRTF can **interrupt a running task** if a new task
arrives with a shorter remaining execution time.

This is how real operating systems behave using timer interrupts.

---

### Key OS Mappings

| Operating System | FocusForge |
|------------------|------------|
| Process | Task |
| Process Control Block | Task struct |
| CPU Clock | `time++` |
| Timer Interrupt | Each simulation step |
| Context Switch | Changing running task |
| Remaining Burst | `remaining` |
| Kernel Scheduler | `Scheduler` base class |
| Scheduling Policy | FCFS / SJF / Priority / RR / SRTF |

---

### Why `remaining` time was required

Before:
- Only total burst time existed
- Algorithms were non-preemptive

Now:
- `burst` → original CPU requirement
- `remaining` → live execution time left

Only `remaining` is modified during execution.

This exactly mirrors how kernels track running processes.

---

### How SRTF works internally

At every time unit:

1. Check which tasks have arrived
2. Select the task with **smallest remaining time**
3. Run it for **1 time unit**
4. Decrease its remaining time
5. If remaining becomes zero → task finishes
6. Repeat until all tasks complete

This causes frequent context switching — just like real CPUs.

---

### Architectural clarity gained today

