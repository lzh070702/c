#include <stdio.h>
#include <stdlib.h>

typedef struct res{
    int* arr;
    int len;
} result;

void my_sort(int* arr1,int len1,int* arr2,int len2,result* result) {
    result->len = len1 + len2;//计算总长
    result->arr = (int*)malloc(result->len * sizeof(int));//分配内存
    for (int i = 0; i < len1; i++) {
        result->arr[i] = arr1[i];
    }
    for (int i = 0; i < len2; i++) {
        result->arr[len1 + i] = arr2[i];
    }//合并数组
    for (int i = 0; i < result->len - 1; i++) {
        for (int j = 0; j < result->len - i - 1; j++) {
            if (result->arr[j] > result->arr[j + 1]) {
                int t = result->arr[j];
                result->arr[j] = result->arr[j + 1];
                result->arr[j + 1] = t;
            }
        }
    }//冒泡排序
    int new_len = 1;
    for (int i = 1; i < result->len; i++) {
        if (result->arr[new_len-1] != result->arr[i]) {
            result->arr[new_len++] = result->arr[i];
        }
    }//去重
    int* new_arr = (int*)realloc(result->arr, new_len * sizeof(int));  // 重新分配内存
    result->len = new_len;
    result->arr = new_arr;
}

int main() {
    int arr1[] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 10};
    int arr2[] = {2, 1, 4, 3, 9, 6, 8};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    result result;
    my_sort(arr1, len1, arr2, len2, &result);
    for (int i = 0; i < result.len; i++) {
        printf("%d ", result.arr[i]);
    }
    free(result.arr);
    return 0;
}