#include <stdbool.h>
#include <stdio.h>

int main() {
    int num = 0;
    printf("请输入一个正整数：");
    if (scanf("%d", &num) != 1 || num < 1) {
        printf("输入错误");
        return 1;
    }
    bool is_prime[num + 1];
    for (int i = 0; i <= num; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= num; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= num; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 0; i <= num; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    return 0;
}