#include <stdio.h>

double min(double x, double y) {
    return x < y ? x : y;
}

int main() {
    double x, y;
    scanf("%lf %lf", &x, &y);
    printf("%lf", min(x, y));
    return 0;
}