int reverse(int x) {
    int result = 0;
    int n = x % 10;
    while (x != 0) {
        n = x % 10;
        if (result > 214748364 || (result == 214748364 && n > 7)) {
            return 0;
        }
        if (result < -214748364 || (result == -214748364 && n < -8)) {
            return 0;
        }
        result = result * 10 + n;
        x /= 10;
    }
    return result;
}
