#include <math.h>
#include <stdio.h>
#define PI 3.14159265358979323846

double f1(double x);
double f2(double x);
double f3(double x);
// void graph_f1(double x);
// void graph_f2(double x);
// void graph_f3(double x);
void graph(double max, double (*f)(double));

int main() {
    double x = -PI;
    double max_f1 = 0, max_f2 = 0, max_f3 = 0;
    for (int i = 0; i < 42; i++) {
        if (sqrt(1.0 + 4.0 * x * x) - x * x - 1.0 > 0) {
            printf("%.7f | %.7f | %.7f | %.7f\n", x, f1(x), f2(x), f3(x));
        } else {
            printf("%.7f | %.7f | - | %.7f\n", x, f1(x), f3(x));
        }
        x += 2 * PI / 41;
        if (f1(x) > max_f1) max_f1 = f1(x);
        if (f2(x) > max_f2) max_f2 = f2(x);
        if (f3(x) > max_f3) max_f3 = f3(x);
    }
    graph(max_f1, f1);
    graph(max_f2, f2);
    graph(max_f3, f3);
}

double f1(double x) { return 1.0 / (1.0 + x * x); }

double f2(double x) {
    if (sqrt(1.0 + 4.0 * x * x) - x * x - 1.0 > 0) {
        return sqrt(sqrt(1.0 + 4.0 * x * x) - x * x - 1.0);
    } else {
        return -42.0;
    }
}

double f3(double x) { return 1.0 / (x * x); }

void graph(double max, double (*f)(double)) {
    // printf("%f\n", max);
    double x = -PI;
    double y = max;
    for (int j = 0; j < 22; j++) {
        if (j != 21) {
            for (int i = 0; i < 43; i++) {
                // printf("(%.1f, %.1f)", x, y);
                if (i == 21)
                    printf("|");
                else if (fabs(f(x) + 42) < 1e-3)
                    printf(" ");
                else if (fabs(f(x) - y) <= max / 30)
                    printf("*");
                else
                    printf(" ");
                if (i != 21) x += 2 * PI / 41;
            }
            x = -PI;
            // printf("` y:  %f  max / 40: %f \n", y, max / 40);
            printf("\n");
            y -= max / 20;
        } else {
            for (int i = 0; i < 43; i++) printf("-");
        }
    }
    printf("\n");
}
