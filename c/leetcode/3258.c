#include <stdio.h>
#include <string.h>

int countKConstraintSubstrings(char* s, int k) {
    int left = 0, right = 0, count = 0, res = 0;
    while (right < strlen(s)) {
        count += s[right] - '0';
        if (count <= k || right - left - count + 1 <= k) {
            res += right - left + 1;
            right++;
        } else {
            count -= s[left] - '0' + s[right] - '0';
            left++;
            if (left > right) {
                count = 0;
                right++;
            }
        }
    }
    return res;
}

int main() {
    char s[] = "10001";
    int k = 1;
    int res = countKConstraintSubstrings(s, k);
    printf("%d\n", res);
    return 0;
}