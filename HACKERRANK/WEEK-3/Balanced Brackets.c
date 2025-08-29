#include <stdio.h>
#include <string.h>
#define MAX 1000

int matches(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

const char* validate(char *expr) {
    char buffer[MAX];
    int ptr = 0;
    int len = strlen(expr);

    for (int i = 0; i < len; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            buffer[ptr++] = ch;
        } else {
            if (ptr == 0) return "NO";
            if (!matches(buffer[--ptr], ch)) return "NO";
        }
    }
    return (ptr == 0) ? "YES" : "NO";
}

int main() {
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        char expr[MAX];
        scanf("%s", expr);
        printf("%s\n", validate(expr));
    }
    return 0;
}
