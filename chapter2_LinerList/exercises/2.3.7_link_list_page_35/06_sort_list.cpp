//
// Created by AutumnSigni on 2023/8/17.
//

//头结点单链表 升序排

#include "liner_list_util.h"

/**
 * 思想
 * 遍历 旧表
 *      遍历新表
 *          若 new data > old data
 *                后插法
 *                交换data
 *      若没有发生插入，直接查到最后面
 *时间 O(n^2)
 * @param list
 */
void sort_list(SingleList &list) {
    if (list->next == nullptr || list->next->next == nullptr)
        return;
    SingleNode *p, *next, *q, *pre;
    p = list->next->next;
    list->next->next = nullptr;
    q = list->next;
    while (p) {
        next = p->next;
        while (q) {
            if (q->data > p->data) { //后插交换数据
                p->next = q->next;
                q->next = p;

                int temp = p->data;
                q->data = p->data;
                p->data = temp;
                break;
            }
            pre = q;
            q = q->next; // 若没发生插入时候，p会指向最后一个结点
        }
        if (q == nullptr) { //单独处理最后一个结点
            p->next = pre->next;
            pre->next = p;
        }
        p = next;
        q = list->next; //漏了这一句，debug查出来的，不重置q的话，q永远是交换前的一个
    }
}

/**
 * 思想是一样的
 * 直接插入排序
 * 我的写的，还是答案的优雅
 * @param list
 */
void sort_list_answer(SingleList &list) {
    SingleNode *p, *pre, *r;

    p = list->next->next;
    list->next->next = nullptr;

    while (p){
        r = p->next;

        pre = list;
        while (pre->next && pre->next->data <p->data) //若pre.next 是空的话
            pre =pre->next;
        p->next = pre->next;                   //这儿是不是有问题， ...没问题，因为上个pre已经判断最后一个结点小于p的值
        pre->next =p;                          //真妙 啊

        p = r;
    }
}


int main() {
    SingleList list;
    int *arr = random(6, 10);
    headCreateListAfter(list, arr, 6);

    printList(list);
    // sort_list(list);
    sort_list_answer(list);
    printList(list);

}