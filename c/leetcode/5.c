#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
    int len = strlen(s) - 1;
    int left = 0, right = left + len;
    while (left < right) {
        if (s[left] == s[right]) {
            int result_left = left++;
            int result_right = right--;
            while (left < right) {
                if (s[left] != s[right]) {
                    left = result_left;
                    right = result_right;
                    break;
                }
                left++;
                right--;
            }
            if (left >= right) {
                char* result_s = (char*)malloc(result_right - result_left + 2);
                for (int i = 0; i <= result_right - result_left; i++) {
                    result_s[i] = s[result_left + i];
                }
                result_s[result_right - result_left + 1] = '\0';
                return result_s;
            }
        }
        if (right + 1 == strlen(s)) {
            len--;
            left = 0;
            right = left + len;
        } else {
            left++;
            right++;
        }
    }
    char* result_s = (char*)malloc(2);
    result_s[0] = s[0];
    result_s[1] = '\0';
    return result_s;
}

int main() {
    char s[] = "bacabab";
    char* res_s = longestPalindrome(s);
    printf("%s", res_s);
    free(res_s);
    res_s = NULL;
    return 0;
}