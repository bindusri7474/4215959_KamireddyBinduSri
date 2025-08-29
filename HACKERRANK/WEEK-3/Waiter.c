#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100000

int is_prime(int x) {
    if (x < 2) return 0;
    if (x % 2 == 0 && x != 2) return 0;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void prime_list(int arr[], int limit) {
    int num = 2, found = 0;
    while (found < limit) {
        if (is_prime(num)) {
            arr[found++] = num;
        }
        num++;
    }
}

int main() {
    int size, rounds;
    scanf("%d %d", &size, &rounds);

    int stack[MAX], primes[rounds];
    for (int i = 0; i < size; i++) {
        scanf("%d", &stack[i]);
    }

    prime_list(primes, rounds);

    for (int r = 0; r < rounds; r++) {
        int divisible[MAX], remain[MAX];
        int d_top = 0, r_top = 0;
        int prime = primes[r];

        for (int i = size - 1; i >= 0; i--) {
            if (stack[i] % prime == 0) {
                divisible[d_top++] = stack[i];
            } else {
                remain[r_top++] = stack[i];
            }
        }

        for (int i = d_top - 1; i >= 0; i--) {
            printf("%d\n", divisible[i]);
        }

        size = r_top;
        for (int i = 0; i < size; i++) {
            stack[i] = remain[i];
        }
    }

    for (int i = size - 1; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }

    return 0;
}
