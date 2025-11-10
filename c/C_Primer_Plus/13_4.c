#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if(argc == 1){
        fprintf(stderr, "命令行参数错误\n");
        exit(1);
    }
    for (int i=1;i<argc;i++) {
        FILE* original_file = fopen(argv[i], "r");
        if (original_file == NULL) {
            fprintf(stderr, "原文件打开错误\n");
            continue;
        }
        fseek(original_file, 0, SEEK_END);
        long size = ftell(original_file);
        fseek(original_file, 0, SEEK_SET);
        char* buffer = (char*)malloc(size + 1);
        buffer[size] = '\0';
        fread(buffer, 1, size, original_file);
        printf("文件：%s\n", argv[i]);
        printf("%s\n", buffer);
        free(buffer);
        fclose(original_file);
    }
    return 0;
}