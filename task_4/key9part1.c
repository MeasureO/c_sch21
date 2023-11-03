/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

// i have changed type void -> int
// void input (int *buffer, int *length);
int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);
int even_exists_check(int *buffer, int length);
/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n;
    int data[NMAX];
    int numbers[NMAX];
    if (input(data, &n) && even_exists_check(data, n)) {
        int sum = sum_numbers(data, n);
        int len = find_numbers(data, n, sum, numbers);
        printf("%d\n", sum);
        output(numbers, len);
    } else
        printf("n/a");

    return 0;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int even_exists_check(int *buffer, int length) {
    int flag = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            flag = 1;
        }
    }

    return flag;
}
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }

    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int count = 0;
    for (int *p = buffer; p - buffer < length; p++) {
        if (*p != 0 && number % *p == 0) {
            *numbers = *p;
            numbers++;
            count++;
        }
    }
    return count;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p - a != n - 1)
            printf("%d ", *p);
        else
            printf("%d", *p);
    }
}

/*
int input(int *a, int *l) {
    int flag = 1;
    double tmp = 0.0;
    char c = '$';
    if (!(scanf("%f", &tmp) == 1 && (tmp - (int)tmp) < 1e-12 && tmp > 0 && tmp <= NMAX)) {
        flag = 0;
    }
    for (int i = 0; i < NMAX; i++) {
        int input_code = scanf("%lf", &tmp);
        if (input_code != 1 || !(tmp - (int)tmp < 1e-12)) {
            flag = 0;
            break;
        }
        a[i] = (int)tmp;
        *l += 1;
        if (*l == NMAX) {
            flag = 0;
            break;
        }
        c = getchar();
        if (c == 0x0a) break;
    }
    return flag;
}
*/

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
