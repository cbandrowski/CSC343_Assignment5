#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int id, burst_time, waiting_time, turnaround_time;
};

// Function to calculate WT & TAT for FCFS
void FCFS(Process processes[], int n) {
    processes[0].waiting_time = 0;  // First process has no waiting time
    for (int i = 1; i < n; i++)
        processes[i].waiting_time = processes[i-1].waiting_time + processes[i-1].burst_time;
    
    for (int i = 0; i < n; i++)
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

    // Display FCFS results
    cout << "\n----------------- FCFS -----------------\n";
    cout << "Process ID | Waiting Time | Turnaround Time\n";
    for (int i = 0; i < n; i++)
        cout << "     " << processes[i].id << "           |      " 
             << processes[i].waiting_time << "                 |        " 
             << processes[i].turnaround_time << endl;
}

// Function to calculate WT & TAT for SJF (Non-preemptive)
void SJF(Process processes[], int n) {
    sort(processes, processes + n, [](Process a, Process b) {
        return a.burst_time < b.burst_time;  // Sorting by burst time
    });

    processes[0].waiting_time = 0;
    for (int i = 1; i < n; i++)
        processes[i].waiting_time = processes[i-1].waiting_time + processes[i-1].burst_time;

    for (int i = 0; i < n; i++)
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

    // Display SJF results
    cout << "\n----------------- SJF -----------------\n";
    cout << "Process ID | Waiting Time | Turnaround Time\n";
    for (int i = 0; i < n; i++)
        cout << "     " << processes[i].id << "           |      " 
             << processes[i].waiting_time << "                 |        " 
             << processes[i].turnaround_time << endl;
}

// Main Function
int main() {
    Process processes[] = {
        {1, 2}, {2, 1}, {3, 8}, {4, 4}, {5, 5}  // Process ID and Burst Time
    };
    int n = sizeof(processes) / sizeof(processes[0]);

    FCFS(processes, n);
    SJF(processes, n);

    return 0;
}
