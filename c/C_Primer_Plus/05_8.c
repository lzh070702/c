#include <stdio.h>

int main() {
    int num1, num2;
    printf("请输入求模运算符的第2个运算对象：");
    scanf("%d", &num2);
    printf("请输入求模运算符的第1个运算对象：");
    scanf("%d", &num1);
    if (num1 > 0) {
        printf("%d %% %d = %d\n", num1, num2, num1 % num2);
    } else {
        return 0;
    }
    while (1) {
        printf("请再次输入求模运算符的第1个运算对象：");
        scanf("%d", &num1);
        if (num1 > 0) {
            printf("%d %% %d = %d\n", num1, num2, num1 % num2);
        } else {
            return 0;
        }
    }
    return 0;
}