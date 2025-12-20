bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int x1 = x;
    long new_x = 0;
    for (; x != 0; x = x / 10) {
        int n = x % 10;
        new_x = new_x * 10 + n;
    }
    return new_x == x1;
}