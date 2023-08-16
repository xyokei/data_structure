//
// Created by AutumnSigni on 2023/8/17.
//

//删除最小值 最小值唯一

#include "liner_list_util.h"

// 时间O(n)
void delete_min_value(SingleList &list) {
    SingleNode *pre, *p, *min, *preMin;
    min = p = list->next;
    pre = preMin = list;
    while (p) {
        if (p->data < min->data) {
            min = p;
            preMin = pre;
        }
        p = p->next;
        pre = pre->next;
    }

    preMin->next=min->next;
    free(min);
}

int main(){
    SingleList list;
    int *arr = random(6,-10,10);
    headCreateListAfter(list,arr,6);
    printList(list);
    delete_min_value(list);
    printList(list);

}