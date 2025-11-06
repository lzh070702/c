#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc,char* argv[]) {
    double base = atoi(argv[1]);
    int index = atoi(argv[2]);
    printf("%lf\n", pow(base,index));
    return 0;
}