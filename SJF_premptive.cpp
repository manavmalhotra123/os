#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>

using namespace std;

class Process {
public:
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnAroundTime;
};

bool compare(Process p1, Process p2) {
    return p1.burstTime < p2.burstTime;
}

void sjfScheduling(Process processes[], int n) {
    int currentTime = 0;
    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;
    int completedProcesses = 0;
    queue<Process> readyQueue;

    while (completedProcesses < n) {
        // Adding arrived processes to the ready queue
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0) {
                readyQueue.push(processes[i]);
            }
        }

        // If ready queue is empty, increment current time
        if (readyQueue.empty()) {
            currentTime++;
            continue;
        }

        // Selecting process with shortest remaining time
        Process currentProcess = readyQueue.front();
        readyQueue.pop();

        // Calculating waiting time and Turn Around Time
        currentProcess.waitingTime += currentTime - currentProcess.arrivalTime;
        currentProcess.turnAroundTime = currentProcess.waitingTime + currentProcess.burstTime;

        // Updating total waiting time and total turn around time
        totalWaitingTime += currentProcess.waitingTime;
        totalTurnAroundTime += currentProcess.turnAroundTime;

        // Decrementing remaining time of current process
        currentProcess.remainingTime--;

        // If process is completed, increment completedProcesses counter
        if (currentProcess.remainingTime == 0) {
            completedProcesses++;
        } else {
            // Otherwise, add process back to ready queue
            readyQueue.push(currentProcess);
        }

        // Updating current time
        currentTime++;
    }

    double avgWaitingTime = (float)totalWaitingTime / n;
    double avgTurnaroundTime = (float)totalTurnAroundTime / n;

    // Printing process details
    cout << left << setw(10) << "Process" << setw(20) << "Arrival Time" << setw(20) << "Burst Time" << setw(20) << "Waiting Time" << setw(20) << "Turnaround Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << processes[i].pid << setw(20) << processes[i].arrivalTime << setw(20) << processes[i].burstTime << setw(20) << processes[i].waitingTime << setw(20) << processes[i].turnAroundTime << endl;
    }

    // Printing average waiting time and average turn around time
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Average Waiting Time = " << avgWaitingTime << endl;
    cout << "Average Turnaround Time = " << avgTurnaroundTime << endl;
    cout << "--------------------------------------------------------------------" << endl;
}

int main() {
    Process processes[100];
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the arrival time of process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter the burst time of process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
        processes[i].pid = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
    }

    sjfScheduling(processes, n);

    return 0;
}
