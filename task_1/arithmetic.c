#include <stdio.h>


int sum(int a, int b);
int difference(int a, int b);
int product(int a, int b);
int quotient(int a, int b);

int main()
{
    int x, y;
    if (scanf("%d%d", &x, &y) == 2) {
        if (getchar() == '\n') {    
            if (y != 0) {
                printf("%d %d %d %d\n", sum(x, y), difference(x, y), product(x, y), quotient(x, y));
            } else {
                printf("%d %d %d n/a\n", sum(x, y), difference(x, y), product(x, y));
            } 
        } else {
            printf("n/a\n");
        }
    } else {
        printf("n/a\n");
    }
    return 0;
} 

int sum(int a, int b){
    return a + b;
}

int difference(int a, int b){
    return a - b;
}

int product(int a, int b){
    return a * b;
}

int quotient(int a, int b){
    return a / b;
}


