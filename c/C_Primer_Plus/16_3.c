#include <math.h>
#include <stdio.h>
#define Pi 3.1415926

typedef struct polar {
    double r;
    double A;
} Po;

typedef struct rectangular {
    double x;
    double y;
} Re;

Re func(Po* po) {
    Re re;
    double rad = po->A * Pi / 180.0;
    re.x = po->r * cos(rad);
    re.y = po->r * sin(rad);
    return re;
}

int main() {
    Po po;
    scanf("%lf %lf", &po.r, &po.A);
    printf("在极坐标系中,当 r = %lf , A = %lf 时,\n", po.r, po.A);
    printf("在直角坐标系中 x = %lf , y = %lf\n", func(&po).x, func(&po).y);
    return 0;
}