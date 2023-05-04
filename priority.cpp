#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

class Process
{
    public:
    int pid;
    int arrival;
    int burst;
    int priority;
    int waitingTime;
    int turnAroundTime;
};

bool compare(Process p1, Process p2)
{
    return p1.priority < p2.priority;
}

void priority(Process process[], int n)
{
    int totalwait = 0;
    int totalturn = 0;
    int current = process[0].arrival;

    sort(process,process + n, compare);

    for (int i = 0; i < n; i++)
    {
        process[i].waitingTime = current - process[i].arrival;
        process[i].turnAroundTime = process[i].waitingTime + process[i].burst;

        totalwait += process[i].waitingTime;
        totalturn += process[i].turnAroundTime;

        current += process[i].burst;

    }

    double avgWaitingTime = (float)totalwait / n;
    double avgTurnaroundTime = (float)totalturn / n;

    // Printing process details
    cout << left << setw(10) << "Process" << setw(20) << "Arrival Time" << setw(20) << "Burst Time" << setw(20) << "Priority" << setw(20) << "Waiting Time" << setw(20) << "Turnaround Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << process[i].pid << setw(20) << process[i].arrival << setw(20) << process[i].burst << setw(20) << process[i].priority << setw(20) << process[i].waitingTime << setw(20) << process[i].turnAroundTime << endl;
    }

    // Printing average waiting time and average turn around time
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Average Waiting Time = " << avgWaitingTime << endl;
    cout << "Average Turnaround Time = " << avgTurnaroundTime << endl;
    cout << "--------------------------------------------------------------------" << endl;

    
}


int main(){
       Process processes[100];
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the arrival time, burst time, and priority of process " << i + 1 << ": ";
        cin >> processes[i].arrival >> processes[i].burst >> processes[i].priority;
        processes[i].pid = i + 1;
    }

    priority(processes, n);

 
    return 0;
}
