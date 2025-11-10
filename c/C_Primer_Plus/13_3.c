#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char file[200];
    scanf("%s", file);
    FILE* original_file = fopen(file, "r");
    if (original_file == NULL) {
        fprintf(stderr, "原文件打开错误\n");
        exit(1);
    }
    fseek(original_file, 0, SEEK_END);
    long size = ftell(original_file);
    fseek(original_file, 0, SEEK_SET);
    char* buffer = (char*)malloc(size + 1);
    buffer[size] = '\0';
    fread(buffer, 1, size, original_file);
    for (int i = 0; i < size; i++) {
        buffer[i] = toupper(buffer[i]);
    }
    FILE* target_file = fopen(file, "w");
    if (target_file == NULL) {
        fprintf(stderr, "目标文件创建错误\n");
        fclose(original_file);
        free(buffer);
        exit(2);
    }
    fwrite(buffer, 1, size, target_file);
    fclose(original_file);
    fclose(target_file);
    free(buffer);
    exit(0);
}