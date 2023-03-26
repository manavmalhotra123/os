// all types of algorithm - first fit , best fit and worst fit


#include <iostream>
#include <limits.h>

using namespace std;

// Function to find the best fit block
int bestFit(int freeList[], int n, int requestSize) {
    int bestBlock = -1;
    for (int i = 0; i < n; i++) {
        if (freeList[i] >= requestSize && (bestBlock == -1 || freeList[i] < freeList[bestBlock])) {
            bestBlock = i;
        }
    }
    return bestBlock;
}

// Function to find the first fit block
int firstFit(int freeList[], int n, int requestSize) {
    for (int i = 0; i < n; i++) {
        if (freeList[i] >= requestSize) {
            return i;
        }
    }
    return -1;
}

// Function to find the worst fit block
int worstFit(int freeList[], int n, int requestSize) {
    int worstBlock = -1;
    for (int i = 0; i < n; i++) {
        if (freeList[i] >= requestSize && (worstBlock == -1 || freeList[i] > freeList[worstBlock])) {
            worstBlock = i;
        }
    }
    return worstBlock;
}

int main() {
    // Create a free list
    int freeList[] = {100, 50, 200, 75, 300};
    int n = sizeof(freeList) / sizeof(freeList[0]);

    // Print the free list
    cout << "Free list: ";
    for (int i = 0; i < n; i++) {
        cout << freeList[i] << " ";
    }
    cout << endl;

    // Allocate some blocks using best fit
    int requestSize = 80;
    int bestBlock = bestFit(freeList, n, requestSize);
    if (bestBlock != -1) {
        cout << "Allocated " << requestSize << " bytes using best fit at position " << bestBlock << endl;
        freeList[bestBlock] -= requestSize;
    } else {
        cout << "Unable to allocate " << requestSize << " bytes using best fit" << endl;
    }

    // Allocate some blocks using first fit
    requestSize = 100;
    int firstBlock = firstFit(freeList, n, requestSize);
    if (firstBlock != -1) {
        cout << "Allocated " << requestSize << " bytes using first fit at position " << firstBlock << endl;
        freeList[firstBlock] -= requestSize;
    } else {
        cout << "Unable to allocate " << requestSize << " bytes using first fit" << endl;
    }

    // Allocate some blocks using worst fit
    requestSize = 150;
    int worstBlock = worstFit(freeList, n, requestSize);
    if (worstBlock != -1) {
        cout << "Allocated " << requestSize << " bytes using worst fit at position " << worstBlock << endl;
        freeList[worstBlock] -= requestSize;
    } else {
        cout << "Unable to allocate " << requestSize << " bytes using worst fit" << endl;
    }

    // Print the updated free list
    cout << "Updated free list: ";
    for (int i = 0; i < n; i++) {
        cout << freeList[i] << " ";
    }
    cout << endl;

    return 0;
}
