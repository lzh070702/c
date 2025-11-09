#include <stdio.h>

#define harmonic_mean(x,y) 1 / ((1 / x + 1 / y) / 2)

int main() {
    double x, y;
    scanf("%lf %lf", &x, &y);
    printf("%lf\n", harmonic_mean(x, y));
    return 0;
}