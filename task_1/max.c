#include<stdio.h>

int max(int x, int y);

int main() {
    int x, y;
    
    if (scanf("%d%d", &x, &y) == 2){
        if (getchar() == '\n') {
            printf("%d\n", max(x, y));   
        } else {
            printf("n/a\n");
        }
    } else {
        printf("n/a\n");
    }
}

int max(int a, int b){
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
