#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        squaring(data, n);
        output(data, n);
    } else
        printf("n/a");
    return 0;
}

int input(int *a, int *n) {
    char c;
    int flag = 1;
    if (scanf("%d%c", n, &c) == 2 && c == '\n' && *n > 0 && *n <= NMAX) {
        int count = 0;
        for (int *p = a; p - a < *n; p++) {
            int number_code = scanf("%d", p);
            if (number_code) count++;
            int char_code = scanf("%c", &c);
            if (!((number_code + char_code) == 2 && (c == ' ' || c == '\n'))) {
                flag = 0;
            }

            if (c == '\n' && count != *n) {
                count++;
                flag = 0;
                break;
            }
            if (count == *n && c != '\n') {
                flag = 0;
                break;
            }
        }
    } else {
        flag = 0;
    }
    return flag;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p - a != n - 1)
            printf("%d ", *p);
        else
            printf("%d", *p);
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p = (*p) * (*p);
    }
}
