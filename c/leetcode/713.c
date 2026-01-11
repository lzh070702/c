#include <stdio.h>

int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    int left = 0, right = 0, res = 0, product = 1;
    while (right < numsSize) {
        product *= nums[right];
        if (product < k) {
            res += right - left + 1;
            right++;
        } else {
            product /= nums[left] * nums[right];
            left++;
            if (left > right) {
                product = 1;
                right++;
            }
        }
    }
    return res;
}

int main() {
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 0;
    int res = numSubarrayProductLessThanK(nums, numsSize, k);
    printf("%d\n", res);
    return 0;
}