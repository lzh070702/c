#include <stdio.h>

int main() {
    while(1){
        printf("请选择运算规则：\n");
        printf("a.add\t        s.subtract\nm.multiply\td.divide\nq.quit\n");
        char x;
        scanf("%c", &x);
        while (x != 'a' && x != 's' && x != 'm' && x != 'd' && x != 'q') {
            printf("输入错误，请重新输入：");
            while (getchar() != '\n') {
            }
            scanf("%c", &x);
        }
        if (x == 'q') {
            return 0;
        }
        float a, b;
        printf("请输入第一个数字：");
        while (scanf("%f", &a) != 1) {
            printf("输入错误，请重新输入第一个数字：");
            while (getchar() != '\n') {
            }
        }
        printf("请输入第二个数字：");
        while (scanf("%f", &b) != 1 || (x == 'd' && b == 0)) {
            printf("输入错误，请重新输入第二个数字：");
            while (getchar() != '\n') {
            }
        }
        float result;
        switch (x) {
            case 'a':
                result = a + b;
                printf("%f + %f = %f", a, b, result);
                break;
            case 's':
                result = a - b;
                printf("%f - %f = %f", a, b, result);
                break;
            case 'm':
                result = a * b;
                printf("%f * %f = %f", a, b, result);
                break;
            case 'd':
                result = a / b;
                printf("%f / %f = %f", a, b, result);
                break;
        }
    }
    return 0;
}