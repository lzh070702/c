#include <stdio.h>

long long countSubarrays(int* nums, int numsSize, int k) {
    long long res = 0;
    int max = nums[0], left = numsSize - 1, right = left, cnt = 0;
    for (int i = 1; i < numsSize; i++) {
        max = max > nums[i] ? max : nums[i];
    }
    while (left >= 0) {
        if (nums[left] == max) {
            cnt++;
        }
        if (cnt == k) {
            res += left + 1;
            if (nums[left] == max) {
                cnt--;
            }
            if (nums[right--] == max) {
                cnt--;
            }
        } else {
            left--;
        }
    }
    return res;
}

int main() {
    int nums[] = {1, 4, 2, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;
    long long res = countSubarrays(nums, numsSize, k);
    printf("%lld\n", res);
    return 0;
}