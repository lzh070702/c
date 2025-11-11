#include <stdio.h>

int myAtoi(char* s) {
    int digit = 0, sign = 1;
    while (s[digit] == ' ') {
        digit++;
    }
    if (s[digit] == '-' || s[digit] == '+') {
        if (s[digit] == '-') {
            sign = -1;
        }
        digit++;
    }
    int result = 0;
    for (int i = digit; s[i] >= '0' && s[i] <= '9'; i++) {
        if (result > 214748364 || (result == 214748364 && s[i] > '7')) {
            if (sign == 1) {
                return 2147483647;
            }
            if (sign == -1) {
                return -2147483648;
            }
        }
        result = result * 10 + (s[i] - '0');
    }
    return sign * result;
}

int main() {
    return 0;
}