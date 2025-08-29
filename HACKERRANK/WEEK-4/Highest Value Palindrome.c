#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* maxPal(char* str, int len, int changes) {
    int l = 0, r = len - 1;
    int *mod = calloc(len, sizeof(int));

    while (l < r && changes >= 0) {
        if (str[l] != str[r]) {
            if (str[l] > str[r]) str[r] = str[l];
            else str[l] = str[r];
            mod[l] = mod[r] = 1;
            changes--;
        }
        l++; r--;
    }
    if (changes < 0) { free(mod); return "-1"; }

    l = 0; r = len - 1;
    while (l <= r && changes > 0) {
        if (l == r && str[l] != '9') {
            str[l] = '9'; changes--;
        } else if (str[l] != '9') {
            if (mod[l] || mod[r]) {
                if (changes > 0) {
                    str[l] = str[r] = '9';
                    changes--;
                }
            } else if (changes > 1) {
                str[l] = str[r] = '9';
                changes -= 2;
            }
        }
        l++; r--;
    }
    free(mod);
    return str;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char *s = malloc(n + 1);
    scanf("%s", s);
    char *res = maxPal(s, n, k);
    printf("%s\n", res);
    if (strcmp(res, "-1") != 0) free(s);
    return 0;
}
