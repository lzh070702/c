#include <stdio.h>

void print(int arr[][5], int x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void two_arr(int arr[][5], int x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] *= 2;
        }
    }
}

int main() {
    int arr[3][5] = {{1,2,3,4,5},{6,7,8,9,0,},{5,4,3,2,1,}};
    int x = sizeof(arr) / sizeof(arr[0]) ;
    printf("原始数组：\n");
    print(arr, x);
    two_arr(arr, x);
    printf("翻倍数组：\n");
    print(arr, x);
    return 0;
}