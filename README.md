# OS-Nexus-Studio

A comprehensive multi-component system featuring custom memory allocator, enhanced CPU scheduler with GUI, and file server.

## 🚀 Quick Start

### Run the Enhanced GUI Frontend

```cmd
python client/frontend.py
```

### Run Enhanced Backend (Terminal Mode)

```cmd
server/main_system.exe
```

## ✨ Features

### 🎨 Modern GUI Frontend
- Clean, professional tkinter interface with custom themes
- Real-time process management (add, view, clear)
- One-click algorithm execution (FCFS, SJF, Priority, Round Robin)
- Visual results with tabbed output
- Sample data loader for quick testing
- Connection to enhanced backend

### 🧠 Custom Memory Allocator
- **1MB Heap** with block-based allocation
- **First-fit allocation** strategy
- **Block splitting** for efficient memory use
- **Coalescing** to reduce fragmentation
- Real-time statistics (allocated, free, fragmentation %)

### ⚙️ Enhanced CPU Scheduler
All scheduling algorithms with detailed statistics:

| Algorithm | Description |
|-----------|-------------|
| **FCFS** | First Come First Serve |
| **SJF** | Shortest Job First (Non-preemptive) |
| **Priority** | Priority-based scheduling |
| **Round Robin** | Time quantum-based (Q=2) |

Each algorithm displays:
- Process execution timeline
- Completion time, Turnaround time, Waiting time
- Average statistics
- Gantt chart visualization

### 📁 Enhanced File Server
- **TCP-based** file server on port 9090
- **Commands supported:**
  - `LIST` - List available files
  - `GET <filename>` - Download file contents
  - `INFO <filename>` - Get file size info
- Multi-client support
- Real-time connection status


## 📁 Project Structure

```
OS-Nexus-Studio/
├── README.md                 # This file
├── LICENSE                   # MIT License
├── client/
│   └── frontend.py           # Modern tkinter GUI (Enhanced)
└── server/
    ├── main_system.cpp       # Enhanced system (Memory + Scheduler + File Server)
    ├── main_system.exe       # Compiled executable
    ├── scheduler.cpp         # Standalone scheduler
    ├── scheduler.exe         # Compiled executable
    ├── file_server.cpp       # Standalone file server
    └── file_server.exe       # Compiled executable
```


## 🎮 Usage Guide

### GUI Frontend

1. Launch the GUI:
   ```cmd
   python client/frontend.py
   ```

2. **Add Processes:**
   - Enter Process ID, Arrival Time, Burst Time, Priority
   - Click "Add Process"
   - Or click "Load Sample Data" for quick start

3. **Run Algorithms:**
   - Click any algorithm button (FCFS, SJF, Priority, Round Robin)
   - Or "Run All Algorithms" for comparison
   - View results in the tabbed panels

4. **Enhanced Backend:**
   - Click "Run Memory Test" to test custom allocator
   - Click "Run All Schedulers" for comprehensive output
   - Click "Open Backend Terminal" to run interactively

### Enhanced Backend (Terminal)

Run directly for interactive mode:
```cmd
server/main_system.exe
```

**Menu Options:**
```
=============== MAIN MENU ===============
  1. Memory Allocator Test       
  2. CPU Scheduler (FCFS)        
  3. CPU Scheduler (SJF)         
  4. CPU Scheduler (Priority)    
  5. CPU Scheduler (Round Robin)  
  6. Run All Schedulers          
  7. Start File Server           
  8. Exit                        
```


## 📊 Scheduler Input Format

For standalone scheduler:
```
<number_of_processes>
<arrival_time> <burst_time> <priority>
<arrival_time> <burst_time> <priority>
...
```

**Example:**
```
3
0 5 2
1 3 1
2 4 3
```


## 🔧 Building from Source

### Compile Enhanced Backend
```cmd
g++ -std=c++11 -o server/main_system server/main_system.cpp -lws2_32
```

### Compile Standalone Scheduler
```cmd
g++ -std=c++11 -o server/scheduler server/scheduler.cpp
```

### Compile Standalone File Server
```cmd
g++ -o server/file_server server/file_server.cpp -lws2_32
```


## 🐛 Troubleshooting

### "g++ not found"
- Install MinGW-w64 and add to PATH
- Restart terminal after installation

### "Python not found"
- Reinstall Python with "Add to PATH" option
- Or use full path: `C:\Python313\python.exe`

### GUI won't start
- Ensure Python is installed with tkinter support
- Install dependencies: `pip install tk`

### Port 9090 in use
- Close any running file server
- Or modify PORT constant in source code


## 🛠️ Technologies

| Component | Technology |
|-----------|------------|
| Backend | C++ (GCC/MinGW) |
| Memory | Custom Allocator (VirtualAlloc) |
| Networking | Winsock2 (Windows) |
| GUI | Python tkinter |
| OS | Windows 11 |


## 📝 File Descriptions

| File | Description |
|------|-------------|
| [`server/main_system.cpp`](server/main_system.cpp) | Complete system with memory allocator, all schedulers, and file server |
| [`server/scheduler.cpp`](server/scheduler.cpp) | Standalone CPU scheduler |
| [`server/file_server.cpp`](server/file_server.cpp) | Standalone TCP file server |
| [`client/frontend.py`](client/frontend.py) | Modern GUI frontend connecting to backend |


## 🎯 Sample Output

### Memory Allocator Test
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

### CPU Scheduler (FCFS)
```
--- Running FCFS Scheduler ---
P1: 0 -> 5 | Waiting: 0
P2: 5 -> 8 | Waiting: 4
P3: 8 -> 12 | Waiting: 6

--- Scheduling Statistics ---
ID    AT    BT    CT    TAT    WT
--------------------------------------------
P1    0     5     5     5      0
P2    1     3     8     7      4
P3    2     8     12    10     6
--------------------------------------------
Avg Waiting Time: 3.33
Avg Turnaround Time: 7.33
```


## 📚 License

MIT License - Open-source project for educational purposes.

Copyright (c) 2026 Ujjwal Saini
