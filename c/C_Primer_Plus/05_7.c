#include <stdio.h>

double func(double a) {
    return a * a * a;
}

int main() {
    double a;
    printf("请输入一个数字：");
    scanf("%lf", &a);
    printf("该数的立方值为：%lf\n", func(a));
    return 0;
}