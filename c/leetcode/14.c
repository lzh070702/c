#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int len = strlen(strs[0]);
    int prefix_size = len;
    for (int i = 1; i < strsSize; i++) {
        int size = 0;
        while (strs[i - 1][size] == strs[i][size] && strs[i - 1][size] &&
               strs[i][size]) {
            size++;
        }
        prefix_size = prefix_size < size ? prefix_size : size;
    }
    char* prefix = (char*)malloc(prefix_size + 1);
    for (int i = 0; i < prefix_size; i++) {
        prefix[i] = strs[0][i];
    }
    prefix[prefix_size] = '\0';
    return prefix;
}

int main() {
    char* strs[] = {"flower", "flow", "flight"};
    printf("%s", longestCommonPrefix(strs, 3));
    return 0;
}