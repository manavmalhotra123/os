#include <iostream>
#include <string>
#include <limits> // for numeric_limits
using namespace std;

int main()
{
    bool is_running = true;
    string command;
    int TOTAL;
    cout << "Enter total memory" << endl;
    cin >> TOTAL;

    // initialize the total memory
    int memory[TOTAL] = {0};             // 0 means free space here
    int process_allocation[TOTAL] = {0}; // mapping the memory location
    int next_process_id = 1;             // it will get incremented with every new process command

    cout << "Logging in..." << endl;

    cout << "new    : for allocating memory to new command" << endl;
    cout << "remove : for terminating the process" << endl;
    cout << "list   : to list down all the processes" << endl;
    cout << "exit   : shutdown all the processes" << endl;

    while (is_running)
    {
        cout << ">";
        cin >> command;

        if (command == "exit")
        {
            is_running = false; // break the loop
        }
        else if (command == "new")
        {
            int requested_size;
            cout << "Enter the requested memory size" << endl;
            cin >> requested_size;

            if (requested_size == 0)
            {
                cout << "Process actually dont exist or error in creating the process" << endl;
            }
            else
            {
                int start_address = -1;
                int min_size = numeric_limits<int>::max(); // set to max possible value
                for (int i = 0; i < TOTAL; i++)
                {
                    if (memory[i] == 0)
                    {
                        int j = i;
                        while (j < TOTAL && memory[j] == 0)
                        {
                            j++;
                        }
                        if (j - i >= requested_size && j - i < min_size)
                        {
                            start_address = i;
                            min_size = j - i;
                        }
                        i = j; // skip to the next free block
                    }
                }

                if (start_address != -1)
                {
                    for (int i = start_address; i < start_address + requested_size; i++)
                    {
                        memory[i] = 1;
                        process_allocation[i] = next_process_id;
                    }
                    cout << "Process " << next_process_id << " created with starting address " << start_address << endl;
                    next_process_id++;
                }

                else
                {
                    cout << "not enough memory to create the process of requested size" << endl;
                }
            }
        }else if (command == "list") {
            for (int i = 0; i < TOTAL; i++) {
                if (process_allocation[i] != 0) {
                    int process_id = process_allocation[i];
                    int size = 1;
                    while (i + size < TOTAL && process_allocation[i + size] == process_id) {
                        size++;
                    }
                    cout << "Process " << process_id << " at address " << i << " with size " << size << endl;
                    i += size - 1;
                }
            }
        } else if (command == "remove") {
            int process_id;
            cout << "Enter the ID of the process to remove: ";
            cin >> process_id;

            bool found = false;
            for (int i = 0; i < TOTAL; i++) {
                if (process_allocation[i] == process_id) {
                    int size = 1;
                    while (i + size < TOTAL && process_allocation[i + size] == process_id) {
                        size++;
                    }
                    for (int j = i; j < i + size; j++) {
                        memory[j] = 0;
                        process_allocation[j] = 0;
                    }
                    cout << "Process " << process_id << " removed" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Process with ID " << process_id << " not found" << endl;
            }
        } else {
            cout << "Unknown command: " << command << endl;
        }
    }

    cout << "Goodbye!\n";
    return 0;
}

