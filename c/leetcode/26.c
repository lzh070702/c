#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int new_size = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[new_size - 1]) {
            nums[new_size++] = nums[i];
        }
    }
    return new_size;
}

int main() {
    int nums[] = {1, 1, 2};
    printf("%d\n", removeDuplicates(nums, 3));
    for (int i = 0; i < 3; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}