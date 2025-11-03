#include <stdio.h>

int main() {
    double simple_interest = 0.10, compound_interest = 0.05;
    double sum1 = 100, sum2 = 100;
    int year = 0;
    while (sum2 <= sum1) {
        sum1 += simple_interest * 100;
        sum2 *= (1 + compound_interest);
        year++;
    }
    printf("年份：%d\n", year);
    printf("单利：%lf\n", sum1);
    printf("复利：%lf\n", sum2);
    return 0;
}