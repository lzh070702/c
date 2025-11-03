#include <stdio.h>

int main() {
    double salary;
    int level = 0;
    printf(
        "工资等级：\n1)$8.75/hr\t2)$9.33/hr\n3)$10.00/hr\t4)$11.20/"
        "hr\n5)quit\n请选择工资等级:");
    scanf("%d", &level);
    switch (level) {
        case 1:
            salary = 8.75;
            break;
        case 2:
            salary = 9.33;
            break;
        case 3:
            salary = 10.00;
            break;
        case 4:
            salary = 11.20;
            break;
        case 5:
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
}