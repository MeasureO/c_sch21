#include <math.h>
#include <stdio.h>

int largest_prime_divisor(int n);
int is_prime(int n);
int div(int n, int k);
int mod(int n, int k);

int main() {
    int a;
    if (scanf("%d", &a) == 1 && getchar() == '\n') {
        if (a != 0) {
            printf("%d", largest_prime_divisor(a));
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    // printf("is prime: %d\n", is_prime(a));
    // printf("lpd: %d\n", largest_prime_divisor(a));
    // printf("div 3: %d\n", div(a, 3));
    // printf("mod 3: %d\n", mod(a, 3));
}

int is_prime(int n) {
    if (n == 1) {
        return 0;
    } else {
        for (int i = 2; i <= floor(sqrt(n)); i++) {
            if (mod(n, i) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int largest_prime_divisor(int n) {
    if (n < 0) {
        n *= -1;
    }
    for (int i = n; i > 0; i--) {
        if (mod(n, i) == 0 && is_prime(i) == 1) {
            return i;
        }
    }
    return 0;
}

int div(int n, int k) {
    int count = 0;
    while (n >= k) {
        n -= k;
        count += 1;
    }
    return count;
}

int mod(int n, int k) {
    while (n >= 0) {
        n -= k;
    }
    n += k;
    return n;
}
