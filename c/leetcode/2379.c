#include <stdio.h>
#include <string.h>

int minimumRecolors(char* blocks, int k) {
    int res = 0;
    for (int i = 0; i < k; i++) {
        if (blocks[i] == 'W') {
            res++;
        }
    }
    int min_res = res;
    for (int i = k; i < strlen(blocks); i++) {
        if (blocks[i] == 'B' && blocks[i - k] == 'W') {
            res--;
            min_res = min_res < res ? min_res : res;
        } else if (blocks[i] == 'W' && blocks[i - k] == 'B') {
            res++;
        }
    }
    return min_res;
}

int main() {
    char blocks[] = "WBBWWBBWBW";
    printf("%d", minimumRecolors(blocks, 2));
    return 0;
}