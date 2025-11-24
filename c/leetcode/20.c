#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    if (len % 2) {
        return false;
    }
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i + 1] - s[i] == 1 || s[i + 1] - s[i] == 2) {
            int j;
            for (j = i + 2; s[j] != '\0'; j++) {
                s[j - 2] = s[j];
            }
            s[j - 2] = '\0';
            i = -1;
        }
    }
    len = strlen(s);
    if (len) {
        return false;
    }
    return true;
}

int main() {
    char s[] = "()([]{()})";
    if (isValid(s)) {
        printf("dui");
    } else {
        printf("cuo");
    }
    return 0;
}