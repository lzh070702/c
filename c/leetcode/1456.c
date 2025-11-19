#include <stdio.h>
#include <string.h>

int maxVowels(char* s, int k) {
    int n = strlen(s);
    int max_num = 0, num = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u') {
            num++;
        }
    }
    max_num = num;
    for (int i = k; i < n; i++) {
        if (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' ||
            s[i - k] == 'o' || s[i - k] == 'u') {
            num--;
        }
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u') {
            num++;
        }
        if (num == k) {
            return k;
        }
        max_num = max_num > num ? max_num : num;
    }
    return max_num;
}

int main() {
    char s[] = "ooooooo";
    int k = 7;
    printf("%d\n", maxVowels(s, k));
    return 0;
}