#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

typedef struct file_metadata {
    // i_node
    // 磁盘占用块数
    // 类型
    // 所有者权限
    // 所属组权限
    // 其他用户权限
    // 硬链接数
    // 用户名
    // 组名
    // 文件大小（字节）
    // mtime
    // 文件名
} FM;

int main(int argc, char* argv[]) {
    int len = 0, size = 0;                               // 参数长度
    int file_num = 0;                                    // 文件个数
    char** file = (char**)malloc(argc * sizeof(char*));  // 用于存放文件路径
    char* parameter = (char*)malloc(1);                  // 用于存放选项
    bool a = false, l = false, R = false, t = false;     // 选项
    bool r = false, I = false, s = false;  // 为防止变量冲突，将i记为I

    // 以下为参数的分类
    for (int i = 1; i < argc; i++) {
        // 分别存放文件路径和选项
        if (argv[i][0] != '-') {
            // 存放文件路径
            file[file_num++] = argv[i];
            continue;
        }
        size += strlen(argv[i]) - 1;
        parameter = (char*)realloc(parameter, size + 1);
        for (int j = 1; j < strlen(argv[i]); j++) {
            // 存放选项
            if (argv[i][j] != 'a' && argv[i][j] != 'l' && argv[i][j] != 'R' &&
                argv[i][j] != 't' && argv[i][j] != 'r' && argv[i][j] != 'i' &&
                argv[i][j] != 's') {
                // 判断选项是否有效
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
        // 未输入文件路径的情况
        file[0] = ".";
        file_num = 1;
    }
    parameter[size] = '\0';
    // 以下为选项的去重（冗长，有时间再改，可不去重）
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
                I = true;
            } else {
                s = true;
            }
        }
    }
    size = len;
    parameter = (char*)realloc(parameter, size + 1);
    parameter[size] = '\0';
    // 以下为选项的执行
    for (int i = 0; i < file_num; i++) {
        // if (l == true || s == true) {
        //     printf("总计 ");
        //     // 
        //     //
        //     printf("\n");
        // }
        struct stat statbuf;
        stat(file[i], &statbuf);
        if (S_ISREG(statbuf.st_mode)) {
            // 普通文件
            if (I) {
                // 参数 I(i) 的执行
                printf("%ld ", statbuf.st_ino);
            }
            printf("%s\n", file[i]);
        } else {
            // 目录文件
            DIR* dir = opendir(file[i]);
            struct dirent* d_file;  // 目录下的文件
            while ((d_file = readdir(dir)) != NULL) {
                // 参数 a 的执行
                if (!a && d_file->d_name[0] == '.') {
                    continue;
                }
                struct stat d_statbuf;
                stat(d_file->d_name, &d_statbuf);
                if (I) {
                    printf("%ld ", d_statbuf.st_ino);
                }
                printf("%s\n", d_file->d_name);
            }
            closedir(dir);
        }
    }
    //
    free(file);
    free(parameter);
    return 0;
}