#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int arr[]) {
    for (int i = 0; i < 100; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void number(int arr[]) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 100; i++) {
        arr[i] = rand() % 10 + 1;
    }
}

void sort(int arr[]){
    for (int i = 0; i < 100 - 1; i++) {
        for (int j = i + 1; j < 100; j++) {
            if (arr[i] < arr[j]){
                arr[i] = arr[i] ^ arr[j];
                arr[j] = arr[i] ^ arr[j];
                arr[i] = arr[i] ^ arr[j];
            }
        }
    }
}

int main() {
    int arr[100] = {0};
    number(arr);
    printf("生成100个随机数：\n");
    print(arr);
    sort(arr);
    printf("对随机数进行排列：\n");
    print(arr);
    return 0;
}