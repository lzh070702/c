#include <stdio.h>

int func(int num){
    int result = 0;
    while(num) {
        result += num % 2;
        num /= 2;
    }
    return result;
}

int main() {
    int num;
    scanf("%d",&num);
    printf("数字%d中打开位的数量为：%d\n",num,func(num));
    return 0;
}