#include <stdio.h>

int* getAverages(int* nums, int numsSize, int k, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    if (numsSize <= 2 * k + 1) {
        for (int i = 0; i < numsSize; i++) {
            result[i] = -1;
        }
        return result;
    }
    for (int i = 0; i < k; i++) {
        result[i] = -1;
        result[numsSize - i - 1] = -1;
    }
    long long res = 0;
    for (int i = 0; i < 2 * k + 1; i++) {
        res += nums[i];
    }
    result[k] = res / (2 * k + 1);
    for (int i = 0; i < (numsSize - 2 * k - 1); i++) {
        res = (res - nums[i] + nums[2 * k + i + 1]);
        result[k + i + 1] = res / (2 * k + 1);
    }
    return result;
}