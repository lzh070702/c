#include <stdio.h>

void chline(char ch, int i, int j) {
    for (int x = 0; x < i; x++) {
        for (int y = 0; y < j; y++) {
            printf("%c",ch);
        }
        printf("\n");
    }
}

int main() {
    char ch = getchar();
    int i, j;
    scanf("%d %d", &j, &i);
    chline(ch, i, j);
    return 0;
}