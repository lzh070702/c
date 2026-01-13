#include <stdio.h>
#include <string.h>

int numberOfSubstrings(char* s, int k) {
    int left = strlen(s) - 1, right = left, res = 0;
    int hash[26] = {0};
    while (left >= 0) {
        hash[s[left] - 'a']++;
        if (hash[s[left] - 'a'] == k) {
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
    char s[] = "abcde";
    int k = 1;
    int res = numberOfSubstrings(s, k);
    printf("%d\n", res);
    return 0;
}