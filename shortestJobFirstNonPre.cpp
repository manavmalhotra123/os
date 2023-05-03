#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

class Process {
public:
    int pid;
    int arrivalTime;
    int burstTime;
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

    sort(processes, processes + n, compare);

    cout << left << setw(10) << "Process" << setw(20) << "Arrival Time" << setw(20) << "Burst Time" << setw(20) << "Waiting Time" << setw(20) << "Turnaround Time" << endl;

    for (int i = 0; i < n; i++) {
        // Checking if process has arrived
        while (currentTime < processes[i].arrivalTime) {
            currentTime++;
        }

        // Calculating waiting time and Turn Around Time
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        processes[i].turnAroundTime = processes[i].waitingTime + processes[i].burstTime;

        // Updating total waiting time and total turn around time
        totalWaitingTime += processes[i].waitingTime;
        totalTurnAroundTime += processes[i].turnAroundTime;

        // Updating current time
        currentTime += processes[i].burstTime;

        // Printing process details
        cout << left << setw(10) << processes[i].pid << setw(20) << processes[i].arrivalTime << setw(20) << processes[i].burstTime << setw(20) << processes[i].waitingTime << setw(20) << processes[i].turnAroundTime << endl;
    }

    double avgWaitingTime = (float)totalWaitingTime / n;
    double avgTurnaroundTime = (float)totalTurnAroundTime / n;

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
    }

    sjfScheduling(processes, n);

    return 0;
}

