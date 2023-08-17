//
// Created by AutumnSigni on 2023/8/17.
//

//反复输出循环单链表的最小值 并删除结点，参照 09 题
#include "liner_list_util.h"

void min_output_delete(CircleList list) {
    //第一二个结点的判断不写了

    CircleNode *minPre, *minP, *pre, *p;
    while (list->next != list) {
        //初始条件重置 第一遍写错了，注意
        pre = list;
        p = list->next;
        minPre = pre;
        minP = p;

        while (p!=list) {
            if (p->data < minP->data && p->data != INT_FAST16_MAX) {//我怎么写成p.data < pre.data了
                minP = p;
                minPre = pre;
            }
            pre = p;
            p = p->next;
        }

        cout << minP->data << " ";
        minPre->next = minP->next;
        free(minP);


    }
}

int main() {
    CircleList list1;
    int *arr = random(6, 9);
    headCreateListAfter(list1, arr, 6);
    // printList(list1);

    min_output_delete(list1);

}