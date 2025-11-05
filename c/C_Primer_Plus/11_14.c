#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc,char* argv[]) {
    double base = atoi(argv[0]);
    int index = atoi(argv[1]);
    printf("%lf", pow(base,index));
    return 0;
}