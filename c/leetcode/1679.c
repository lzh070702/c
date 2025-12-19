#include <stdio.h>
#include <stdlib.h>

int minArrivalsToDiscard(int* arrivals, int arrivalsSize, int w, int m) {
    int left = 0, right = w;
    int* cnt = (int*)malloc((arrivalsSize + 1) * sizeof(int));
    int res = 0;
    for (int i = 0; i < w; i++) {
        cnt[arrivals[i]]++;
        if (cnt[arrivals[i]] == m + 1) {
            cnt[arrivals[i]] = m;
            res++;
        }
    }
    while (right != arrivalsSize) {
        cnt[arrivals[left]]--;
        cnt[arrivals[right]]++;
        if (cnt[arrivals[right]] == m + 1) {
            cnt[arrivals[right]] = m;
            res++;
        }
        left++;
        right++;
    }
    return res;
}

int main() {
    int arrivals[] = {1, 2, 3, 3, 3, 4};
    int arrivalsSize = sizeof(arrivals) / sizeof(arrivals[0]);
    int w = 3;
    int m = 2;
    printf("%d\n", minArrivalsToDiscard(arrivals, arrivalsSize, w, m));
    return 0;
}