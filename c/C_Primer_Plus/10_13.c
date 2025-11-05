#include <stdio.h>

int main() {
    double arr[3][5];
    for (int i = 0;i < 3;i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%lf",&arr[i][j]);
        }
    }
    double sum_average = 0;
    for (int i = 0; i < 3; i++) {
        double average = 0;
        for (int j = 0; j < 5; j++) {
            average += arr[i][j];
        }
        average /= 5;
        printf("第 %d 行的平均数为：%lf\n", i + 1, average);
        sum_average += average;
    }
    sum_average /= 3;
    printf("所有数据的平均数为：%lf\n",sum_average);
    double max = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            max = max > arr[i][j] ? max : arr[i][j];
        }
    }
    printf("所有数据的最大值为：%lf\n", max);
    return 0;
}