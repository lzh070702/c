#include<stdio.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int min_len = 1000;
    for (int i = 0; i < strsSize; i++){
        int j = 0;
        while(strs[i][j] != 0) {
            j++;
        }
        min_len = min_len < j ? min_len : j;
    }
    return min_len;
}

int main(){
    char** strs = [ "flower", "flow", "flight" ];
    printf("%d", longestCommonPrefix(strs, 3));
    return 0;
}