#include <stdio.h>
#include <stdlib.h>

int compareInt(const void *p, const void *q) {
    return (*(int*)p - *(int*)q);
}

int placeTransmitters(int arr[], int sz, int dist) {
    qsort(arr, sz, sizeof(int), compareInt);

    int counter = 0, y = 0;
    while (y < sz) {
        int start = y;
        while (start + 1 < sz && arr[start + 1] - arr[y] <= dist) start++;
        counter++;
        int place = start;
        while (place + 1 < sz && arr[place + 1] - arr[start] <= dist) place++;
        y = place + 1;
    }
    return counter;
}

int main() {
    int sz, dist;
    scanf("%d %d", &sz, &dist);
    int arr[sz];
    for (int j = 0; j < sz; j++) scanf("%d", &arr[j]);

    printf("%d\n", placeTransmitters(arr, sz, dist));
    return 0;
}
