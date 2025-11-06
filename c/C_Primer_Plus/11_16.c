#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char mode;
    if (argc == 1 || !strcmp(argv[1], "-p")) {
        mode = 'p';
    } else if (!strcmp(argv[1], "-u")) {
        mode = 'u';
    } else if (!strcmp(argv[1], "-l")) {
        mode = 'l';
    } else {
        return 1;
    }
    int ch;
    while ((ch = getchar()) != EOF) {
        switch (mode)
        {
        case 'p':
            break;
        case 'u':
            if (ch >= 'a' && ch <= 'z') {
                ch -= 32;
            }
            break;
        case 'l':
            if (ch >= 'A' && ch <= 'Z') {
                ch += 32;
            }
            break;
        }
        putchar(ch);
    }
    return 0;
}