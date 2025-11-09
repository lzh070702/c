#include <stdio.h>

void func1(){
    printf("你选择了功能一\n");
}

void func2() {
    printf("你选择了功能二\n");
}

void func3() {
    printf("你选择了功能三\n");
}

int main() {
    typedef void (*arr)();
    arr func_arr[3] = {func1, func2, func3};
    printf("==菜单==\n");
    printf("a.功能一\n");
    printf("b.功能二\n");
    printf("c.功能三\n");
    printf("q.退出\n");
    while(1){
        printf("选择模式：");
        char choice = getchar();
        getchar();
        switch (choice) {
            case 'a':
                func_arr[0]();
                break;
            case 'b':
                func_arr[1]();
                break;
            case 'c':
                func_arr[2]();
                break;
            case 'q':
                return 0;
            default:
                printf("输入错误，请重新");
                break;
        }
    }
    return 0;
}