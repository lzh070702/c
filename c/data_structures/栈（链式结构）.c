#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;  // 数据类型为int

typedef struct stack {
    ElemType data;
    struct stack* next;
} STACK;

STACK* init_STACK(void);              // 初始化栈
bool is_empty(STACK* s);              // 判断是否为空
void push(STACK* s, ElemType e);      // 压栈
bool pop(STACK* s, ElemType* e);      // 出栈
bool get_top(STACK* s, ElemType* e);  // 获取栈顶元素

int main() {
    STACK* s = init_STACK();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    ElemType e;
    pop(s, &e);
    printf("%d\n", e);
    get_top(s, &e);
    printf("%d\n", e);
    return 0;
}

STACK* init_STACK(void) {
    STACK* s = (STACK*)malloc(sizeof(STACK));
    s->data = 0;
    s->next = NULL;
    return s;
}

bool is_empty(STACK* s) {
    if (s->next == NULL) {
        printf("当前栈内为空\n");
        return true;
    }
    return false;
}

void push(STACK* s, ElemType e) {
    STACK* p = (STACK*)malloc(sizeof(STACK));
    p->data = e;
    p->next = s->next;
    s->next = p;
}

bool pop(STACK* s, ElemType* e) {
    if (is_empty(s)) {
        return false;
    }
    STACK* next = s->next;
    *e = next->data;
    s->next = next->next;
    free(next);
    return true;
}

bool get_top(STACK* s, ElemType* e) {
    if (is_empty(s)) {
        return false;
    }
    *e = s->next->data;
    return true;
}