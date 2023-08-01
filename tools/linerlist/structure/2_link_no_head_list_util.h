//
// Created by AutumnSigni on 2023/7/31.
//单链表 -- 无头结点

#ifndef CHAPTER3_STACKANDQUEUE_2_LINK_NO_HEAD_LIST_UTIL_H
#define CHAPTER3_STACKANDQUEUE_2_LINK_NO_HEAD_LIST_UTIL_H
// 定义
typedef struct NoHeadNode {
    int data;
    struct NoHeadNode *next;
}NoHeadNode, *NoHeadLinkList;

// 定义
// 基本： 增( 只写前增 ）
//       删 只写按位
//       查 只写按位
// 附加： 输出格式 只写输出
//       前插法建立表，后插法建立表

// 插(节点前插，节点后插) 按位插
bool insertBefore(NoHeadLinkList &list, NoHeadNode *p, int data);

bool insertAfter(NoHeadNode *p, int data);

bool insertById(NoHeadLinkList &list, int i, int data);

bool deleteAt(NoHeadLinkList &list, int i);

NoHeadNode *getElem(NoHeadLinkList list, int i);

int getLength(NoHeadLinkList list);

void printList(NoHeadLinkList list);

// 前插法建立表，后插法建立表
NoHeadLinkList headCreateListPre(NoHeadLinkList &list, int data[], int len);

NoHeadLinkList headCreateListAfter(NoHeadLinkList &list, int data[], int len);

#endif //CHAPTER3_STACKANDQUEUE_2_LINK_NO_HEAD_LIST_UTIL_H
