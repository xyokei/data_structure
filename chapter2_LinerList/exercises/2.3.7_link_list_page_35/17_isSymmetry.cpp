//
// Created by AutumnSigni on 2023/8/17.
//

//判断一个循环双链表是否对称

#include "liner_list_util.h"

bool isSymmetry(CircleDList list){
    CircleDNode *p,*q;
    p = list->next;
    q = list->prior;
    while (p->next!=q && p!=q){ // 双链表的循环跳出条件，第一遍写错了
        if (p->data!=q->data)
            return false;
        p = p->next;
        q = q->prior;
    }
    // if (p->data ==q->data) return true; //在这里判断
    return true; //直接返回就行了啊~？
}

int main() {
    CircleDList list;
    int *arr = random(3, 5);
    int ar[]={8,7,7,8};
    headCreateListAfter(list, ar, 4);
    printList(list);
    cout<<"是否对称："<<boolalpha<<isSymmetry(list)<<endl;
}