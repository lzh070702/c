#include <stdio.h>
#include <string.h>

int numberOfSubstrings(char* s) {
    int left = strlen(s) - 1, right = left, res = 0;
    int hash[3] = {0};
    while (left >= 0) {
        hash[s[left] - 'a']++;
        if (hash[0] && hash[1] && hash[2]) {
            res += left + 1;
            hash[s[right--] - 'a']--;
            hash[s[left] - 'a']--;
        } else {
            left--;
        }
    }
    return res;
}

int main() {
    char s[] = "abcabc";
    int res = numberOfSubstrings(s);
    printf("%d\n", res);
    return 0;
}