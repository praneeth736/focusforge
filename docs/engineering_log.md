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
