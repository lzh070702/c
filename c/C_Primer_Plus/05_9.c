#include <stdio.h>

void Temperatures(double F) {
    const double c1 = 5.0 / 9.0, c2 = -32.0, c3 = 273.16;
    double C = c1 * (F + c2);
    double K = C + c3;
    printf("其相对应的摄氏温度：%.2lf\n", C);
    printf("其相对应的开氏温度：%.2lf\n", K);
}

int main() {
    double F;
    printf("请输入一个华氏温度：");
    while (scanf("%lf", &F) == 1) {
        Temperatures(F);
    }
    return 0;
}