#include <ctype.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int file_qsort(const void* a, const void* b) {
    const char* cmp_a = *(const char**)a;
    const char* cmp_b = *(const char**)b;
    int str_a = (cmp_a[0] == '.') ? 1 : 0;
    int str_b = (cmp_b[0] == '.') ? 1 : 0;
    // 字母排序
    while (cmp_a[str_a] && cmp_b[str_b]) {
        int lower_a = tolower((unsigned char)cmp_a[str_a]);
        int lower_b = tolower((unsigned char)cmp_b[str_b]);
        if (lower_a != lower_b) {
            // 字母顺序排序
            return lower_a - lower_b;
        } else {
            // 字母大小写排序
            if (islower(cmp_a[str_a]) && isupper(cmp_b[str_b])) {
                return -1;
            }
            if (isupper(cmp_a[str_a]) && islower(cmp_b[str_b])) {
                return 1;
            }
        }
        str_a++;
        str_b++;
    }
    if (cmp_a[str_a] != cmp_b[str_b]) {
        // str已经到'\0'（短的）排在前面
        return cmp_a[str_a] - cmp_b[str_b];
    }
    // 隐藏文件排序
    int hidden_a = (cmp_a[0] == '.');
    int hidden_b = (cmp_b[0] == '.');
    if (hidden_a && !hidden_b) {
        return -1;
    }
    if (!hidden_a && hidden_b) {
        return 1;
    }
    return 0;
}

int r_file_qsort(const void* a, const void* b) {
    return file_qsort(b, a);
}

int main(int argc, char* argv[]) {
    // 参数的分类
    int file_num = 0;                                      // 文件个数
    int o_file_num = 0;                                    // 普通文件个数
    int d_file_num = 0;                                    // 目录文件个数
    int len = 0, num = 0;                                  // 选项个数
    char** file = (char**)malloc(argc * sizeof(char*));    // 存放文件路径
    char** o_file = (char**)malloc(argc * sizeof(char*));  // 存放普通文件路径
    char** d_file = (char**)malloc(argc * sizeof(char*));  // 存放目录文件路径
    char* parameter = (char*)malloc(1);                    // 存放选项
    bool a = false, l = false, R = false;                  // 选项
    bool t = false, r = false, s = false;                  // 选项
    bool I = false;  // 选项，为防止变量冲突，将i记为I
    for (int i = 1; i < argc; i++) {
        // 分别存放文件路径和选项
        if (argv[i][0] != '-') {
            // 存放文件路径
            file[file_num++] = argv[i];
            continue;
        }
        num += strlen(argv[i]) - 1;
        parameter = (char*)realloc(parameter, num + 1);
        for (int j = 1; j < strlen(argv[i]); j++) {
            // 存放选项
            if (argv[i][j] != 'a' && argv[i][j] != 'l' && argv[i][j] != 'R' &&
                argv[i][j] != 't' && argv[i][j] != 'r' && argv[i][j] != 'i' &&
                argv[i][j] != 's') {
                // 判断选项是否有效
                printf("ls: 无效的选项 -- %c\n", argv[i][j]);
                printf("请尝试执行 \"ls --help\" 来获取更多信息。\n");
                free(file);
                free(d_file);
                free(o_file);
                free(parameter);
                return 0;
            }
            parameter[len++] = argv[i][j];
        }
    }
    parameter[num] = '\0';
    // 文件路径的分类
    if (!file_num) {
        // 未输入文件路径的情况
        file[0] = ".";
        file_num = 1;
    }
    file[file_num] = NULL;
    for (int i = 0; i < file_num; i++) {
        struct stat statbuf;
        if (stat(file[i], &statbuf) == -1) {
            // 文件路径错误
            printf("ls: 无法访问 '%s': 没有那个文件或目录", file[i]);
        } else if (S_ISREG(statbuf.st_mode)) {
            // 普通文件路径
            o_file[o_file_num++] = file[i];
        } else {
            // 目录文件路径
            d_file[d_file_num++] = file[i];
        }
    }
    o_file = (char**)realloc(o_file, (o_file_num + 1) * sizeof(char*));
    d_file = (char**)realloc(d_file, (d_file_num + 1) * sizeof(char*));
    o_file[o_file_num] = NULL;
    d_file[d_file_num] = NULL;
    // 选项的处理
    for (int i = 0; i < num; i++) {
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
        } else if (parameter[i] == 's') {
            s = true;
        } else {
            I = true;
        }
    }
    // 文件的排序
    if (!t && !r) {
        qsort(o_file, o_file_num, sizeof(char*), file_qsort);
        qsort(d_file, d_file_num, sizeof(char*), file_qsort);
    } else if (!t && r) {
        qsort(o_file, o_file_num, sizeof(char*), r_file_qsort);
        qsort(d_file, d_file_num, sizeof(char*), r_file_qsort);
    } else if (t && !r) {
    } else {
    }

    // 选项的执行
    for (int i = 0; i < o_file_num; i++) {
        struct stat statbuf;
        stat(o_file[i], &statbuf);
        if (I) {
            printf("%lu ", (unsigned long)statbuf.st_ino);
        }
        if (s) {
            printf("%lu ", (unsigned long)statbuf.st_blocks / 2);
        }
        if (l) {
            putchar(S_ISREG(statbuf.st_mode) ? '-' : 'd');
            putchar((statbuf.st_mode & S_IRUSR) ? 'r' : '-');
            putchar((statbuf.st_mode & S_IWUSR) ? 'w' : '-');
            putchar((statbuf.st_mode & S_IXUSR) ? 'x' : '-');
            putchar((statbuf.st_mode & S_IRGRP) ? 'r' : '-');
            putchar((statbuf.st_mode & S_IWGRP) ? 'w' : '-');
            putchar((statbuf.st_mode & S_IXGRP) ? 'x' : '-');
            putchar((statbuf.st_mode & S_IROTH) ? 'r' : '-');
            putchar((statbuf.st_mode & S_IWOTH) ? 'w' : '-');
            putchar((statbuf.st_mode & S_IXOTH) ? 'x' : '-');
            printf(" %lu ", (unsigned long)statbuf.st_nlink);
            printf("%s ", getpwuid(statbuf.st_uid)->pw_name);
            printf("%s ", getgrgid(statbuf.st_gid)->gr_name);
            printf("%lu ", (unsigned long)statbuf.st_size);
        }
        printf("%s\n", o_file[i]);
    }

    //
    for (int i = 0; i < file_num; i++) {
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
            struct dirent* dir_file;  // 目录下的文件
            while ((dir_file = readdir(dir)) != NULL) {
                // 参数 a 的执行
                if (!a && dir_file->d_name[0] == '.') {
                    continue;
                }
                struct stat d_statbuf;
                stat(dir_file->d_name, &d_statbuf);
                if (I) {
                    printf("%ld ", d_statbuf.st_ino);
                }
                printf("%s\n", dir_file->d_name);
            }
            closedir(dir);
        }
    }
    free(file);
    free(d_file);
    free(o_file);
    free(parameter);
    return 0;
}