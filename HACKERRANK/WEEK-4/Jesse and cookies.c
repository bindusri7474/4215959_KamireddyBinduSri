#include <stdio.h>
#include <stdlib.h>

void exchange(int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
}

void siftDown(int arr[], int len, int idx) {
    int m = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;

    if (l < len && arr[l] < arr[m])
        m = l;
    if (r < len && arr[r] < arr[m])
        m = r;

    if (m != idx) {
        exchange(&arr[idx], &arr[m]);
        siftDown(arr, len, m);
    }
}

void siftUp(int arr[], int pos) {
    int up = (pos - 1) / 2;
    if (pos > 0 && arr[pos] < arr[up]) {
        exchange(&arr[pos], &arr[up]);
        siftUp(arr, up);
    }
}

int removeTop(int arr[], int *sz) {
    if (*sz <= 0)
        return -1;
    int val = arr[0];
    arr[0] = arr[*sz - 1];
    (*sz)--;
    siftDown(arr, *sz, 0);
    return val;
}

void addHeap(int arr[], int *sz, int v) {
    arr[*sz] = v;
    (*sz)++;
    siftUp(arr, *sz - 1);
}

int combineMix(int bar, int B[], int len) {
    int store[len], count = 0;

    for (int i = 0; i < len; i++) {
        addHeap(store, &count, B[i]);
    }

    int steps = 0;
    while (count > 1 && store[0] < bar) {
        int u = removeTop(store, &count);
        int v = removeTop(store, &count);

        int formed = u + 2 * v;
        addHeap(store, &count, formed);
        steps++;
    }

    if (count > 0 && store[0] >= bar)
        return steps;
    else
        return -1;
}

int main() {
    int len, bar;
    scanf("%d %d", &len, &bar);

    int nums[len];
    for (int i = 0; i < len; i++) {
        scanf("%d", &nums[i]);
    }

    int output = combineMix(bar, nums, len);
    printf("%d\n", output);

    return 0;
}
