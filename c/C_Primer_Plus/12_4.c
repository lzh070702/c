#include <stdio.h>
int  func(void){
    static int i = 0;
    return ++i;
}

int main() {
    int n,res;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        res=func();
    }
    printf("函数被调用的次数：%d\n",res);
    return 0;
}