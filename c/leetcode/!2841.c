#include <stdio.h>

long long maxSum(int* nums, int numsSize, int m, int k) {
    int count = 0, x = 1;
    long long res = 0;
    for (int i = 0; i < k; i++) {
        int n = 1;
        for (int j = i + 1; j < k; j++) {
            if (nums[i] == nums[j]) {
                n = 0;
                break;
            }
        }
        count += n;
    }
    if (count < m) {
        x = 0;
    }
    for (int i = 0; i < k; i++) {
        res += nums[i];
    }
    long long max_res = res * x;
    for (int i = k; i < numsSize; i++) {
        x = 1;
        // for (int j = i - k + 1; j < i; j++) {
        //     if (nums[j] != nums[i - k] && nums[j] == nums[i]) {
        //         count--;
        //         break;
        //     }
        //     if (nums[j] == nums[i - k] && nums[j] != nums[i]) {
        //         count++;
        //         break;
        //     }
        // }
        if (count < m) {
            x = 0;
        }
        res = res + nums[i] - nums[i - k];
        max_res = max_res > res * x ? max_res : res * x;
    }
    return max_res;
}

int main() {
    int nums[] = {1, 2, 1, 2, 1, 2, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("%lld", maxSum(nums, numsSize, 3, 3));
    return 0;
}