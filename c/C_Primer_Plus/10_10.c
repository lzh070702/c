#include <stdio.h>

void arr_add(int arr1[], int arr2[], int arr[], int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = arr1[i] + arr2[i];
    }
}

int main() {
    int arr1[4] = {2, 4, 5, 8};
    int arr2[4] = {1, 0, 4, 6};
    int arr[4] = {0};
    int len = sizeof(arr) / sizeof(arr[0]);
    arr_add(arr1, arr2, arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}                    