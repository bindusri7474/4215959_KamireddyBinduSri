#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *items;
    int s, e;
} Queue;

Queue* newQueue(int sz) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->items = (int*)malloc(sz * sizeof(int));
    q->s = 0;
    q->e = -1;
    return q;
}

void qPush(Queue* q, int v) {
    q->e++;
    q->items[q->e] = v;
}

void qPop(Queue* q) {
    q->s++;
}

void qPopLast(Queue* q) {
    q->e--;
}

int qFirst(Queue* q) {
    return q->items[q->s];
}

int qLast(Queue* q) {
    return q->items[q->e];
}

int qEmpty(Queue* q) {
    return q->s > q->e;
}

void maxWin(int vals[], int len, int win, int out[]) {
    Queue* q = newQueue(len);
    int curr = 0;

    for (int p = 0; p < len; p++) {
        if (!qEmpty(q) && qFirst(q) < p - win + 1) qPop(q);
        while (!qEmpty(q) && vals[qLast(q)] < vals[p]) qPopLast(q);
        qPush(q, p);
        if (p >= win - 1) out[curr++] = vals[qFirst(q)];
    }
    free(q->items);
    free(q);
}

void process(int vals[], int len, int requests[], int rqcount) {
    for (int h = 0; h < rqcount; h++) {
        int win = requests[h];
        int times = len - win + 1;
        int *mx = (int*)malloc(times * sizeof(int));
        maxWin(vals, len, win, mx);

        int mn = mx[0];
        for (int a = 1; a < times; a++)
            if (mx[a] < mn) mn = mx[a];

        printf("%d\n", mn);
        free(mx);
    }
}

int main() {
    int len, rqcount;
    scanf("%d %d", &len, &rqcount);

    int *vals = (int*)malloc(len * sizeof(int));
    for (int p = 0; p < len; p++) scanf("%d", &vals[p]);

    int *requests = (int*)malloc(rqcount * sizeof(int));
    for (int h = 0; h < rqcount; h++) scanf("%d", &requests[h]);

    process(vals, len, requests, rqcount);

    free(vals);
    free(requests);
    return 0;
}
