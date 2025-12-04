#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int len = 0;
    int size = 0;
    int file_num = 0;
    char** file = (char**)malloc(argc * sizeof(char*));
    char* parameter = (char*)malloc(1);
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            file[file_num++] = argv[i];
            continue;
        }
        size += strlen(argv[i]) - 1;
        parameter = (char*)realloc(parameter, size + 1);
        for (int j = 1; j < strlen(argv[i]); j++) {
            if (argv[i][j] != 'a' && argv[i][j] != 'l' && argv[i][j] != 'R' &&
                argv[i][j] != 't' && argv[i][j] != 'r' && argv[i][j] != 'i' &&
                argv[i][j] != 's') /*参数无效*/ {
                printf("ls: 无效的选项 -- %c\n", argv[i][j]);
                printf("请尝试执行 \"ls --help\" 来获取更多信息。\n");
                free(file);
                free(parameter);
                return 0;
            }
            parameter[len++] = argv[i][j];
        }
    }
    if (!file_num) {
        file[0] = ".";
    }
    parameter[size] = '\0';
    for (int i = 0; i < size; i++) {
        if (parameter[i] == ' ') {
            continue;
        }
        for (int j = i + 1; j < size; j++) {
            if (parameter[i] == parameter[j]) {
                parameter[j] = ' ';
            }
        }
    }
    len = 0;
    for (int i = 0; i < size; i++) {
        if (parameter[i] == ' ') {
            continue;
        } else {
            parameter[len++] = parameter[i];
        }
    }
    size = len;
    parameter = (char*)realloc(parameter, size + 1);
    parameter[size] = '\0';

    // 参数处理

    printf("%d\n", file_num);  // 文件个数
    for (int i = 0; i < file_num; i++) {
        printf("%s\n", file[i]);
    }  // 文件
    printf("%d\n", size);       // 参数个数
    printf("%s\n", parameter);  // 参数

    //

    free(file);
    free(parameter);
    return 0;
}