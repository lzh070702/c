#include <stdio.h>

int main() {
    int num = 5, week = 0;
    while (num <= 150) {
        week++;
        num -= week;
        num *= 2;
        printf("第 %d 周朋友的数量：%d\n", week, num);
    }
    return 0;
}