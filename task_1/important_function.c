#include<stdio.h>
#include<math.h>

float important_function(float x){
    return 7e-3 * pow(x, 3) + ((22.8 * pow(x, 1 / 3) - 1e3) * x + 3) / (x * x / 2) - x * pow (10 + x, 2 / x) - 1.01;
}

int main(){
    float x;
    if (scanf("%f", &x) == 1) {
        if (getchar() == '\n') {
            printf("%.1f\n", important_function(x));
        } else {
            printf("n/a\n");
        }
    } else {
        printf("n/a\n");
    }
}
