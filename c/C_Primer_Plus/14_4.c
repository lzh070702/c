#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct name{
    char first[20];
    char middle[20];
    char last[20];
} NAME;

typedef struct people {
    int number;
    NAME name;
} P;

int main() {
    P arr[] = {302039823,{"Flossie","M","Dribble"}};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        printf("%s, %s ", arr[i].name.last, arr[i].name.first);
        if (strlen(arr[i].name.middle) > 0) {
            printf("%c. -- ", toupper(arr[i].name.middle[0]));
        }
        printf("%d\n", arr[0].number);
    }
    return 0;
}