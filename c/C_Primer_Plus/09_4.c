#include <stdio.h>

double harmonic_mean(double x, double y) {
    return 1 / ((1 / x + 1 / y) / 2);
}

int main() {
    double x, y;
    scanf("%lf %lf",&x,&y);
    printf("%lf",harmonic_mean(x,y));
    return 0;
}