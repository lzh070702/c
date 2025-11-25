#include<stdio.h>

int numOfSubarrays(int* arr, int arrSize, int k, int threshold) {
    int num = 0;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    if (sum >= (k * threshold)) {
        num++;
    }
    for (int i = k; i < arrSize; i++) {
        sum = sum + arr[i] - arr[i - k];
        if (sum >= (k * threshold)) {
            num++;
        }
    }
    return num;
}

int main() {
    int arr[] = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    printf("%d", numOfSubarrays(arr, arrSize, 3, 5));
    return 0;
}