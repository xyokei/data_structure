//
// Created by AutumnSigni on 2023/8/17.
//

// 升序单链表 去掉相同数值元素
#include "liner_list_util.h"
#include <algorithm>

void delete_same(SingleList &list) {
    if (list->next == nullptr || list->next->next == nullptr) return;
    SingleNode *pre, *p, *next;
    pre = list->next;
    p = list->next->next;
    while (p) {
        next = p->next;
        if (p->data == pre->data) {
            pre->next = p->next;
            free(p);
            p = next;  //总是忘记这个
        }
        else{
            pre = p;   // 忘记
            p = next;
        }

    }
}

int main() {
    SingleList list;
    int *arr = random(6, 10);
    sort(arr, arr + 6);
    headCreateListAfter(list, arr, 6);

    printList(list);
    delete_same(list);
    printList(list);
}