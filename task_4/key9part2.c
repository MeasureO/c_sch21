#include <stdio.h>

#define LEN 100

int sum(int *buff1, int *buff2, int *result);
void sub(int *buff1, int *buff2, int *result);
int input(int *a, int *l);
void output(int *a, int n);
void shift(int *a, int l);
void zero(int *a);
int diff_check(int *a);
void final_output(int *a);

int main() {
    int a[LEN];
    int b[LEN];
    int res1[LEN + 1], res2[LEN + 1];
    int l1 = 0, l2 = 0;
    zero(a);
    zero(b);
    zero(res1);
    zero(res2);
    if (input(a, &l1) && input(b, &l2)) {
        shift(a, l1);
        shift(b, l2);
        // output(a, LEN);
        // printf("\n");
        // output(b, LEN);
        // printf("\n");
        int code = sum(a, b, res1);
        sub(a, b, res2);
        // output(res1, LEN + 1);
        // printf("\n");
        // output(res2, LEN + 1);
        // printf("\n");
        if (code == 0)
            printf("n/a");
        else {
            // output(res1, LEN);
            final_output(res1);
            printf("\n");
            // output(res2, LEN);
            final_output(res2);
            printf("\n");
        }
    } else
        printf("n/a");
}

int input(int *a, int *l) {
    int flag = 1;
    double tmp = 0.0;
    *l = 0;
    char c = '$';
    for (int i = 0; i < LEN; i++) {
        int input_code = scanf("%lf", &tmp);
        if (input_code != 1 || !(tmp - (int)tmp < 1e-12) || (int)tmp > 9 || (int)tmp < 0) {
            flag = 0;
            break;
        }
        a[i] = (int)tmp;
        *l += 1;
        c = getchar();
        if (c == 0x0a) break;
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

void final_output(int *a) {
    for (int i = 0; i <= LEN; i++) {
        if (a[i] != 0) {
            printf("%d ", a[i]);
        }
    }
}

void shift(int *a, int l) {
    for (int i = l - 1; i >= 0; i--) {
        a[i + (LEN - l)] = a[i];
    }
    for (int i = 0; i < l; i++) {
        a[i] = 0;
    }
}

void zero(int *a) {
    for (int i = 0; i <= LEN; i++) {
        a[i] = 0;
    }
}

int sum(int *buff1, int *buff2, int *result) {
    int dob = 0;
    int flag = 1;
    for (int i = LEN; i >= 0; i--) {
        result[i] += (buff1[i] + buff2[i]) % 10;
        dob = (buff1[i] + buff2[i]) / 10;
        result[i - 1] += dob;
        if (i == 1 && dob > 0) flag = 0;
    }
    return flag;

    //*result_length++;
    // if (dob > 0) {
    //     *result_length++;
    // }
}

void sub(int *buff1, int *buff2, int *result) {
    for (int i = LEN; i >= 0; i--) {
        if (buff1[i] - buff2[i] >= 0) {
            result[i] += buff1[i] - buff2[i];
        } else {
            result[i] += buff1[i] - buff2[i] + 10;
            buff1[i - 1] -= 1;
        }
    }
}

int diff_check(int *a) {
    int flag = 1;
    for (int i = 0; i <= LEN; i++) {
        if (a[i] < 0) flag = 0;
    }
    return flag;
}
