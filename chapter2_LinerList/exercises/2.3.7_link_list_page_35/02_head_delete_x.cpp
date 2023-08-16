//
// Created by AutumnSigni on 2023/8/17.
//

#include "liner_list_util.h"
#include "algorithm"

/**
 * 递归试试
 * @param list
 * @param x
 */
void delete_x(SingleList &list, int x) { //这个警告这么烦人的？代码没问题，就是提醒我这有个递归？
    if (list->next == nullptr) return;

    delete_x(list->next, x);  //直接指到末尾

    if (list->next->data == x) {   //此时list 为倒数第二个节点 ，判断倒数第一个结点是否是x
        SingleNode *p = list->next;
        list->next = p->next;
        free(p);
    }
}

//法2 :尾插法链接表 判断 是否等于x

int main() {
    SingleList list;
    initList(list);
    int *arr = random(6, 0, 9);
    headCreateListAfter(list, arr, 6);
    printList(list);

    delete_x(list, 2);

    printList(list);
}