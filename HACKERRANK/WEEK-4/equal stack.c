#include <stdio.h>

int main() {
    int lenA, lenB, lenC;
    scanf("%d %d %d", &lenA, &lenB, &lenC);

    int stackA[lenA], stackB[lenB], stackC[lenC];

    for (int idx = 0; idx < lenA; idx++) {
        scanf("%d", &stackA[idx]);
    }
    for (int idx = 0; idx < lenB; idx++) {
        scanf("%d", &stackB[idx]);
    }
    for (int idx = 0; idx < lenC; idx++) {
        scanf("%d", &stackC[idx]);
    }

    int sumA = 0, sumB = 0, sumC = 0;
    for (int idx = 0; idx < lenA; idx++) sumA += stackA[idx];
    for (int idx = 0; idx < lenB; idx++) sumB += stackB[idx];
    for (int idx = 0; idx < lenC; idx++) sumC += stackC[idx];

    int startA = 0, startB = 0, startC = 0;

    while (1) {
        if (sumA == sumB && sumB == sumC) break;
        if (sumA >= sumB && sumA >= sumC) {
            sumA -= stackA[startA++];
        } else if (sumB >= sumA && sumB >= sumC) {
            sumB -= stackB[startB++];
        } else {
            sumC -= stackC[startC++];
        }
    }

    printf("%d\n", sumA);
    return 0;
}
