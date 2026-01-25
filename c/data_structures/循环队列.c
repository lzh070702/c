#include <stdbool.h>
#include <stdio.h>

#define MAXSIZE 5

typedef int ElemType;  // 数据类型为int

typedef struct queue {
    ElemType data[MAXSIZE];
    int front;
    int rear;
} QUEUE;

void init_queue(QUEUE* q);             // 初始化队列
bool is_empty(QUEUE* q);               // 判断是否为空
bool push(QUEUE* q, ElemType e);       // 入队
bool pop(QUEUE* q, ElemType* e);       // 出队
bool get_head(QUEUE* q, ElemType* e);  // 获取队头元素

int main() {
    QUEUE q;
    init_queue(&q);
    push(&q, 10);
    push(&q, 20);
    push(&q, 30);
    push(&q, 40);
    ElemType e;
    pop(&q, &e);
    printf("%d\n", e);
    get_head(&q, &e);
    printf("%d\n", e);
    return 0;
}

void init_queue(QUEUE* q) {
    q->front = 0;
    q->rear = 0;
}

bool is_empty(QUEUE* q) {
    if (q->front == q->rear) {
        printf("当前队列为空\n");
        return true;
    }
    return false;
}

bool push(QUEUE* q, ElemType e) {
    if (q->rear - q->front == MAXSIZE) {
        printf("当前队列为满\n");
        return false;
    }
    q->data[q->rear % MAXSIZE] = e;
    q->rear++;
    return true;
}

bool pop(QUEUE* q, ElemType* e) {
    if (q->front == q->rear) {
        printf("当前队列为空\n");
        return false;
    }
    *e = q->data[q->front % MAXSIZE];
    q->front++;
    return true;
}

bool get_head(QUEUE* q, ElemType* e){
    if (q->front == q->rear) {
        printf("当前队列为空\n");
        return false;
    }
    *e = q->data[q->front % MAXSIZE];
    return true;
}