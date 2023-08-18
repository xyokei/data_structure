//
// Created by AutumnSigni on 2023/8/18.
//

//带头结点的单链表 删除绝对值相等的结点 类似第12题

#include "liner_list_util.h"

/**
 * 哈希算法 破一切
 * 时间O（n）
 * @param list
 */
void delete_equal_abs(SingleList &list, int n) {
    int arr[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = 0;
    }

    SingleNode *p, *pre;
    p = list->next;
    pre = list;
    while (p) {
        if (arr[abs(p->data)] == 0) {
            arr[abs(p->data)]++;
            pre = p;
            p = p->next;
        } else {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
    }
}

int main() {
    SingleList list;
    int *arr = random(14, -10, 10);

    headCreateListAfter(list, arr, 14);
    printList(list);
    delete_equal_abs(list, 10);
    printList(list);

}