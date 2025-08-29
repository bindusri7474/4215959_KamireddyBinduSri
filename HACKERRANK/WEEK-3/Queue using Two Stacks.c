#include <stdio.h>

int stackA[100000], stackB[100000];
int topA = -1, topB = -1;

void pushA(int val) {
    stackA[++topA] = val;
}

void transferIfNeeded() {
    if (topB == -1) {
        while (topA != -1) {
            stackB[++topB] = stackA[topA--];
        }
    }
}

void dequeue() {
    transferIfNeeded();
    if (topB != -1) {
        topB--;
    }
}

void front() {
    transferIfNeeded();
    if (topB != -1) {
        printf("%d\n", stackB[topB]);
    }
}

int main() {
    int queries, op, value;
    scanf("%d", &queries);

    while (queries--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &value);
            pushA(value);
        } else if (op == 2) {
            dequeue();
        } else if (op == 3) {
            front();
        }
    }

    return 0;
}
