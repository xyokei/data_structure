//
// Created by AutumnSigni on 2023/8/17.
//

//分割一个带头结点的单链表，按位序奇偶分
#include "liner_list_util.h"

void split_odd_even(SingleList list,SingleList &odd,SingleList &even){
    SingleNode *p =list->next;
    int i = 1;
    SingleNode *q,*s,*next;
    q = odd;
    s = even;
    while (p){
        next = p->next;
        if (i%2!=0){    //奇
            //后插
            p->next = q->next; //漏了这句，新表最后一个结点要置空
            q->next=p;
            q = p;
        } else{
            //后插
            s->next =p;
            s = p;
            s->next = nullptr;  //漏了这句，新表最后一个结点要置空
        }
        p = next;
        i++;
    }
}

int main(){
    SingleList list,odd,even;
    initList(odd);
    initList(even);
    int *arr = random(9,10);
    headCreateListAfter(list,arr,9);
    printList(list);
    split_odd_even(list,odd,even);

    printList(odd);
    printList(even);
}