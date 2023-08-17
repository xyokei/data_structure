//
// Created by AutumnSigni on 2023/8/17.
//

//链接两个循环单链表
#include "liner_list_util.h"
#include "chrono"
#include "thread"

void link_list(CircleList &list1,CircleList list2){
    CircleNode *p,*q;
    p = list1->next;
    q = list2->next;
    while (p->next!=list1){
        p = p->next;
    }
    while (q->next!=list2){
        q = q->next;
    }
    p->next=list2->next;
    q->next = list1;
}

int main(){
    CircleList list1,list2;
    int *arr = random(6, 9);
    headCreateListAfter(list1, arr, 6);

    this_thread::sleep_until(chrono::system_clock::now() + 1s);

    int *arr1 = random(8,  10);

    headCreateListAfter(list2, arr1, 8);
    printList(list1);
    printList(list2);

    link_list(list1,list2);
    printList(list1);


}