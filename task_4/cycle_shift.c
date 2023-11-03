#include <stdio.h>
#define NMAX 10

int input(int *data, int *n, int *c);
void output(int *data, int n);
int cyclic_shift(int *data, int n, int shift);

int main() {
    int data[NMAX];
    int n;
    int shift;
    if (input(data, &n, &shift)) {
        cyclic_shift(data, n, shift);
        output(data, n);
    } else
        printf("n/a");
}

int input(int *a, int *n, int *shift) {
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
        c = '#';
        if (flag != 0) {
            if (scanf("%d%c", shift, &c) != 2 || c != '\n') {
                flag = 0;
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

int cyclic_shift(int *a, int n, int shift) {
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = 0;
    }
    if (shift < 0) {
        shift = shift % n - 1;
    } else if (shift > 0) {
        shift = shift % n;
    }
    for (int i = shift; i < n; i++) {
        temp[i - shift] = a[i];
    }
    // output(temp, n);
    // printf("\n");

    for (int i = 0; i < shift; i++) {
        temp[n - shift + i] = a[i];
    }
    // output(temp, n);
    // printf("\n");

    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }

    return 1;
}
