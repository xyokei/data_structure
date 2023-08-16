//
// Created by AutumnSigni on 2023/8/17.
//
// 就地逆置，时间O(1)

#include "liner_list_util.h"


void insertBefore(SingleNode *p, SingleNode *q) {
    q->next = p->next;
    p->next = q;
}

void reverse_list(SingleList &list) {
    SingleNode *p, *next;
    p = list->next;
    list->next = nullptr;
    while (p) {
        next = p->next; //保护next 指针 ，不加的话链表就断了
        // insertBefore(list, p);
        p->next = list->next;
        list->next = p;

        p = next;
    }
}

int main() {
    SingleList list;
    int *arr = random(6, 10);
    headCreateListAfter(list, arr, 6);
    printList(list);
    reverse_list(list);
    printList(list);
}