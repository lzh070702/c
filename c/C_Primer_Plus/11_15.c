#include <stdio.h>

int ATOI(char* s) {
    if(s == NULL||s=="\0"){
        return 0;
    }
    int result = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] < '0' || s[i] > '9') {
            return 0;
        }
        result = result * 10 + (s[i] - '0');
    }
    return result;
}

int main() {
    char s[10] = "123456789";
    printf("%d\n", ATOI(s));
    return 0;
}