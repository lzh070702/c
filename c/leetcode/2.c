#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} Node;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
void add(struct ListNode* l1, struct ListNode* l2);
struct ListNode* init_list(void);
void head_insert(Node* node, int data);
void print(Node* node);

int main() {
    Node* l1 = init_list();
    Node* l2 = init_list();
    Node* l3 = init_list();
    head_insert(l1, 3);
    head_insert(l1, 4);
    head_insert(l1, 2);
    head_insert(l2, 4);
    head_insert(l2, 6);
    head_insert(l2, 5);
    l3 = addTwoNumbers(l1->next, l2->next);
    print(l3);
    return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    add(l1, l2);
    return l1;
}
void add(struct ListNode* l1, struct ListNode* l2) {
    while (l1 || l2) {
        l1->val += l2->val;
        if (l1->val >= 10) {
            if (l1->next) {
                l1->next->val++;
            } else {
                struct ListNode* node =
                    (struct ListNode*)malloc(sizeof(struct ListNode));
                node->next = NULL;
                node->val = 1;
                l1->next = node;
            }
        }
        l1->val %= 10;
        if ((!l1->next && l2->next) || (l1->next && !l2->next)) {
            if (!l1->next) {
                struct ListNode* node1 =
                    (struct ListNode*)malloc(sizeof(struct ListNode));
                node1->next = NULL;
                node1->val = 0;
                l1->next = node1;
            }
            if (!l2->next) {
                struct ListNode* node2 =
                    (struct ListNode*)malloc(sizeof(struct ListNode));
                node2->next = NULL;
                node2->val = 0;
                l2->next = node2;
            }
        }
        l1 = l1->next;
        l2 = l2->next;
    }
}

struct ListNode* init_list(void) {
    Node* head = (Node*)malloc(sizeof(Node));
    head->val = 0;
    head->next = NULL;
    return head;
}

void head_insert(Node* node, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->val = data;
    new_node->next = node->next;
    node->next = new_node;
}

void print(Node* node) {
    Node* next_node = node->next;
    while (next_node != NULL) {
        printf("%d", next_node->val);
        next_node = next_node->next;
    }
    printf("\n");
}