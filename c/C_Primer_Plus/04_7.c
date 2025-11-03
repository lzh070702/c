#include <float.h>
#include <stdio.h>

int main() {
    double num1 = 1.0 / 3.0;
    float num2 = 1.0f / 3.0f;
    printf("%.6f\n", num1);
    printf("%.6f\n", num2);
    printf("%.12f\n", num1);
    printf("%.12f\n", num2);
    printf("%.16f\n", num1);
    printf("%.16f\n", num2);
    printf("%d\n", DBL_DIG);
    printf("%d\n", FLT_DIG);
    return 0;
}