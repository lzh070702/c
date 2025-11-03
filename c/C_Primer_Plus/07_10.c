#include <stdio.h>

int main() {
    double money[5] = {0, 17850, 23900, 29750, 14875};
    while (1) {
        int type = 0;
        printf("0.退出\n1.单身\n2.户主\n3.已婚，公用\n4.已婚，离异\n请确认身份：");
        scanf("%d", &type);
        if (type < 1 || type > 5) {
            return 0;
        }
        double tax = 0;
        printf("请输入您的金额：");
        scanf("%lf", &tax);
        if (tax <= money[type]) {
            tax *= 0.15;
        }
        else{
            tax = (tax - money[type]) * 0.28 + money[type] * 0.15;
        }
        printf("需要缴纳的税金：%lf",tax);
    }
    return 0;
}