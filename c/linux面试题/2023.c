#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* welcome() {
    static char name[] = "444";
    return name;
}
int main(void) {
    char* a = welcome();
    printf("Hi, 我相信 %s 可以面试成功!\n", a);
    return 0;
}