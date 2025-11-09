#include <stdio.h>

int func(int num,int digit){
    num >>= digit - 1;
    return num % 2;
}

int main() {
    int num;
    int digit;
    scanf("%d %d", &num, &digit);
    printf("数字%d的二进制第%d位为：%d\n", num, digit, func(num, digit));
    return 0;
}