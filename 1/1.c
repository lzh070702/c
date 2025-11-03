#include <stdio.h>
#include <stdlib.h>

struct result {
    int* arr;
    int size;
};

void print_result(struct result result) {
    for (int i = 0; i < result.size; i++) {
        printf("%d ", result.arr[i]);
    }
    printf("\n");
}

void my_concat(int* arr1,
                 int len1,
                 int* arr2,
                 int len2,
                 struct result* result) {
    int total = len1 + len2;
    result->arr = (int*)malloc(total * sizeof(int));
    for (int i = 0; i < len1; i++) {
        result->arr[i] = arr1[i];
    }
    for (int i = 0; i < len2; i++) {
        result->arr[len1 + i] = arr2[i];
    }
    result->size = total;
}

void my_sort(struct result* result) {
    for (int i = 0; i < result->size - 1; i++) {
        for (int j = 0; j < result->size - i - 1; j++) {
            if (result->arr[j] > result->arr[j + 1]) {
                int temp = result->arr[j];
                result->arr[j] = result->arr[j + 1];
                result->arr[j + 1] = temp;
            }
        }
    }
}

void my_dedup(struct result* result) {
    int new_size = 1;
    for (int i = 1; i < result->size; i++) {
        if (result->arr[i] != result->arr[new_size - 1]) {
            result->arr[new_size++] = result->arr[i];
        }
    }
    int* temp = (int*)realloc(result->arr, new_size * sizeof(int));
    result->arr = temp;
    result->size = new_size;
}

int main() {
    int arr1[] = {6, 1, 2, 1, 9, 1, 3, 2, 6, 2};
    int arr2[] = {4, 2, 2, 1, 6, 2};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    struct result result;
    my_concat(arr1, len1, arr2, len2, &result);
    print_result(result);
    my_sort(&result);
    print_result(result);
    my_dedup(&result);
    print_result(result);
    free(result.arr);
    return 0;
}