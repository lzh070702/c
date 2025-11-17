#include <stdio.h>

double findMedianSortedArrays(int* nums1,
                              int nums1Size,
                              int* nums2,
                              int nums2Size) {
    int digit1 = -1, digit2 = -1;
    int size = nums1Size + nums2Size;
    if ((size) % 2) {
        double result;
        for (int i = 0; i < size / 2 + 1; i++) {
            if (digit1 + 1 == nums1Size) {
                digit2++;
                result = (double)nums2[digit2];
            } else if (digit2 + 1 == nums2Size) {
                digit1++;
                result = (double)nums1[digit1];
            } else {
                if (nums1[digit1 + 1] < nums2[digit2 + 1]) {
                    digit1++;
                    result = (double)nums1[digit1];
                } else {
                    digit2++;
                    result = (double)nums2[digit2];
                }
            }
        }
        return result;
    } else {
        double result1, result2;
        for (int i = 0; i < size / 2 + 1; i++) {
            if (digit1 + 1 == nums1Size) {
                digit2++;
                result1 = (double)nums2[digit2];
            } else if (digit2 + 1 == nums2Size) {
                digit1++;
                result1 = (double)nums1[digit1];
            } else {
                if (nums1[digit1 + 1] < nums2[digit2 + 1]) {
                    digit1++;
                    result1 = (double)nums1[digit1];
                } else {
                    digit2++;
                    result1 = (double)nums2[digit2];
                }
            }
            if (i == size / 2) {
                return (result1 + result2) / 2;
            }
            result2 = result1;
        }
    }
    return 0.0;
}
int main() {
    int nums1[] = {1, 2};
    int nums1Size = 2;
    int nums2[] = {3, 4, 5};
    int nums2Size = 3;
    printf("%lf\n", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));
    return 0;
}