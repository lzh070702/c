int lengthOfLongestSubstring(char* s) {
    int length = 0;
    while (*(s + length) != 0) {
        length++;
    }
    if (length == 1) {
        return 1;
    }
    int left = 0;
    int right = 0;
    int ascii[128] = {0};
    int max_len = 0;
    for (; *(s + right) != 0; right++) {
        if (ascii[*(s + right)]) {
            left = ascii[*(s + right)];
            right = left;
            for (int i = 0; i < 128; i++) {
                ascii[i] = 0;
            }
        }
        ascii[*(s + right)] = right + 1;
        max_len = (max_len > (right - left + 1) ? max_len : (right - left + 1));
    }
    return max_len;
}