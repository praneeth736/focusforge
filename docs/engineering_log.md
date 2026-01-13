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
