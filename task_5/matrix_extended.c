#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

int inputNumber(int *cmd);
int inputMatrixSize(int *m, int *n);
int inputMatrix1(int m, int n, int a[][n]);
void outputMatrix1(int m, int n, int a[][n]);
int inputMatrix2(int m, int n, int **a);
void outputMatrix2(int m, int n, int **a);
void findMaxRows2(int m, int n, int **a, int *res);
void findMinCols2(int m, int n, int **a, int *res);
void findMaxRows1(int m, int n, int a[][n], int *res);
void findMinCols1(int m, int n, int a[][n], int *res);
void output(int n, int *a);

int main() {
    int cmd;
    int m, n;
    if (inputNumber(&cmd) && inputMatrixSize(&m, &n)) {
        if (cmd == 1 && m <= NMAX && n <= NMAX) {
            int data[m][n];
            if (inputMatrix1(m, n, data)) {
                outputMatrix1(m, n, data);
                int res1[m], res2[n];
                findMaxRows1(m, n, data, res1);
                findMinCols1(m, n, data, res2);
                output(m, res1);
                printf("\n");
                output(n, res2);
            } else
                printf("n/a");
        } else if (cmd == 2) {
            int **data = malloc(m * n * sizeof(int) + m * sizeof(int *));
            int *p = (int *)(data + m);
            for (int i = 0; i < m; i++) data[i] = p + n * i;
            if (inputMatrix2(m, n, data)) {
                outputMatrix2(m, n, data);
                int *res1 = malloc(m * sizeof(int));
                int *res2 = malloc(n * sizeof(int));
                findMaxRows2(m, n, data, res1);
                findMinCols2(m, n, data, res2);
                output(m, res1);
                printf("\n");
                output(n, res2);
            } else
                printf("n/a");
            free(data);
        } else if (cmd == 3) {
            int **data = malloc(m * sizeof(int *));
            for (int i = 0; i < m; i++) data[i] = malloc(n * sizeof(int));
            if (inputMatrix2(m, n, data)) {
                outputMatrix2(m, n, data);
                int *res1 = malloc(m * sizeof(int));
                int *res2 = malloc(n * sizeof(int));
                findMaxRows2(m, n, data, res1);
                findMinCols2(m, n, data, res2);
                output(m, res1);
                printf("\n");
                output(n, res2);
            } else
                printf("n/a");
            for (int i = 0; i < m; i++) free(data[i]);
            free(data);
        } else if (cmd == 4) {
            int **data = malloc(m * sizeof(int *));
            int *p = malloc(m * n * sizeof(int));
            for (int i = 0; i < m; i++) data[i] = p + n * i;
            if (inputMatrix2(m, n, data)) {
                outputMatrix2(m, n, data);
                int *res1 = malloc(m * sizeof(int));
                int *res2 = malloc(n * sizeof(int));
                findMaxRows2(m, n, data, res1);
                findMinCols2(m, n, data, res2);
                output(m, res1);
                printf("\n");
                output(n, res2);
            } else
                printf("n/a");
            free(data);
            free(p);
        } else
            printf("n/a");
    } else
        printf("n/a");

    return 0;
}

int inputNumber(int *n) {
    int flag = 1;
    char c = '$';
    double d = 0.0;
    if (scanf("%lf%c", &d, &c) == 2 && (d - (int)d < 1e-20) && (c == ' ' || c == '\n')) {
        *n = (int)d;
    } else
        flag = 0;
    if (*n < 0 || *n > 4) flag = 0;
    return flag;
}

int inputMatrixSize(int *m, int *n) {
    int flag = 1;
    char c = '$';
    double x = 0.0, y = 0.0;
    if (scanf("%lf%lf%c", &x, &y, &c) == 3 && (x - (int)x < 1e-20) && (y - (int)y < 1e-20) &&
        (c == ' ' || c == '\n')) {
        *m = x;
        *n = y;
    } else
        flag = 0;

    if (*m < 0 || *n < 0) flag = 0;

    return flag;
}

int inputMatrix1(int m, int n, int a[][n]) {
    int flag = 1;
    int code = -1;
    double d = 0.0;
    char c = '$';
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            code = scanf("%lf%c", &d, &c);
            if (code == 2 && (d - (int)d < 1e-18) && (c == ' ' || c == '\n')) {
                a[i][j] = (int)d;
            } else {
                flag = 0;
                break;
            }
        }
        if (flag == 0) break;
    }
    return flag;
}

void outputMatrix1(int m, int n, int a[][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            if (j != n - 1)
                printf("%d ", a[i][j]);
            else
                printf("%d ", a[i][j]);
        if (i != m - 1) printf("\n");
    }
}

int inputMatrix2(int m, int n, int **a) {
    int flag = 1;
    int code = -1;
    double d = 0.0;
    char c = '$';
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            code = scanf("%lf%c", &d, &c);
            if (code == 2 && (d - (int)d < 1e-18) && (c == ' ' || c == '\n')) {
                a[i][j] = (int)d;
            } else {
                flag = 0;
                break;
            }
        }
        if (flag == 0) break;
    }
    return flag;
}

void outputMatrix2(int m, int n, int **a) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            if (j != n - 1)
                printf("%d ", a[i][j]);
            else
                printf("%d ", a[i][j]);
        if (i != m - 1) printf("\n");
    }
}

void findMaxRows2(int m, int n, int **a, int *res) {
    for (int i = 0; i < m; i++) {
        int mx = a[i][0];
        for (int j = 0; j < n; j++) {
            if (a[i][j] > mx) mx = a[i][j];
        }
        res[i] = mx;
    }
}

void findMinCols2(int m, int n, int **a, int *res) {
    for (int j = 0; j < m; j++) {
        int mn = a[0][j];
        for (int i = 0; i < n; i++) {
            if (a[i][j] < mn) mn = a[i][j];
        }
        res[j] = mn;
    }
}

void findMaxRows1(int m, int n, int a[][n], int *res) {
    for (int i = 0; i < m; i++) {
        int mx = a[i][0];
        for (int j = 0; j < n; j++) {
            if (a[i][j] > mx) mx = a[i][j];
        }
        res[i] = mx;
    }
}

void findMinCols1(int m, int n, int a[][n], int *res) {
    for (int j = 0; j < m; j++) {
        int mn = a[0][j];
        for (int i = 0; i < n; i++) {
            if (a[i][j] < mn) mn = a[i][j];
        }
        res[j] = mn;
    }
}

void output(int n, int *a) {
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            printf("%d ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
}