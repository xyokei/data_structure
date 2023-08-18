//
// Created by AutumnSigni on 2023/8/18.
//

//头结点单链表
// 找中点，中点以后的放偶数位，之前的放奇数位置
// 可以参考第10题分割奇偶

#include "liner_list_util.h"

/**
 * 和答案思路一样，实现稍有不同
 * 找中间节点，用 p,q，p走一次，q走两次，q到链尾，p为中间节点
 * 答案写的真简洁啊，极简写法
 * @param list
 */
void change_list(SingleList list) {
    int len = getLength(list);
    int mid = len / 2; //偶数为前，奇数是中间
    SingleNode *midpre, *midp, *list1, *list2, *p, *q, *next, *nextMid, *rear;
    //跳到中间结点
    midp = list->next; //p已经是第一个结点了，下面应该从1开始
    for (int i = 0; i < mid; ++i) {//跳到中间结点前一个结点 1 2 3 4 会指向2 ，1 2 3 4 5 会指向 3
        midp = midp->next;
    }
    // 偏移
    midpre = midp;
    midp = midp->next;
    midpre->next = nullptr;// 构造list1

    // 用中间结点构造倒序序列的链表 构造list2
    list2 = (SingleNode*)malloc(sizeof(SingleList));
    list2->next = nullptr;
    while (midp) {
        nextMid = midp->next;
        //头插 逆置
        midp->next =list2->next;
        list2->next = midp;
        midp = nextMid;
    }
    list1 = list;
    // 初始化变量
    p = list1->next; //若链表长度是奇数 p 比 q 长 q会先空
    q = list2->next; //若为偶数 两个长度相同
    list->next = nullptr;
    rear = list;
    while (p && q) {
        // 保护下一个指针
        next = p->next;
        nextMid = q->next;

        // 尾插 ,先插p 在插q
        p->next = q;
        q->next = rear->next;
        rear->next = p;
        rear = q;
        // 置换
        p = next;
        q = nextMid;
    }
    if (p) {
        rear->next = p;
    }
}

void change_list_answer(SingleList list){
    SingleNode *p,*q,*r,*s;
    p  = q=list;
    //找中间节点
    while (q->next){
        p = p->next;
        q = q->next;
        if (q->next){ //走第二步
            q =q->next;
        }
    }
    q = p->next;
    p->next = nullptr;
    while (q){
        r = q->next;//保护next
        // 头插 逆置
        q->next =p->next;
        p->next=q;
        q =r;
    }

    s =list->next; //前半段首结点
    q =p->next; //后半段首结点
    p->next = nullptr;
    while (q){
        r = q->next;

        q->next =s->next; //q插到s s.next之间
        s->next=q;
        s=q->next;        //更新s,这里的写法就是为什么这么简洁的原因，我的太白了

        q =r;
    }
}

int main() {
    SingleList list;
    int *arr = random(7, 10);
    headCreateListAfter(list, arr, 6);
    printList(list);
    change_list(list);
    printList(list);
}
