#include <stdio.h>
#include <string.h>

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int truemonth(char* month) {
    if (strlen(month) == 1) {
        return month[0] - '0';
    }
    if (!strcmp(month, "10")) {
        return 10;
    }
    if (!strcmp(month, "11")) {
        return 11;
    }
    if (!strcmp(month, "12")) {
        return 12;
    }
    char* months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    char* full_months[12] = {"january",   "february", "march",    "april",
                             "may",       "june",     "july",     "august",
                             "september", "october",  "november", "december"};
    for (int i = 0; i < 12; i++) {
        if (!strcmp(month, months[i]) || !strcmp(month, full_months[i])) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    int day = 0;
    char month[20];
    int year;
    printf("请输入日，月，年：\n");
    scanf("%d %s %d", &day, month, &year);
    int true_month = truemonth(month);
    for (int i = 1; i < true_month; i++) {
        switch (i) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                day += 31;
                break;
            case 2:
                day += 28;
                break;
            default:
                day += 30;
                break;
        }
    }
    if (true_month > 2 && is_leap_year(year)) {
        day++;
    }
    printf("当年到该日期的总天数为：%d\n", day);
    return 0;
}