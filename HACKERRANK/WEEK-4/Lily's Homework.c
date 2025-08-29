#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int pos;
} Elem;

int cmpInc(const void *a, const void *b) {
    return ((Elem*)a)->val - ((Elem*)b)->val;
}

int cmpDec(const void *a, const void *b) {
    return ((Elem*)b)->val - ((Elem*)a)->val;
}

int countCycles(int *arr, int n, int ascending) {
    Elem *e = malloc(n * sizeof(Elem));
    for (int i = 0; i < n; i++) {
        e[i].val = arr[i];
        e[i].pos = i;
    }
    qsort(e, n, sizeof(Elem), ascending ? cmpInc : cmpDec);

    char *used = calloc(n, 1);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (used[i] || e[i].pos == i) continue;
        int size = 0, j = i;
        while (!used[j]) {
            used[j] = 1;
            j = e[j].pos;
            size++;
        }
        res += size > 1 ? size - 1 : 0;
    }
    free(e); free(used);
    return res;
}

int minSwapsToSort(int *arr, int n) {
    int a = countCycles(arr, n, 1);
    int b = countCycles(arr, n, 0);
    return a < b ? a : b;
}

int main() {
    int n; scanf("%d", &n);
    int *v = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    printf("%d\n", minSwapsToSort(v, n));
    free(v);
    return 0;
}
