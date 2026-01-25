#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;  // 数据类型为int

typedef struct node {
    ElemType data;
    struct node* next;
} Node;

Node* init_list(void);                                      // 初始化链表
void head_insert(Node* list, ElemType data);            // 头节点插入
bool given_insert(Node* list, int pos, ElemType data);  // 指定节点插入
Node* get_tail_node(Node* list);                        // 获取尾节点
Node* tail_insert(Node* tail_node,
                  ElemType data);    // 尾节点插入并返回新的尾节点
bool del_node(Node* list, int pos);  // 删除指定节点
void print(Node* node);              // 遍历输出链表
int listlen(Node* list);             // 获取链表长度
void free_list(Node* list);          // 释放链表

int main() {
    Node* list_1 = init_list();
    head_insert(list_1, 30);
    head_insert(list_1, 10);
    if (given_insert(list_1, 2, 20) == false) {
        return 1;
    }
    if (given_insert(list_1, 2, 20) == false) {
        return 1;
    }
    if (del_node(list_1, 3) == false) {
        return 1;
    }
    Node* tail = get_tail_node(list_1);
    tail = tail_insert(tail, 40);
    tail = tail_insert(tail, 50);
    print(list_1);
    printf("链表长度为%d\n", listlen(list_1));
    free_list(list_1);
    printf("释放链表后长度为%d\n", listlen(list_1));
    return 0;
}

Node* init_list(void) {
    Node* head_node = (Node*)malloc(sizeof(Node));
    head_node->data = 0;
    head_node->next = NULL;
    return head_node;
}

void head_insert(Node* list, ElemType data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->next;
    list->next = new_node;
}

bool given_insert(Node* list, int pos, ElemType data) {
    Node* next_node = list;
    for (int i = 0; i < pos - 1; i++) {
        next_node = next_node->next;
        if (next_node == NULL) {
            printf("插入节点不存在\n");
            return false;
        }
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = next_node->next;
    next_node->next = new_node;
    return true;
}

Node* get_tail_node(Node* list) {
    Node* next_node = list;
    while (next_node->next != NULL) {
        next_node = next_node->next;
    }
    return next_node;
}

Node* tail_insert(Node* tail_node, ElemType data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    tail_node->next = new_node;
    return new_node;
}

bool del_node(Node* list, int pos) {
    if (pos < 0) {
        printf("删除节点不存在\n");
        return false;
    }
    if (pos == 0) {
        printf("尝试删除头节点\n");
        return false;
    }
    Node* next_node = list;
    for (int i = 0; i < pos - 1; i++) {
        next_node = next_node->next;
        if (next_node->next == NULL) {
            printf("删除节点不存在\n");
            return false;
        }
    }
    Node* del_node = next_node->next;
    next_node->next = del_node->next;
    free(del_node);
    return true;
}

void print(Node* node) {
    Node* next_node = node->next;
    while (next_node != NULL) {
        printf("%d  ", next_node->data);
        next_node = next_node->next;
    }
    printf("\n");
}

int listlen(Node* list) {
    int len = 0;
    Node* next_node = list->next;
    while (next_node != NULL) {
        next_node = next_node->next;
        len++;
    }
    return len;
}

void free_list(Node* list) {
    for (int i = 0; i < listlen(list); i++) {
        del_node(list, 1);
    }
    list->next = NULL;
}