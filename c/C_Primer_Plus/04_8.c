#include <stdio.h>

const double gal_L = 3.785;
const double mi_km = 1.609;

int main() {
    double mi, gal;
    printf("请输入旅行的里程：");
    scanf("%lf", &mi);
    printf("请输入消耗的汽油量：");
    scanf("%lf", &gal);
    double USA = mi / gal;
    double Eur = gal * gal_L / mi * mi_km * 100;
    printf("消耗单位燃料的行程（美国方案：mi/gal）:%.1f\n", USA);
    printf("单位距离消耗的燃料（欧洲方案：L/100km）:%.1f\n", Eur);
    return 0;
}