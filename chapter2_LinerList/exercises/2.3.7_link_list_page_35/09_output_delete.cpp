//
// Created by AutumnSigni on 2023/8/17.
//

//头结点单链表，增序输出，并删除节点
#include "liner_list_util.h"

/**
 * 先变降序，然后输出一个删一个
 * @param list
 */
void output_delete(SingleList &list){
    cout<<"顺序输出："<<endl;
    if (list->next== nullptr){
        return;
    }
    if (list->next->next== nullptr){
        cout<<list->data;
    }

    SingleNode *head,*p,*next,*pre;
    p =list->next->next;
    head =list->next;
    head->next = nullptr;  //新链表只有一个结点

    //排序 参见第6题
    while(p){
        next = p->next;

        pre = head;
        while (pre->next!= nullptr && pre->next->data<p->data)
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;

        p = next;
    }

    //输出并删除
    p = head->next;
    while (p){
        next  = p->next;
        cout<<p->data<<" ";
        free(p);
        p = next;
    }
    free(list);
}


int main(){
    SingleList list;
    int *arr = random(6, 10);
    headCreateListAfter(list, arr, 6);

    printList(list);
    output_delete(list);
    cout<<endl<<list->next->data<<endl;
}