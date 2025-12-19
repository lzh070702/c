// #include <stdio.h>
// #include <string.h>

// int minimumLength(char* s) {
//     // if (strlen(s) == 1) {
//     //     return 1;
//     // }
//     int left = 0, right = strlen(s) - 1;
//     while (s[left] == s[right] && left < right) {
//         int l = left, r = right;
//         do {
//             left++;
//         } while (s[left] == s[l]);
//         if (left > right) {
//             return 0;
//         }
//         do {
//             right--;
//         } while (s[right] == s[r]);
//     }
//     return (right - left + 1) > 0 ? (right - left + 1) : 0;
// }

// int main() {
//     char s[] = "bbbbbbbbbbbbbbbbb";
//     printf("%d\n", minimumLength(s));
//     return 0;
// }