//
// Created by AutumnSigni on 2023/8/17.
//


#include "liner_list_util.h"
#include "algorithm"

void delete_x(NoHeadLinkList list,int x){
    if (list == nullptr) return;
    NoHeadNode *pre,*p,*next;
    pre =list;
    p = list->next;
    if (pre->data == x) pre = pre->next;
    while (p){
        next = p->next;
        if (p->data == x){
            pre->next = next;
            free(p);
            p = next;
        }else{
            pre = p;
            p = next;
        }
    }
}

int main(){
    NoHeadLinkList list;
    int *arr = random(6, 0, 9);
    headCreateListAfter(list, arr, 6);

    printList(list);

    delete_x(list,1);
    printList(list);
}