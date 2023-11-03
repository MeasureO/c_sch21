#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *data, int *n);
int search(int *data, int n);
double mean(int *data, int n);
double variance(int *data, int n);
void output(int *data, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n))
        printf("%d", search(data, n));
    else
        printf("n/a");
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

int search(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if ((*p != 0) && (*p % 2 == 0) && (*p >= mean(a, n)) &&
            (fabs(*p - mean(a, n)) <= 3 * sqrt(variance(a, n)))) {
            return *p;
        }
    }
    return 0;
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

/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
