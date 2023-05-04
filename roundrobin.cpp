#include <iostream>
#include <iomanip>

using namespace std;

class Process
{
public:
    int pid;
    int arrival;
    int burst;
    int turn;
    int wait;
    int remain;
};

void roundrobin(Process process[], int n, int quanta)
{
    int current = 0;
    int totalwait = 0;
    int totalturn = 0;
    int completed = 0;

    while (completed != n)
    {
        for (int i = 0; i < n; i++)
        {
            if (process[i].remain > 0)
            {
                current += quanta;
                process[i].remain -= quanta;
            }
            else
            {
                current += process[i].remain;
                process[i].wait = current - process[i].arrival;
                process[i].turn = process[i].wait + process[i].burst;

                totalturn += process[i].turn;
                totalwait += process[i].wait;
                process[i].remain = 0;
                completed++;
            }

            double a = (float)totalturn / n;
            double b = (float)totalwait / n;

            cout << left << setw(10) << "Process" << setw(20) << "Waiting Time" << setw(20) << "Turnaround Time" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << left << setw(10) << process[i].pid << setw(20) << process[i].wait << setw(20) << process[i].turn << endl;
            }

            // Printing average waiting time and average turn around time
            cout << "--------------------------------------------------------------------" << endl;
            cout << "Average Waiting Time = " << a << endl;
            cout << "Average Turnaround Time = " << b << endl;
            cout << "--------------------------------------------------------------------" << endl;
        }
    }
}


int main(){
    Process processes[100];
    int n, quantum;

    cout << "Enter the number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the arrival time and burst time of process " << i + 1 << ": ";
        cin >> processes[i].arrival >> processes[i].burst;
        processes[i].pid = i + 1;
        processes[i].remain = processes[i].burst;
    }

    cout << "Enter the time quantum: ";
    cin >> quantum;

    roundrobin(processes, n, quantum);

    return 0;
   
}
