#include <stdio.h>

int fib(int n);

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n >= 0) {
        if (getchar() == '\n') {
            printf("%d\n", fib(n));
        } else {
            printf("n/a\n");
        }
    } else {
        printf("n/a\n");
    }
}

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}
