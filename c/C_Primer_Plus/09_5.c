#include <stdio.h>

void larger_of(double* x, double* y) {
    *x = *y = *x > *y ? *x : *y;
}

int main() {
    double x, y;
    scanf("%lf %lf", &x, &y);
    larger_of(&x, &y);
    printf("%lf %lf", x, y);
    return 0;
}