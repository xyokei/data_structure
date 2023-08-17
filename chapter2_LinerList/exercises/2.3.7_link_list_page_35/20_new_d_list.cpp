//
// Created by AutumnSigni on 2023/8/17.
//

//新结构 双向链表多一个freq域，直接在工具里改吧
#include "liner_list_util.h"


void sort_list_freq(DoubleList &list, DoubleNode *p) {
    DoubleNode *q = list;
    while (q->next != nullptr && q->next->freq > p->freq) {
        q = q->next;
    }
    //后插结点
    if (q->next!= nullptr)
        q->next->prior=p;
    p->prior = q;
    p->next = q->next;
    q->next = p;
}

//要求：每调用一次locate freq + 1;
//很符合 操作系统内存管理 快表的算法，用的多往前放
void locate(DoubleList &list, int x) {
    DoubleNode *p = list->next;
    while (p) {
        if (p->data == x) {
            p->freq++;
            //断结点

            p->prior->next = p->next;
            if (p->next != nullptr)
                p->next->prior = p->prior;
            p->next = nullptr;
            p->prior = nullptr;
            sort_list_freq(list, p);
            break;
        }
        p = p->next;
    }
}

void printList(DoubleList list, bool freq) {
    DoubleNode *p = list->next;
    if (isEmpty(list)) {
        cout << "空表" << endl;
        return;
    }
    int i = 0;
    cout << "双链表：" << endl << "[";
    while (p != nullptr) {
        if (i != 0 && i % 7 == 0) cout << endl << ' ';
        cout << p->data << ":" << p->freq << "," << '\t';
        p = p->next;
        i++;
        //判断p是不是最后一个节点
        //p == nullptr 是当表只有一个节点
        //p ->next ==  nullptr 是当表大于1个节点时，p为最后一个节点
        if (p == nullptr || p->next == nullptr) {
            break;
        }
    }
    cout << p->data << ":" << p->freq << "]" << endl;
}

int main() {
    DoubleList list;
    int *arr = random(6, 9);
    printArr(arr,6);
    // headCreateListAfter(list, arr, 6);  //实在搞不清哪里错了，debug是对的，但是一运行就错，烦死了
    headCreateListPre(list, arr, 6);
    printList(list, true);

    locate(list, 2);
    locate(list, 2);
    locate(list, 2);
    locate(list, 7);
    locate(list, 4);
    locate(list, 6);
    locate(list, 5);

    printList(list, true);

}
