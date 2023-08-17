//
// Created by AutumnSigni on 2023/8/17.
//

// 将 a1 b1 a2 b2 .... an bn,拆成a1,a2,a3...  b1 b2 b3

//跟上一题一样啊，不写了;
//算了，这次不用 i来控制奇偶

#include "liner_list_util.h"

void split_odd_even(SingleList list,SingleList &odd,SingleList &even){
    SingleNode *q,*p =list->next;
    SingleNode *next;
    SingleNode *r=odd,*s=even;
    while (p){
        q = p->next; //偶结点

        //奇结点处理
        p->next = r->next;
        r->next =p;
        r = p;
        //偶结点为空，说明总数是奇数，结束循环
        if (q == nullptr){ //这个之前写p.next =null 是不行的，因为在处理p的时候，p.next已经被破坏了
            break;
        }

        // 非空，处理当前偶结点
        if (q->next!= nullptr)
           next =q->next;
        q->next = s->next;
        s->next =q;
        s =q;

        //一次性处理2个结点，跳2次
        p = next;
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