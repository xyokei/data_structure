//
// Created by AutumnSigni on 2023/8/17.
//

// 两个增序的单链表，归并成一个，且降序
#include "liner_list_util.h"
#include "chrono"
#include "thread"
#include "algorithm"

/**
 * 时间复杂度不行
 * @param list1
 * @param list2
 */
void merge_sort(SingleList &list1, SingleList list2) {
    if (list2->next == nullptr) return;
    if (list1->next == nullptr) {
        list1 = list2;
        return;
    }
    SingleNode *head, *p, *q, *pre, *next;
    p = list1->next;  //这个要放在前面，下面list变了 注意注意
    q = list2->next;

    head = list1;
    head->next = nullptr;


    //增序排列  O(n^2)
    while (p) {
        next = p->next;
        pre = head;
        while (pre->next != nullptr && pre->next->data > p->data)
            pre = pre->next;

        p->next = pre->next;
        pre->next = p;

        p = next;
    }
    //增序排列  O(n^2)
    while (q) {
        next = q->next;
        pre = head;
        while (pre->next != nullptr && pre->next->data > q->data)
            pre = pre->next;

        q->next = pre->next;
        pre->next = q;
        q = next;
    }
}

void merge_sort_answer(SingleList &list1, SingleList list2) {
    if (list2->next == nullptr) return;
    if (list1->next == nullptr) {
        list1 = list2;
        return;
    }
    SingleNode *head, *p, *q, *nextp, *nextq;
    p = list1->next;  //这个要放在前面，下面list变了 注意注意
    q = list2->next;

    head = list1;
    head->next = nullptr;
    while (p && q) {
        nextp = p->next;
        nextq = q->next;
        if (p->data <= q->data) { //写反了？小的数据先插入,还真是，总是把小的进行头插，之前写错了，写成>
            // 头插法
            p->next = head->next;
            head->next = p;

            p = nextp;
        } else {
            // 头插法
            q->next = head->next;
            head->next = q;

            q = nextq;
        }
    }
    if (q) {
        // nextq = q->next;
        // q->next = head->next;
        // head->next = q;
        p = q; //这个太妙了吧
    }
    while (p) {
        nextp = p->next;
        p->next = head->next;
        head->next = p;
        p = nextp;
    }

}

int main() {
    SingleList list1, list2;
    int *arr = random(6, 9);
    sort(arr,arr+6);
    headCreateListAfter(list1, arr, 6);

    this_thread::sleep_until(chrono::system_clock::now() + 1s);

    int *arr1 = random(8, 10, 20);
    sort(arr1,arr1+8);
    headCreateListAfter(list2, arr1, 8);

    printList(list1);
    printList(list2);
    // merge_sort(list1, list2);
     merge_sort_answer(list1, list2);


    printList(list1);

}