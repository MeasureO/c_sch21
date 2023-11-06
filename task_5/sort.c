#include <stdio.h>
#include <stdlib.h>

int input(int *a, int n, int *l);
void output(int *a, int n);
void sort(int *a, int n);
int inputNumber(int *n);

int main() {
    int n;
    int l = 0;
    /* if (input(data, &n)) {
        sort(data, n);
        output(data, n);
    } else
        printf("n/a"); */
    if (inputNumber(&n)) {
        int *data = (int *)malloc(n * sizeof(int));
        if (input(data, n, &l) && n == l) {
            sort(data, n);
            output(data, n);
        } else {
            printf("n/a");
        }
        free(data);
    } else
        printf("n/a");
    return 0;
}

/*int input(int *a) {
    char c;
    int flag = 1;
    int count = 0;
    for (int *p = a; p - a < N; p++) {
        int number_code = scanf("%d", p);
        if (number_code) count++;
        int char_code = scanf("%c", &c);
        if (!((number_code + char_code) == 2 && (c == ' ' || c == '\n'))) {
            flag = 0;
        }

        if (c == '\n' && count != N) {
            count++;
            flag = 0;
            break;
        }
        if (count == N && c != '\n') {
            flag = 0;
            break;
        }
    }
    return flag;
}
*/
int inputNumber(int *n) {
    int flag = 1;
    char c = '$';
    double d = 0.0;
    if (scanf("%lf%c", &d, &c) == 2 && (d - (int)d < 1e-12) && (c == ' ' || c == '\n')) {
        *n = (int)d;
    } else
        flag = 0;

    return flag;
}
int input(int *a, int n, int *l) {
    int flag = 1;
    double tmp = 0.0;
    *l = 0;
    char c = '$';
    for (int i = 0; i < n; i++) {
        int input_code = scanf("%lf", &tmp);
        if (input_code != 1 || !(tmp - (int)tmp < 1e-12)) {
            flag = 0;
            break;
        }
        a[i] = (int)tmp;
        *l += 1;
        if (*l == n) {
            flag = 0;
            break;
        }
        c = getchar();
        if (c == 0x0a) break;
    }
    return flag;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            printf("%d ", a[i]);
        else
            printf("%d", a[i]);
    }
}

void sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j + 1] < a[j]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}
