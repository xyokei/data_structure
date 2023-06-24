//
// Created by AutumnSigni on 2023/6/24.
//

#include "LinkListHead.h"


//Test
// 定义
// 创建 销毁
// 基本： 增(节点前增，节点后增)
//       删(节点前增，节点后增) 查（按位查，按值查）
// 附加：判空，表长，输出格式
int main() {
    int len = 20;
    int data[len];
    for (int i = 0; i < len; ++i) {
        data[i] = i+1;
    }
    LinkList listPre,listAfter;

    headCreateListPre(listPre,data,len);
    printList(listPre);
    deleteAt(listPre,1);
    printList(listPre);
    deleteAt(listPre,3);
    printList(listPre);
    LNode *p = getElem(listPre,18);
    cout<<p->data<<endl;
    insertBefore(p,21);
    p = getElem(listPre,19);
    cout<<p->data<<endl;
    insertAfter(p,22);
    printList(listPre);
    p = getElem(listPre,2);
    deleteNode(listPre,p);
    printList(listPre);

    // headCreateListAfter(listAfter,data,len);
    // printList(listAfter);
}