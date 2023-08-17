//
// Created by AutumnSigni on 2023/8/17.
//
//删除带头结点链表中 值在s t 之间的节点

#include "liner_list_util.h"

/**
 * 时间 O(n)
 * 空间 O(1)
 * @param list
 * @param s
 * @param t
 */
void delete_s_t(SingleList &list, int s, int t) {
    SingleNode *pre, *p, *next;
    pre = list;
    p = list->next;

    while (p) {
        next = p->next;
        if (p->data >= s && p->data <= t) {
            pre->next = next;
            free(p);
            p = next;     //这漏了
        } else {
            pre = p;
            p = next;
        }

    }
}

int main() {
    SingleList list;
    int *arr = random(6, 10);
    headCreateListAfter(list, arr, 6);
    printList(list);
    delete_s_t(list, 3, 6);
    printList(list);
}
