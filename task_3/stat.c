#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        output(data, n);
        printf("\n");
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6f %.6f", max_v, min_v, mean_v, variance_v);
}
int max(int *a, int n) {
    int mx = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p > mx) {
            mx = *p;
        }
    }
    return mx;
}
int min(int *a, int n) {
    int mn = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p < mn) {
            mn = *p;
        }
    }
    return mn;
}

double mean(int *a, int n) {
    double sum = 0;
    for (int *p = a; p - a < n; p++) {
        sum += *p;
    }
    return sum / n;
}

double variance(int *a, int n) {
    double sum = 0, sum2 = 0;
    for (int *p = a; p - a < n; p++) {
        sum += *p;
        sum2 += (*p) * (*p);
    }
    return sum2 / n - (sum / n) * (sum / n);
}
