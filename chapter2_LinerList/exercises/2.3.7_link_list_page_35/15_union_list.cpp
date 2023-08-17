//
// Created by AutumnSigni on 2023/8/17.
//

//求两个表交集 ，解法和上一题类似
#include "liner_list_util.h"
#include "chrono"
#include "thread"
#include "algorithm"

/**
 * 我写的比答案好
 * @param list1
 * @param list2
 */
void union_list(SingleList &list1,SingleList list2){
    SingleNode *p, *q, *r,*head,*next;
    p = list1->next;
    q = list2->next;
    head = list1;
    head->next = nullptr;
    r = head;

    while (p && q) {
        if (p->data < q->data) {
            p = p->next;
        } else if (p->data > q->data) {
            q = q->next;
        } else {
            //尾插
            if(p->data == r->data){ //去重
                p = p->next;
                q = q->next;
                continue;
            }
            next = p->next;
            p->next = r->next;
            r->next = p;
            r = p ;

            p = next;
            q = q->next; //为了去重删掉这句 ,测过了，不行
        }
    }
}

int main() {
    SingleList list1, list2,list3;
    initList(list3);
    int *arr = random(6, 9);
    sort(arr,arr+6);
    int ar[] =  {2,2,4,6,6,6};
    headCreateListAfter(list1, arr, 6);

    this_thread::sleep_until(chrono::system_clock::now() + 1s);

    int *arr1 = random(8,  10);

    sort(arr1,arr1+8);
    int ar1[] = {3,6,6,7,7,8,9,10};
    headCreateListAfter(list2, arr1, 8);

    printList(list1);
    printList(list2);
    // merge_sort(list1, list2);
    union_list(list1, list2);


    printList(list1);

}
