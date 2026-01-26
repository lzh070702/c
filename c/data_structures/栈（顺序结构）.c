#include <stdbool.h>
#include <stdio.h>

#define MAXSIZE 100

typedef int ElemType;  // 数据类型为int

typedef struct stack {
    ElemType data[MAXSIZE];
    int top;
} STACK;

void init_stack(STACK* s);            // 初始化栈
bool is_empty(STACK* s);              // 判断是否为空
bool push(STACK* s, ElemType e);      // 压栈
bool pop(STACK* s, ElemType* e);      // 出栈
bool get_top(STACK* s, ElemType* e);  // 获取栈顶元素

int main() {
    STACK s1;
    init_stack(&s1);
    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);
    push(&s1, 40);
    ElemType e;
    pop(&s1, &e);
    printf("%d\n", e);
    get_top(&s1, &e);
    printf("%d\n", e);
    return 0;
}

void init_stack(STACK* s) {
    s->top = -1;
}

bool is_empty(STACK* s) {
    if (s->top == -1) {
        printf("当前栈内为空\n");
        return true;
    }
    return false;
}

bool push(STACK* s, ElemType e) {
    if (s->top == MAXSIZE - 1) {
        printf("当前栈内为满\n");
        return false;
    }
    s->data[++s->top] = e;
    return true;
}

bool pop(STACK* s, ElemType* e) {
    if (s->top == -1) {
        printf("当前栈内为空\n");
        return false;
    }
    *e = s->data[s->top--];
    return true;
}

bool get_top(STACK* s, ElemType* e) {
    if (s->top == -1) {
        printf("当前栈内为空\n");
        return false;
    }
    *e = s->data[s->top];
    return true;
}