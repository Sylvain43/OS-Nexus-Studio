# OS-Nexus-Studio

A comprehensive multi-component system featuring custom memory allocator, enhanced CPU scheduler with GUI, and file server.

## 🚀 Quick Start

### Option 1: GUI Frontend (Recommended)
```cmd
python client/mainClient.py
```

### Option 2: Backend Terminal (Single Entry Point)
```cmd
server/main_system.exe
```


## 🎯 Single Backend Entry Point

The [`server/main_system.exe`](server/main_system.cpp) is the **main and only required backend file**. Running it gives you access to ALL features:

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


## ✨ Features

### 🎨 Modern GUI Frontend
- Clean, professional tkinter interface with custom themes
- **Add custom processes** with ID, Arrival Time, Burst Time, Priority
- **Clear all processes** or **load sample data**
- One-click algorithm execution (FCFS, SJF, Priority, Round Robin)
- Visual results with tabbed output
- **All processes stored in frontend - customize your own data!**

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
├── .gitignore                # Git ignore rules
├── client/
│   └── mainClient.py         # ⭐ Modern tkinter GUI
└── server/
    ├── main_system.cpp       # ⭐ MAIN BACKEND (All-in-one)
    ├── main_system.exe        # ⭐ Compiled executable
    ├── scheduler.cpp         # Standalone scheduler (optional)
    ├── scheduler.exe         # Standalone executable (optional)
    ├── file_server.cpp       # Standalone file server (optional)
    └── file_server.exe       # Standalone executable (optional)
```

> **Note:** Only `main_system.cpp` and `main_system.exe` are required. The standalone files are optional extras.


## 🎮 Usage Guide

### GUI Frontend

1. Launch the GUI:
   ```cmd
   python client/mainClient.py
   ```

2. **Add Custom Processes:**
   - Enter Process ID (e.g., P1), Arrival Time, Burst Time, Priority
   - Click "Add Process" to add to the list
   - Click "Clear All" to reset
   - Click "Load Sample Data" to restore default 5 processes

3. **Run Algorithms:**
   - Click any algorithm button (FCFS, SJF, Priority, Round Robin)
   - Your custom processes will be sent to the backend for processing
   - Or "Run All Algorithms" for comparison
   - View results in the tabbed panels

4. **Enhanced Backend:**
   - Click "Run Memory Test" to test custom allocator
   - Click "Run All Schedulers" for comprehensive output
   - Click "Open Backend Terminal" to run interactively

### Backend Terminal (Single Entry Point)

Run the main backend executable:
```cmd
server/main_system.exe
```

The system comes pre-loaded with 5 sample processes. Simply choose an option from the menu:


## 🔧 Building from Source

### Compile Main Backend (Required)
```cmd
g++ -std=c++11 -o server/main_system server/main_system.cpp -lws2_32
```

### Optional: Compile Standalone Scheduler
```cmd
g++ -std=c++11 -o server/scheduler server/scheduler.cpp
```

### Optional: Compile Standalone File Server
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
| [`server/main_system.cpp`](server/main_system.cpp) | ⭐ **Main backend** - Complete system with memory allocator, all schedulers, and file server |
| [`client/mainClient.py`](client/mainClient.py) | ⭐ **GUI Frontend** - Add custom processes, run algorithms, view results |
| [`server/scheduler.cpp`](server/scheduler.cpp) | Standalone CPU scheduler (optional) |
| [`server/file_server.cpp`](server/file_server.cpp) | Standalone TCP file server (optional) |


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
