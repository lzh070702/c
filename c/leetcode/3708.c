#include <stdio.h>

int longestSubarray(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return numsSize;
    }
    int res = 2, max_res = 2;
    for (int i = 2; i < numsSize; i++) {
        if (nums[i] == nums[i - 1] + nums[i - 2]) {
            res++;
        } else {
            max_res = max_res > res ? max_res : res;
            res = 2;
        }
    }
    return max_res > res ? max_res : res;
}

int main() {
    int nums[] = {1,1,2,3,5,8};
    int size = sizeof(nums) / 4;
    printf("%d\n", longestSubarray(nums, size));
    return 0;
}
