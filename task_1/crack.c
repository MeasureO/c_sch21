#include<stdio.h>

int main() {
    float x, y;
    if (scanf("%f%f", &x, &y) == 2) {
        if (getchar() == '\n') {
            if (x * x + y * y < 25) {
                printf("GOTCHA\n");
            } else {
                printf("MISS\n");
            }
        } else {
            printf("n/a\n");
        }
    } else {
        printf("n/a\n");
    }
}
