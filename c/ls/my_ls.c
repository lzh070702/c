#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    int len = 0;
    int size = 0;
    int file_num = 0;
    char** file = (char**)malloc(argc * sizeof(char*));
    char* parameter = (char*)malloc(1);
    bool a = false, l = false, R = false, t = false;
    bool r = false, i = false, s = false;
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
    if (!file_num || argc == 1) {
        file[0] = ".";
        file_num = 1;
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
            if (parameter[i] == 'a') {
                a = true;
            } else if (parameter[i] == 'l') {
                l = true;
            } else if (parameter[i] == 'R') {
                R = true;
            } else if (parameter[i] == 't') {
                t = true;
            } else if (parameter[i] == 'r') {
                r = true;
            } else if (parameter[i] == 'i') {
                i = true;
            } else {
                s = true;
            }
        }
    }
    size = len;
    parameter = (char*)realloc(parameter, size + 1);
    parameter[size] = '\0';

    // 参数处理

    for (int i = 0; i < file_num; i++) {
        struct stat statbuf;
        stat(file[i], &statbuf);
        if (S_ISREG(statbuf.st_mode)) {  // 普通文件
            printf("%s\n", file[i]);
        } else {
            DIR* dir = opendir(file[i]);
            struct dirent* d_file;  // 目录下的文件
            while ((d_file = readdir(dir)) != NULL) {
                if (!a && d_file->d_name[0] == '.') {  // 参数 a 的执行
                    continue;
                }
                printf("%s\n", d_file->d_name);
            }
            printf("\n");
            closedir(dir);
        }
    }

    // 参数执行

    free(file);
    free(parameter);
    return 0;
}