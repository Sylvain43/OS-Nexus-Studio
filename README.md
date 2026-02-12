# OS-Nexus-Studio

OS Nexus Studio is an educational operating system simulation platform combining a high-performance C++ backend with a Python GUI frontend. It demonstrates CPU scheduling algorithms (FCFS, SJF, Priority, Round Robin) alongside a multithreaded TCP file server for concurrent client handling. Designed for clarity and learning, the project visualizes process execution, networking, and synchronization concepts in a practical environment 🚀, making core OS concepts easier to understand and experiment with 🧠.

[![Github License](https://img.shields.io/github/license/UjjwalSaini07/OS-Nexus-Studio)](https://github.com/UjjwalSaini07/OS-Nexus-Studio/blob/main/LICENSE)
[![Info](https://img.shields.io/badge/Project-Info-blue?style=flat&logo=data:image/svg%2bxml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iaXNvLTg4NTktMSI/Pg0KPCEtLSBHZW5lcmF0b3I6IEFkb2JlIElsbHVzdHJhdG9yIDE5LjAuMCwgU1ZHIEV4cG9ydCBQbHVnLUluIC4gU1ZHIFZlcnNpb246IDYuMDAgQnVpbGQgMCkgIC0tPg0KPHN2ZyB2ZXJzaW9uPSIxLjEiIGlkPSJDYXBhXzEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgeG1sbnM6eGxpbms9Imh0dHA6Ly93d3cudzMub3JnLzE5OTkveGxpbmsiIHg9IjBweCIgeT0iMHB4Ig0KCSB2aWV3Qm94PSIwIDAgNTEyIDUxMiIgc3R5bGU9ImVuYWJsZS1iYWNrZ3JvdW5kOm5ldyAwIDAgNTEyIDUxMjsiIHhtbDpzcGFjZT0icHJlc2VydmUiPg0KPHBhdGggc3R5bGU9ImZpbGw6IzBBNEVBRjsiIGQ9Ik0yNTYsNTEyYy02OC4zOCwwLTEzMi42NjctMjYuNjI5LTE4MS4wMi03NC45OEMyNi42MjksMzg4LjY2NywwLDMyNC4zOCwwLDI1Ng0KCVMyNi42MjksMTIzLjMzMyw3NC45OCw3NC45OEMxMjMuMzMzLDI2LjYyOSwxODcuNjIsMCwyNTYsMHMxMzIuNjY3LDI2LjYyOSwxODEuMDIsNzQuOThDNDg1LjM3MSwxMjMuMzMzLDUxMiwxODcuNjIsNTEyLDI1Ng0KCXMtMjYuNjI5LDEzMi42NjctNzQuOTgsMTgxLjAyQzM4OC42NjcsNDg1LjM3MSwzMjQuMzgsNTEyLDI1Niw1MTJ6Ii8+DQo8cGF0aCBzdHlsZT0iZmlsbDojMDYzRThCOyIgZD0iTTQzNy4wMiw3NC45OEMzODguNjY3LDI2LjYyOSwzMjQuMzgsMCwyNTYsMHY1MTJjNjguMzgsMCwxMzIuNjY3LTI2LjYyOSwxODEuMDItNzQuOTgNCglDNDg1LjM3MSwzODguNjY3LDUxMiwzMjQuMzgsNTEyLDI1NlM0ODUuMzcxLDEyMy4zMzMsNDM3LjAyLDc0Ljk4eiIvPg0KPHBhdGggc3R5bGU9ImZpbGw6I0ZGRkZGRjsiIGQ9Ik0yNTYsMTg1Yy0zMC4zMjcsMC01NS0yNC42NzMtNTUtNTVzMjQuNjczLTU1LDU1LTU1czU1LDI0LjY3Myw1NSw1NVMyODYuMzI3LDE4NSwyNTYsMTg1eiBNMzAxLDM5NQ0KCVYyMTVIMTkxdjMwaDMwdjE1MGgtMzB2MzBoMTQwdi0zMEgzMDF6Ii8+DQo8Zz4NCgk8cGF0aCBzdHlsZT0iZmlsbDojQ0NFRkZGOyIgZD0iTTI1NiwxODVjMzAuMzI3LDAsNTUtMjQuNjczLDU1LTU1cy0yNC42NzMtNTUtNTUtNTVWMTg1eiIvPg0KCTxwb2x5Z29uIHN0eWxlPSJmaWxsOiNDQ0VGRkY7IiBwb2ludHM9IjMwMSwzOTUgMzAxLDIxNSAyNTYsMjE1IDI1Niw0MjUgMzMxLDQyNSAzMzEsMzk1IAkiLz4NCjwvZz4NCjxnPg0KPC9nPg0KPGc+DQo8L2c+DQo8Zz4NCjwvZz4NCjxnPg0KPC9nPg0KPGc+DQo8L2c+DQo8Zz4NCjwvZz4NCjxnPg0KPC9nPg0KPGc+DQo8L2c+DQo8Zz4NCjwvZz4NCjxnPg0KPC9nPg0KPGc+DQo8L2c+DQo8Zz4NCjwvZz4NCjxnPg0KPC9nPg0KPGc+DQo8L2c+DQo8Zz4NCjwvZz4NCjwvc3ZnPg0K)](https://github.com/UjjwalSaini07/OS-Nexus-Studio/blob/main/README.md)
[![Generic badge](https://img.shields.io/badge/Owner-@Ujjwal-<COLOR>.svg)](https://github.com/UjjwalSaini07/OS-Nexus-Studio)
[![Generic Repo Size badge](https://img.shields.io/github/repo-size/UjjwalSaini07/OS-Nexus-Studio?style=flat&logo=github)](https://github.com/UjjwalSaini07/OS-Nexus-Studio)
[![GitHub stars](https://img.shields.io/github/stars/UjjwalSaini07/OS-Nexus-Studio?style=social&label=Star&maxAge=2592100)](https://github.com/UjjwalSaini07/OS-Nexus-Studio/stargazers)
[![Github Release](https://img.shields.io/github/v/release/UjjwalSaini07/OS-Nexus-Studio)](https://github.com/UjjwalSaini07/OS-Nexus-Studio)

![OS-Nexus](https://github.com/user-attachments/assets/ea742259-00f3-4085-81f2-12f7e3fff0e3)


## Table of Contents

| SNo. | Section | Link |
|---|--------|-----|
| 1 | Overview | [Overview](#overview) |
| 2 | Features | [Features](#features) |
| 2.1 | CPU Scheduling | [CPU Scheduling](#cpu-scheduling) |
| 2.2 | Memory Allocator | [Memory Allocator](#memory-allocator) |
| 2.3 | File Server | [File Server](#file-server) |
| 3 | Getting Started | [Getting Started](#getting-started) |
| 4 | Project Structure | [Project Structure](#project-structure) |
| 5 | Usage Guide | [Usage Guide](#usage-guide) |
| 5.1 | GUI Frontend | [GUI Frontend](#gui-frontend) |
| 5.2 | Backend Terminal | [Backend Terminal](#backend-terminal) |
| 5.3 | API Mode | [API Mode](#api-mode) |
| 6 | Architecture | [Architecture](#architecture) |
| 7 | Building from Source | [Building from Source](#building-from-source) |
| 8 | API Reference | [API Reference](#api-reference) |
| 9 | Examples | [Examples](#examples) |
|10 | Troubleshooting | [Troubleshooting](#troubleshooting) |
|11 | License | [License](#license) |

## 🧩 Overview

**OS Nexus Studio** is an interactive operating system simulation platform built to transform theoretical OS concepts into practical experience. The project integrates real execution logic with visual interaction, allowing users to observe how core system components behave, interact, and respond under different conditions.

The platform demonstrates:

### ⚙️ Core Modules
- **CPU Scheduling** — Multiple algorithms (FCFS, SJF, Priority, Round Robin) with execution timelines, waiting/turnaround metrics, and comparative analysis
- **Memory Management** — Custom block-based allocator illustrating allocation, deallocation, and fragmentation behavior
- **Networking** — Multithreaded TCP file server supporting concurrent clients and request handling

### 🧠 Learning & Analysis
- Visual understanding of process lifecycle and queue behavior
- Performance comparison between scheduling strategies
- Practical demonstration of concurrency and synchronization
- Safe experimentation without affecting the real system

### 🎯 Purpose
OS Nexus Studio bridges the gap between academic theory and real operating system behavior. Instead of only reading algorithms, users can run, observe, and analyze them in action — making complex OS concepts easier to understand, test, and demonstrate in an educational or academic setting.

The project serves as a compact laboratory for exploring how operating systems manage processes, memory, and communication in a controlled environment.



## Features

### CPU Scheduling

Four scheduling algorithms with comprehensive metrics:

| Algorithm | Type | Description | Time Quantum |
|-----------|------|-------------|-------------|
| FCFS | Non-preemptive | First Come First Serve | - |
| SJF | Non-preemptive | Shortest Job First | - |
| Priority | Non-preemptive | Priority-based scheduling | - |
| Round Robin | Preemptive | Time-slice based | 2 units |

**Metrics Provided:**
- Process execution timeline
- Completion time (CT)
- Turnaround time (TAT)
- Waiting time (WT)
- Average statistics
- Gantt chart visualization

### Memory Allocator

Custom block-based allocator implementing:

- **1MB Heap** - Pre-allocated virtual memory
- **First-Fit Strategy** - Finds first suitable block
- **Block Splitting** - Divides large blocks for efficiency
- **Coalescing** - Merges adjacent free blocks
- **Fragmentation Tracking** - Real-time statistics

**Statistics:**
- Total heap size
- Allocated memory
- Free memory
- Fragmentation percentage

### File Server

Multi-client TCP server on port 9090:

| Command | Description | Usage |
|---------|-------------|-------|
| LIST | List available files | `LIST` |
| GET | Download file contents | `GET <filename>` |
| INFO | Get file size | `INFO <filename>` |

**Features:**
- Concurrent client handling
- Real-time connection status
- Binary and text file support


## Getting Started

### Prerequisites

- Python 3.8+ (for GUI frontend)
- MinGW-w64 with g++ (for backend compilation)
- Windows 10/11

### Quick Start

#### GUI Frontend (Recommended)
```cmd
python client/mainClient.py
```

#### Backend Terminal
```cmd
server/main_system.exe
```


## Project Structure

```
OS-Nexus-Studio/
├── README.md                 # Documentation
├── LICENSE                    # MIT License
├── .gitignore                # Git ignore rules
├── client/
│   └── mainClient.py         # GUI Frontend (Python/tkinter)
└── server/
    ├── main_system.cpp       # Main backend (C++)
    ├── main_system.exe       # Compiled executable
    ├── scheduler.cpp         # Standalone scheduler
    ├── scheduler.exe         # Compiled executable
    ├── file_server.cpp       # Standalone file server
    └── file_server.exe       # Compiled executable
```


## Usage Guide

### GUI Frontend

#### Adding Processes

1. Enter process details:
   - **Process ID** - Unique identifier (e.g., P1, P2)
   - **Arrival Time** - When process arrives
   - **Burst Time** - CPU time required
   - **Priority** - Scheduling priority (1-10)

2. Click "Add Process"

3. Manage processes:
   - "Clear All" - Remove all processes
   - "Load Sample Data" - Restore default 5 processes
   - "Refresh Process List" - Reload from backend

#### Running Algorithms

1. Select an algorithm:
   - FCFS
   - SJF
   - Priority
   - Round Robin
   - "Run All Algorithms" - Compare all

2. View results in tabbed panels

3. Gantt chart displays execution timeline

#### Backend Features

- **Run Memory Test** - Test custom allocator
- **Start File Server** - Launch TCP server
- **Open Backend Terminal** - Interactive mode

### Backend Terminal

Run `server/main_system.exe` for interactive mode:

```
=============== MAIN MENU ===============
  1. Memory Allocator Test
  2. CPU Scheduler (FCFS)
  3. CPU Scheduler (SJF)
  4. CPU Scheduler (Priority)
  5. CPU Scheduler (Round Robin)
  6. Run All Schedulers
  7. Start File Server
  9. List Processes (API)
 10. Add Process (API)
 11. Clear All Processes (API)
 12. Load Sample Processes (API)
  8. Exit
```

### API Mode

The backend supports programmatic access via pipe I/O:

**Input Format:**
```
<num_processes>
<arrival_time> <burst_time> <priority>
...
<algorithm_option>
8
```

**Example (FCFS with 3 processes):**
```
3
0 5 2
1 3 1
2 8 4
2
8
```

**Response Format:**
```
--- Running FCFS Scheduler ---
P1: 0 -> 5 | Waiting: 0
P2: 5 -> 8 | Waiting: 4
...

--- Scheduling Statistics ---
ID    AT    BT    CT    TAT    WT
----------------------------------------
P1    0     5     5     5      0
...

Avg Waiting Time: 3.33
Avg Turnaround Time: 7.33
```


## Architecture

### System Components

```
┌─────────────────────────────────────────┐
│           GUI Frontend                   │
│         (Python/tkinter)                 │
│                                         │
│  - Process management UI                 │
│  - Algorithm selection                   │
│  - Result visualization                 │
└─────────────────┬───────────────────────┘
                  │
                  ▼
┌─────────────────────────────────────────┐
│           Backend (C++)                  │
│                                         │
│  ┌─────────────────────────────────┐    │
│  │    Custom Memory Allocator       │    │
│  └─────────────────────────────────┘    │
│                                         │
│  ┌─────────────────────────────────┐    │
│  │    CPU Scheduler                 │    │
│  │  - FCFS  - SJF                  │    │
│  │  - Priority  - Round Robin       │    │
│  └─────────────────────────────────┘    │
│                                         │
│  ┌─────────────────────────────────┐    │
│  │    TCP File Server               │    │
│  │  - LIST  - GET  - INFO          │    │
│  └─────────────────────────────────┘    │
└─────────────────────────────────────────┘
```

### Data Flow

1. User creates processes in GUI
2. Frontend sends data to backend via pipe
3. Backend computes scheduling results
4. Results returned and visualized in GUI


## Building from Source

### Main Backend (Required)

```cmd
g++ -std=c++11 -o server/main_system server/main_system.cpp -lws2_32
```

### Standalone Scheduler (Optional)

```cmd
g++ -std=c++11 -o server/scheduler server/scheduler.cpp
```

### Standalone File Server (Optional)

```cmd
g++ -o server/file_server server/file_server.cpp -lws2_32
```


## API Reference

### Process Structure

```cpp
struct Process {
    int id;           // Process identifier
    int arrival;      // Arrival time
    int burst;         // Burst time (CPU required)
    int priority;      // Scheduling priority
    int completion;    // Completion time
    int turnaround;   // Turnaround time
    int waiting;      // Waiting time
};
```

### Scheduler Methods

| Method | Description |
|--------|-------------|
| `addProcess()` | Add a process to the queue |
| `runFCFS()` | Execute FCFS scheduling |
| `runSJF()` | Execute SJF scheduling |
| `runPriority()` | Execute Priority scheduling |
| `runRoundRobin(q)` | Execute Round Robin with quantum q |
| `getProcesses()` | Get all processes |
| `clear()` | Clear all processes |

### Memory Allocator Methods

| Method | Description |
|--------|-------------|
| `allocate(size)` | Allocate memory block |
| `deallocate(ptr)` | Free allocated block |
| `printStats()` | Print allocation statistics |

## Examples

### Example 1: FCFS Scheduling

**Input:**
```
3
0 5 2
1 3 1
2 8 4
2
8
```

**Output:**
```
--- Running FCFS Scheduler ---
P1: 0 -> 5 | Waiting: 0
P2: 5 -> 8 | Waiting: 4
P3: 8 -> 16 | Waiting: 6

--- Scheduling Statistics ---
ID    AT    BT    CT    TAT    WT
----------------------------------------
P1    0     5     5     5      0
P2    1     3     8     7      4
P3    2     8     16    14     6
----------------------------------------
Avg Waiting Time: 3.33
Avg Turnaround Time: 8.67
```

### Example 2: Memory Allocation Test

**Output:**
```
=== Memory Allocator Test ===
=== Memory Allocator Stats ===
Total Heap Size: 1024 KB
Allocated: 0 KB
Free: 1024 KB
Fragmentation: 0.00%
[OK] Freed block P2
=== Memory Allocator Stats ===
Total Heap Size: 1024 KB
Allocated: 0 KB
Free: 1024 KB
Fragmentation: 0.00%
```


## Troubleshooting

| Issue | Solution |
|-------|----------|
| g++ not found | Install MinGW-w64 and add to PATH. Restart terminal after installation. |
| Python not found | Reinstall Python with "Add to PATH" option enabled. |
| GUI won't start | Ensure tkinter is installed: `pip install tk` |
| Port 9090 in use | Close any running file server or change PORT in source code |
| Backend crashes | Ensure no other instance is running. Check Task Manager. |


## License

MIT License - Open-source project for educational purposes.

Copyright (c) 2026 Ujjwal Saini
