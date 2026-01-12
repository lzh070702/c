#include <stdio.h>
#include <string.h>

int beautifulBouquet(int* flowers, int flowersSize, int cnt) {
    int left = 0, right = 0, res = 0;
    int hash[100001] = {0};
    while (right < flowersSize) {
        hash[flowers[right]]++;
        if (hash[flowers[right]] <= cnt) {
            res += right - left + 1;
            right++;
        } else {
            hash[flowers[right]]--;
            hash[flowers[left]]--;
            left++;
            if (left > right) {
                hash[flowers[right]]++;
                right++;
            }
        }
    }
    return res;
}

int main() {
    int flowers[] = {5, 3, 3, 3};
    int flowersSize = sizeof(flowers) / sizeof(flowers[0]);
    int cnt = 2;
    int res = beautifulBouquet(flowers, flowersSize, cnt);
    printf("%d\n", res);
    return 0;
}