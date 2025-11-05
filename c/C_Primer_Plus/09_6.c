#include <stdio.h>

void sort(double* x, double* y, double* z) {
    if (*x > *y) {
        *x = *x + *y;
        *y = *x - *y;
        *x = *x - *y;
    }
    if (*x > *z) {
        *x = *x + *z;
        *z = *x - *z;
        *x = *x - *z;
    }
    if (*y > *z) {
        *y = *y + *z;
        *z = *y - *z;
        *y = *y - *z;
    }
}

int main() {
    double x, y, z;
    scanf("%lf %lf %lf",&x,&y,&z);
    sort(&x, &y, &z);
    printf("%lf %lf %lf",x,y,z);
    return 0;
}