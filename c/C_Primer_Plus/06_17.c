#include <stdio.h>

int main() {
    double bonus = 1000000.0;
    int year = 0;
    while (bonus > 0) {
        bonus *= (1 + 0.08);
        bonus -= 100000.0;
        year++;
    }
    printf("%d 年后会取完所有的钱\n", year);
    return 0;
}