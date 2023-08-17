//
// Created by AutumnSigni on 2023/8/17.
//

//给定2个单链表 找公共结点
#include "liner_list_util.h"
#include "chrono"
#include "thread"

/**
 * 答案写法
 * @param list1
 * @param list2
 * @return
 */
SingleNode *find_share_node_answer(SingleList list1, SingleList list2) {
    if (!list1->next && !list2->next) return nullptr;

    SingleNode *p, *q;
    p = list1->next;
    q = list2->next;
    int len1 = getLength(list1);
    int len2 = getLength(list2);
    if (len1 < len2) {
        for (int i = 0; i < len2 - len1; ++i) {
            q = q->next;
        }
    }
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; ++i) {
            p = p->next;
        }
    }

    while (p && q) {
        if (p == q) return p;
        p = p->next;
        q = q->next;
    }
    return nullptr;
}

/**
 * 递归做法
 * 测过了， 不行，因为递归到最后一层时，回到上一层有个链表指针会回退，而另一个不动 gg
 * @param list1
 * @param list2
 * @param p
 */
void find_share_node(SingleList list1, SingleList list2, SingleNode *p) {
    if (list1->next != nullptr && list2->next != nullptr) {
        find_share_node(list1->next, list2->next, p);
    }
    if (list1->next == nullptr && list2->next != nullptr) {
        find_share_node(list1, list2->next, p);
    }
    if (list1->next != nullptr && list2->next == nullptr) {
        find_share_node(list1->next, list2, p);
    }
    if (list1->next == nullptr && list2->next == nullptr) return;
    if (list1 == list2) {
        p = list1;
    }
}

int main() {
    SingleList list1, list2;
    int *arr = random(6, 9);
    headCreateListAfter(list1,arr,6);

    this_thread::sleep_until(chrono::system_clock::now() + 1s);

    int *arr1 = random(8, 10,20);
    headCreateListAfter(list2,arr1,8);
    //设定公共结点
    SingleNode *q= getElem(list1,4); //
    SingleNode *t= getElem(list2,3);
    q->next =t;

    printList(list1);
    printList(list2);

    SingleNode *p =find_share_node_answer(list1,list2);
    // SingleNode *p;
    // find_share_node(list1,list2,p);

    cout<<"共同结点后续值："<<endl;
    while (p){
        cout<<p->data<<" ";
        p=p->next;
    }
}