#include <stdio.h>

int lengthOfLastWord(char* s) {
    int len = 0;
    while (s[len] != 0) {
        len++;
    }
    int right = len - 1;
    while (s[right] == ' ') {
        right--;
    }
    int left = right;
    while (left != -1 && s[left] != ' ') {
        left--;
    }
    return right - left;
}