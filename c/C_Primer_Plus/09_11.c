#include <stdio.h>

long long Fibonacci(long long x) {
    if (x == 1 || x == 2){
        return 1;
    }
    return Fibonacci(x - 2) + Fibonacci(x - 1);
}

int main() {
    long long x;
    scanf("%lld", &x);
    printf("%lld", Fibonacci(x));
    return 0;
}