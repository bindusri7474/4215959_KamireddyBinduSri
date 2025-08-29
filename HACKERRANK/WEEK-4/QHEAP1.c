#include <stdio.h>
#include <stdlib.h>

int minHeap[100000], heapCount = 0;

void swapElements(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int idx) {
    while (idx > 0 && minHeap[(idx - 1) / 2] > minHeap[idx]) {
        swapElements(&minHeap[idx], &minHeap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

void heapifyDown(int idx) {
    int leftChild = 2 * idx + 1;
    int rightChild = 2 * idx + 2;
    int smallest = idx;

    if (leftChild < heapCount && minHeap[leftChild] < minHeap[smallest])
        smallest = leftChild;

    if (rightChild < heapCount && minHeap[rightChild] < minHeap[smallest])
        smallest = rightChild;

    if (smallest != idx) {
        swapElements(&minHeap[idx], &minHeap[smallest]);
        heapifyDown(smallest);
    }
}

void addElement(int val) {
    minHeap[heapCount] = val;
    heapifyUp(heapCount++);
}

void removeElement(int val) {
    for (int i = 0; i < heapCount; i++) {
        if (minHeap[i] == val) {
            minHeap[i] = minHeap[--heapCount];
            heapifyDown(i);
            heapifyUp(i);
            break;
        }
    }
}

int getMin() {
    if (heapCount == 0) return -1; // or appropriate error value
    return minHeap[0];
}

int main() {
    int queries, type, value;
    scanf("%d", &queries);
    while (queries--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &value);
            addElement(value);
        } else if (type == 2) {
            scanf("%d", &value);
            removeElement(value);
        } else if (type == 3) {
            printf("%d\n", getMin());
        }
    }
    return 0;
}
