#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 100;

class MemoryBlock {
public:
    int size;
    bool allocated;
};

void printMemoryBlocks(MemoryBlock memoryBlocks[], int n) {
    cout << left << setw(10) << "Block ID" << setw(20) << "Block Size" << setw(20) << "Allocated" << endl;
    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << i + 1 << setw(20) << memoryBlocks[i].size << setw(20) << (memoryBlocks[i].allocated ? "Yes" : "No") << endl;
    }
    cout << "--------------------------------------------------------------------" << endl;
}

void bestFit(MemoryBlock memoryBlocks[], int n, int processSize) {
    int bestFitIndex = -1;
    int bestFitSize = MAX;

    for (int i = 0; i < n; i++) {
        if (!memoryBlocks[i].allocated && memoryBlocks[i].size >= processSize && memoryBlocks[i].size < bestFitSize) {
            bestFitIndex = i;
            bestFitSize = memoryBlocks[i].size;
        }
    }

    if (bestFitIndex != -1) {
        memoryBlocks[bestFitIndex].allocated = true;
        cout << "Process allocated to block " << bestFitIndex + 1 << endl;
    }
    else {
        cout << "No block available for allocation" << endl;
    }
}

void worstFit(MemoryBlock memoryBlocks[], int n, int processSize) {
    int worstFitIndex = -1;
    int worstFitSize = 0;

    for (int i = 0; i < n; i++) {
        if (!memoryBlocks[i].allocated && memoryBlocks[i].size >= processSize && memoryBlocks[i].size > worstFitSize) {
            worstFitIndex = i;
            worstFitSize = memoryBlocks[i].size;
        }
    }

    if (worstFitIndex != -1) {
        memoryBlocks[worstFitIndex].allocated = true;
        cout << "Process allocated to block " << worstFitIndex + 1 << endl;
    }
    else {
        cout << "No block available for allocation" << endl;
    }
}

void firstFit(MemoryBlock memoryBlocks[], int n, int processSize) {
    for (int i = 0; i < n; i++) {
        if (!memoryBlocks[i].allocated && memoryBlocks[i].size >= processSize) {
            memoryBlocks[i].allocated = true;
            cout << "Process allocated to block " << i + 1 << endl;
            return;
        }
    }
    cout << "No block available for allocation" << endl;
}

int main() {
    MemoryBlock memoryBlocks[MAX];
    int n, processSize;

    cout << "Enter the number of memory blocks: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the size of block " << i + 1 << ": ";
        cin >> memoryBlocks[i].size;
        memoryBlocks[i].allocated = false;
    }

    printMemoryBlocks(memoryBlocks, n);

    while (true) {
        cout << "Enter the size of the process (-1 to exit): ";
        cin >> processSize;

        if (processSize == -1) {
            break;
        }

        cout << "Select the memory allocation algorithm:" << endl;
        cout << "1. Best Fit" << endl;
        cout << "2. Worst Fit" << endl;
        cout << "3. First Fit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            bestFit(memoryBlocks, n, processSize);
            break;
        case 2:
            worstFit(memoryBlocks, n, processSize);
            break;
        case 3:
            firstFit(memoryBlocks, n, processSize);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }

        printMemoryBlocks(memoryBlocks, n);
    }

    return 0;
}
