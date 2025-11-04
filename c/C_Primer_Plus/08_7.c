#include <stdio.h>

int main() {
    double salary;
    printf(
        "工资等级：\na)$8.75/hr\tb)$9.33/hr\nc)$10.00/hr\td)$11.20/"
        "hr\nq)quit\n请选择工资等级:");
    char level = getchar();
    switch (level) {
        case 'a':
            salary = 8.75;
            break;
        case 'b':
            salary = 9.33;
            break;
        case 'c':
            salary = 10.00;
            break;
        case 'd':
            salary = 11.20;
            break;
        case 'q':
        default:
            return 0;
    }
    double hour;
    printf("请输入一周工作时长：");
    scanf("%lf", &hour);
    if (hour > 40) {
        hour = 1.5 * (hour - 40) + 40;
    }
    salary *= hour;
    printf("工资总额：%lf\n", salary);
    double tax = 0;
    if (salary <= 300) {
        tax = salary * 0.15;
    } else if (300 < salary && salary <= 450) {
        tax = 300 * 0.15 + (salary - 300) * 0.20;
    } else {
        tax = 300 * 0.15 + 150 * 0.20 + (salary - 450) * 0.25;
    }
    printf("税金：%lf\n", tax);
    printf("净收入：%lf\n", salary - tax);
    return 0;
    return 0;
}