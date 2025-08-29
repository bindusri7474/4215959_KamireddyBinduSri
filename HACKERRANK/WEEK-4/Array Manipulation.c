#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10000010

long vals[LIMIT] = {0};

int main() {
    int size, ops;
    scanf("%d %d", &size, &ops);

    for (int x = 0; x < ops; x++) {
        int l, r;
        long v;
        scanf("%d %d %ld", &l, &r, &v);

        vals[l] += v;
        vals[r + 1] -= v;
    }

    long result = 0, sum = 0;
    for (int idx = 1; idx <= size; idx++) {
        sum += vals[idx];
        if (sum > result) result = sum;
    }

    printf("%ld\n", result);

    return 0;
}
