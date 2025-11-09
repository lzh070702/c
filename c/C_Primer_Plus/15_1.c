#include <stdio.h>
#include <math.h>
#include <string.h>

int number(char* pbin) {
    int result;
    int len = strlen(pbin);
    if(pbin[0] == '0'){
        for (int i = len - 1; i > 0; i--) {
            if (pbin[i] == '1') {
                result += pow(2, len - i - 1);
            }
        }
    }
    if(pbin[0] == '1'){
        for (int i = len - 1; i > 0; i--) {
            if (pbin[i] == '0') {
                result += pow(2, len - i - 1);
            }
        }
        result = -(result + 1);
    }
    return result;
}

int main() {
    char* pbin ="01001001";
    printf("%d\n",number(pbin));
    return 0;
}