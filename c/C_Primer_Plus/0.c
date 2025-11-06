#include <stdio.h>
#include <stdlib.h>

void number(int arr[],int seed){
    srand(seed);
    for (int i = 0; i < 100; i++){
        arr[i] = rand() % 10 + 1;
    }
}

void statistics(int arr[]){
    int counts[11] = {0};
    for (int i = 0; i < 100; i++) {
        counts[arr[i]]++;
    }
    for (int i = 1; i <= 10; i++) {
        printf("数字%d出现了%d次\n", i, counts[i]);
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        unsigned int seed;
        printf("请输入种子值：\n");
        scanf("%u", &seed);
        int arr[100] = {0};
        number(arr, seed);
        printf("当种子值为%u时，\n各种数出现的次数：\n",seed);
        statistics(arr);
    }
    return 0;
}