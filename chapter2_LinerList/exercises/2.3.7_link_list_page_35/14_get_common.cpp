//
// Created by AutumnSigni on 2023/8/17.
//

//用两个单链表中共同元素构建一个新链表
#include "liner_list_util.h"
#include "chrono"
#include "thread"
#include "algorithm"

/**
 * 有个问题，没有去重复
 * @param list1
 * @param list2
 * @param list3
 */
void get_common(SingleList list1, SingleList list2, SingleList &list3) {

    SingleNode *node;
    SingleNode *p, *q, *r;
    p = list1->next;
    q = list2->next;
    r = list3;

    while (p && q) {
        if (p->data < q->data) {
            p = p->next;
        } else if (p->data > q->data) {
            q = q->next;
        } else {
            node = (SingleNode *) malloc(sizeof(SingleList));
            node->data = q->data;

            //尾插
            node->next = r->next;
            r->next = node;
            r = node; //别忘了更新尾

            p = p->next;
            q = q->next;
        }
    }

}


int main() {
    SingleList list1, list2,list3;
    initList(list3);
    int *arr = random(6, 9);
    sort(arr,arr+6);
    headCreateListAfter(list1, arr, 6);

    this_thread::sleep_until(chrono::system_clock::now() + 1s);

    int *arr1 = random(8,  10);
    sort(arr1,arr1+8);
    headCreateListAfter(list2, arr1, 8);

    printList(list1);
    printList(list2);
    // merge_sort(list1, list2);
    get_common(list1, list2,list3);


    printList(list3);

}