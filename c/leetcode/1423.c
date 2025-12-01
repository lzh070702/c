#include <stdio.h>
#include <stdlib.h>

int maxScore(int* cardPoints, int cardPointsSize, int k) {
    int sum = 0, max_sum;
    int* new_cardPoints = (int*)malloc(2 * k * sizeof(cardPoints[0]));
    for (int i = 0; i < k; i++) {
        new_cardPoints[i] = cardPoints[cardPointsSize - k + i];
        new_cardPoints[k + i] = cardPoints[i];
    }
    for (int i = 0; i < k; i++) {
        sum += new_cardPoints[i];
    }
    max_sum = sum;
    for (int i = k; i < 2 * k; i++) {
        sum = sum + new_cardPoints[i] - new_cardPoints[i - k];
        max_sum = max_sum > sum ? max_sum : sum;
    }
    return max_sum;
}

int main() {
    int cardPoints[] = {1, 2, 3, 4, 5, 6, 1};
    int cardPointsSize = sizeof(cardPoints) / sizeof(cardPoints[0]);
    int k = 3;
    printf("%d\n", maxScore(cardPoints, cardPointsSize, k));
    return 0;
}