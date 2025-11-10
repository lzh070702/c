#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "命令行参数错误\n");
        exit(1);
    }
    FILE* original_file = fopen(argv[1], "rb");
    if (original_file == NULL) {
        fprintf(stderr, "原文件打开错误\n");
        exit(2);
    }
    FILE* target_file = fopen(argv[2], "wb");
    if (target_file == NULL) {
        fprintf(stderr, "目标文件创建错误\n");
        fclose(original_file);
        exit(3);
    }
    char buffer[1024];
    size_t read_size;
    while ((read_size = fread(buffer, 1, 1024, original_file)) > 0) {
        fwrite(buffer, 1, read_size, target_file);
    }
    if (ferror(original_file)) {
        fprintf(stderr, "原文件读取错误\n");
        fclose(original_file);
        fclose(target_file);
        exit(4);
    }
    if (ferror(target_file)) {
        fprintf(stderr, "目标文件写入错误\n");
        fclose(original_file);
        fclose(target_file);
        exit(5);
    }
    fclose(original_file);
    fclose(target_file);
    fprintf(stdout, "文件拷贝成功\n");
    exit(0);
}