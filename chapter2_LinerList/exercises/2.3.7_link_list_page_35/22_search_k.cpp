//
// Created by AutumnSigni on 2023/8/18.
//


//查找带头 结点的单链表 倒数第k个位置

#include "liner_list_util.h"

int search_k(SingleList list, int k) {

    SingleNode *p = list->next;
    int len = getLength(list);
    int n = len - k + 1;
    if (n<=0){
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        p = p->next;
    }
    if (p != nullptr) {
        cout << "倒数第" << k << "个节点值：" << p->data << endl;
        return 1;
    }
    return 0;
}

int main() {
    SingleList list;
    int *arr = random(10, 10);

    headCreateListAfter(list, arr, 10);
    printList(list);
    search_k(list, 10);


}