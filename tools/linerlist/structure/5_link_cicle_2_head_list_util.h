//
// Created by AutumnSigni on 2023/7/31.
//

#ifndef CHAPTER3_STACKANDQUEUE_5_LINK_CICLE_2_NO_HEAD_LIST_UTIL_H
#define CHAPTER3_STACKANDQUEUE_5_LINK_CICLE_2_NO_HEAD_LIST_UTIL_H

// 定义
typedef struct CircleDNode {
    int data;
    CircleDNode *prior, *next;
} CircleDNode, *CircleDList;

void initList(CircleDList &list);

bool insertLinklist(CircleDList &list, CircleDNode *p, int data);

bool deleteLinklist(CircleDList &list, CircleDNode *p);

CircleDNode *getElem(CircleDList list, int i);

bool isEmpty(CircleDList list);

void printList(CircleDList list);

CircleDList headCreateListPre(CircleDList &list, int data[], int len);


#endif //CHAPTER3_STACKANDQUEUE_5_LINK_CICLE_2_NO_HEAD_LIST_UTIL_H
