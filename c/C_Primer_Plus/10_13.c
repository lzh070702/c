#include <stdio.h>

double func1(double arr[],double average){
    for (int i = 0; i < 5; i++) {
        average += arr[i];
    }
    return average / 5;
}

double func2(double arr[3][5]) {
    int sum_average = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            sum_average += arr[i][j];
        }
    }
    return sum_average / 15;
}

double func3(double arr[3][5]) {
    int max = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            max = max > arr[i][j] ? max : arr[i][j];
        }
    }
    return max;
}

int main() {
    double arr[3][5];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%lf", &arr[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        double average = 0;
        average = func1(arr[i],average);
        printf("第 %d 行的平均数为：%lf\n", i + 1, average);
    }
    double sum_average = func2(arr);
    printf("所有数据的平均数为：%lf\n", sum_average);
    double max = func3(arr);
    printf("所有数据的最大值为：%lf\n", max);
    return 0;
}