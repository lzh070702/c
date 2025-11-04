#include <stdio.h>

int main() {
    int guess = 50, left = 1, right = 101;
    printf("从 1 到 100 中选一个整数，我来试着猜一猜\n");
    printf("如果我猜对了，请输入 y ；\n");
    printf("如果我猜大了，请输入 b ；\n");
    printf("如果我猜小了，请输入 s 。\n");
    printf("我猜你的数字是 %d\n",guess);
    while (1){
        char result = getchar();
        if (result == 'y') {
            break;
        } else {
            if (result == 'b') {
                right = guess;
            }
            if (result == 's') {
                left = guess;
            }
            guess = (left + right) / 2;
            printf("嗯，那我猜是 %d\n", guess);
        }
    }
    printf("我就知道我可以");
    return 0;
}