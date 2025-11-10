#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func(int* arr, int size, int n) {
    srand((unsigned int)time(NULL));
    printf("选取结果：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[rand() % size]);
    }
    printf("\n");
}

int main() {
    int size, n;
    printf("随机数个数：");
    scanf("%d", &size);
    printf("选取次数：");
    scanf("%d", &n);
    int arr[size];
    printf("选取数字：");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    func(arr, size, n);
    return 0;
}