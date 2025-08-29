#include <stdio.h>

void findFlavors(int money, int prices[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (prices[i] + prices[j] == money) {
                printf("%d %d\n", i + 1, j + 1);
                return;
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int money, n;
        scanf("%d %d", &money, &n);
        int prices[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &prices[i]);
        }
        findFlavors(money, prices, n);
    }

    return 0;
}
