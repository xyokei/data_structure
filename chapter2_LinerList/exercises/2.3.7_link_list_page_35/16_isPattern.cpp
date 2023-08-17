//
// Created by AutumnSigni on 2023/8/17.
//

//判断链表是否是另一个的字串
#include "liner_list_util.h"
#include "chrono"
#include "thread"
#include "algorithm"


/**
 * 直接暴力解
 * @param list1
 * @param list2
 * return bool
 */
bool isPattern(SingleList list1, SingleList list2) {
    SingleNode *p, *q, *next;
    p = list1->next;
    while (p) {
        next = p->next;
        q = list2->next; //重置 q
        while (q) {
            if (q->data != p->data) {
                break;
            }
            q = q->next;
            p = p->next;
        }
        if (q == nullptr) return true;
        p = next;
    }
    return false;
}

int main() {
    SingleList list1, list2, list3;
    initList(list3);
    int ar[] = {6, 6, 7};
    headCreateListAfter(list1, ar, 3);

    int ar1[] = {3, 6, 6, 7, 7, 8, 9, 10};
    headCreateListAfter(list2, ar1, 8);

    printList(list1);
    printList(list2);
    // merge_sort(list1, list2);
    cout << "是否子串：" << boolalpha << isPattern(list2, list1) << endl;


}
