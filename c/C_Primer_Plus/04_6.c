#include <stdio.h>
#include <string.h>

int main() {
    char first_name[10], last_name[10];
    printf("请输入名：");
    scanf("%s", &first_name);
    printf("请输入姓：");
    scanf("%s", &last_name);
    int first_len = strlen(first_name), last_len = strlen(last_name);
    printf("%s %s\n", first_name, last_name);
    for (int i = 0; i < first_len - 1; i++) {
        printf(" ");
    }
    printf("%d ", first_len);
    for (int i = 0; i < last_len - 1; i++) {
        printf(" ");
    }
    printf("%d\n", last_len);
    printf("%s %s\n", first_name, last_name);
    printf("%d ", first_len);
    for (int i = 0; i < first_len - 1; i++) {
        printf(" ");
    }
    printf("%d", last_len);
    for (int i = 0; i < last_len - 1; i++) {
        printf(" ");
    }
    printf("\n");
    return 0;
}