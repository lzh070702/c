int maxArea(int* height, int heightSize) {
    int result = 0;
    int i = 0, j = heightSize - 1;
    while (i != j) {
        int h = height[i] < height[j] ? height[i] : height[j];
        result = result > h * (j - i) ? result : h * (j - i);
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return result;
}