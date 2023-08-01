//
// Created by AutumnSigni on 2023/7/31.
//双链表 -- 有头结点

#ifndef CHAPTER3_STACKANDQUEUE_3_LINK_2_NO_HEAD_LIST_UTIL_H
#define CHAPTER3_STACKANDQUEUE_3_LINK_2_NO_HEAD_LIST_UTIL_H
typedef struct DoubleNode {
    int data;
    DoubleNode *prior, *next;
} DoubleNode, *DoubleList;

void initList(DoubleList &list);

bool insertLinklist(DoubleList &list, DoubleNode *p, int data);

bool deleteLinklist(DoubleList &list, DoubleNode *p);

DoubleNode *getElem(DoubleList list, int i);

bool isEmpty(DoubleList list);

void printList(DoubleList list);

DoubleList headCreateListPre(DoubleList &list, int data[], int len);


#endif //CHAPTER3_STACKANDQUEUE_3_LINK_2_NO_HEAD_LIST_UTIL_H
