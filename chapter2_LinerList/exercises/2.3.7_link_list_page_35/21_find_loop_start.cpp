//
// Created by AutumnSigni on 2023/8/18.
//

//若单链表有环，找出环的起始位置
#include "liner_list_util.h"

/**
 * 不会，直接看答案的
 * 说实话，答案也难看懂
 * @param list
 * @return
 */
SingleNode* find_loop_start(SingleList list){
    SingleNode *fast,*slow;
    fast = list->next;
    slow = list->next;
    while (fast->next!= nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (fast->next == nullptr) return nullptr;
    SingleNode *p  = list;
    SingleNode *q  = slow;
    while (p!=q){
        p = p->next;
        q = q->next;
    }
    return p;
}

