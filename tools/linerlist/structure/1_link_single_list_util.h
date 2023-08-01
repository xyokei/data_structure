//
// Created by AutumnSigni on 2023/7/31.
//单链表 -- 有头结点

#ifndef CHAPTER3_STACKANDQUEUE_1_LINK_SINGLE_LIST_UTIL_H
#define CHAPTER3_STACKANDQUEUE_1_LINK_SINGLE_LIST_UTIL_H
typedef struct SingleNode {
    int data;
    struct SingleNode *next;
}SingleNode, *SingleList;

// 创建 销毁
bool initList(SingleList &list);

void destroyList(SingleList &list);

// 插(节点前插，节点后插) 按位插
bool insertBefore(SingleNode *p, int data);

bool insertAfter(SingleNode *p, int data);

bool insertById(SingleList &list, int i, int data);

// 删（按位删，按节点删）
bool deleteAt(SingleList &list, int i);

bool deleteNode(SingleList &list, SingleNode *p);

//查（按位查，按值查）
SingleNode *getElem(SingleList list, int i);

SingleNode *locateValue(SingleList list, int value);

// 附加：判空，表长，输出格式
bool isEmpty(SingleList list);

int getLength(SingleList list);

void printList(SingleList list);

#endif //CHAPTER3_STACKANDQUEUE_1_LINK_SINGLE_LIST_UTIL_H
