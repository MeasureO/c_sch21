#include <stdio.h>
#include <stdlib.h>

int inputNumber(int *cmd);
int inputMatrixSize(int *m, int *n);
int inputMatrix(int m, int n, int **a);
void outputMatrix(int m, int n, int **a);
void sum(int m_first, int n_first, int **matrix_first, int **matrix_second, int **matrix_result);
void transpose(int m, int n, int **matrix, int **result);
void mul(int m_first, int n_first, int **matrix_first, int n_second, int **matrix_second,
         int **matrix_result);

int main() {
    int cmd;
    int m, n;
    int k, l;
    if (inputNumber(&cmd) && inputMatrixSize(&m, &n)) {
        if (cmd == 1) {
            int **data = malloc(m * n * sizeof(int) + m * sizeof(int *));
            int *p = (int *)(data + m);
            for (int i = 0; i < m; i++) data[i] = p + n * i;

            if (inputMatrix(m, n, data) && inputMatrixSize(&k, &l) && m == k && k == l) {
                int **data2 = malloc(m * sizeof(int *));
                for (int i = 0; i < m; i++) data2[i] = malloc(n * sizeof(int));

                if (inputMatrix(k, l, data2)) {
                    int **result = malloc(m * n * sizeof(int) + m * sizeof(int *));
                    int *p3 = (int *)(result + m);
                    for (int i = 0; i < m; i++) result[i] = p3 + n * i;
                    sum(m, n, data, data2, result);
                    outputMatrix(m, n, result);
                    free(result);
                } else
                    printf("n/a");
                free(data);
                for (int i = 0; i < m; i++) free(data2[i]);
                free(data2);
            } else
                printf("n/a");
        } else if (cmd == 2) {
            int **data = malloc(m * n * sizeof(int) + m * sizeof(int *));
            int *p = (int *)(data + m);
            for (int i = 0; i < m; i++) data[i] = p + n * i;

            if (inputMatrix(m, n, data) && inputMatrixSize(&k, &l) && n == k) {
                int **data2 = malloc(k * sizeof(int *));
                for (int i = 0; i < k; i++) data2[i] = malloc(l * sizeof(int));

                if (inputMatrix(k, l, data2)) {
                    int **result = malloc(m * l * sizeof(int) + m * sizeof(int *));
                    int *p3 = (int *)(result + m);
                    for (int i = 0; i < m; i++) result[i] = p3 + l * i;

                    mul(m, n, data, l, data2, result);
                    outputMatrix(m, l, result);
                    for (int i = 0; i < m; i++) free(result[i]);
                    free(result);
                } else
                    printf("n/a");
                for (int i = 0; i < m; i++) free(data2[i]);
                free(data2);
            } else
                printf("n/a");
            free(data);
        } else if (cmd == 3) {
            int **data = malloc(m * n * sizeof(int) + m * sizeof(int *));
            int *p = (int *)(data + m);
            for (int i = 0; i < m; i++) data[i] = p + n * i;
            if (inputMatrix(m, n, data)) {
                int **result = malloc(n * sizeof(int *));
                for (int i = 0; i < n; i++) result[i] = malloc(m * sizeof(int));
                transpose(m, n, data, result);
                outputMatrix(n, m, result);
                for (int i = 0; i < m; i++) free(result[i]);
                free(result);
            } else
                printf("n/a");
            free(data);
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
    if (*n < 0 || *n > 3) flag = 0;
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

int inputMatrix(int m, int n, int **a) {
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

void outputMatrix(int m, int n, int **a) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j != n - 1)
                printf("%d ", a[i][j]);
            else
                printf("%d", a[i][j]);
        }
        if (i != m - 1) printf("\n");
    }
}

void sum(int m_first, int n_first, int **matrix_first, int **matrix_second, int **matrix_result) {
    for (int i = 0; i < m_first; i++) {
        for (int j = 0; j < n_first; j++) {
            matrix_result[i][j] = matrix_first[i][j] + matrix_second[i][j];
        }
    }
}

void transpose(int m, int n, int **a, int **result) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = a[j][i];
        }
    }
}

void mul(int m, int n, int **matrix_first, int l, int **matrix_second, int **matrix_result) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            matrix_result[i][j] = 0;
            for (int t = 0; t < n; t++) {
                matrix_result[i][j] += matrix_first[i][t] * matrix_second[t][j];
            }
        }
    }
}