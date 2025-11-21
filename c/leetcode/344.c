#include <stdio.h>
#include <string.h>

void reverseString(char* s, int sSize) {
    int left = 0, right = sSize - 1;
    while (left < right) {
        s[left] = s[left] ^ s[right];
        s[right] = s[left] ^ s[right];
        s[left] = s[left] ^ s[right];
        left++;
        right--;
    }
}

int main() {
    char s[] = "hello";
    reverseString(s, 5);
    printf("%s", s);
    return 0;
}