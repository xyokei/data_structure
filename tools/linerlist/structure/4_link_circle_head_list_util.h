//
// Created by AutumnSigni on 2023/7/31.
//

#ifndef CHAPTER3_STACKANDQUEUE_4_LINK_CIRCLE_HEAD_LIST_UTIL_H
#define CHAPTER3_STACKANDQUEUE_4_LINK_CIRCLE_HEAD_LIST_UTIL_H

typedef struct CircleNode {
    int data;
    struct CircleNode *next;
}CircleNode, *CircleList;

// 创建 销毁
bool initList(CircleList &list);

void destroyList(CircleList &list);

// 插(节点前插，节点后插) 按位插
bool insertBefore(CircleNode *p, int data);

bool insertAfter(CircleNode *p, int data);

bool insertById(CircleList &list, int i, int data);

// 删（按位删，按节点删）
bool deleteAt(CircleList &list, int i);

bool deleteNode(CircleList &list, CircleNode *p);

//查（按位查，按值查）
CircleNode *getElem(CircleList list, int i);

CircleNode *locateValue(CircleList list, int value);

// 附加：判空，表长，输出格式
bool isEmpty(CircleList list);

int getLength(CircleList list);

void printList(CircleList list);

//       前插法建立表，后插法建立表

CircleList headCreateListPre(CircleList &list, int data[], int len);

CircleList headCreateListAfter(CircleList &list, int data[], int len);


#endif //CHAPTER3_STACKANDQUEUE_4_LINK_CIRCLE_HEAD_LIST_UTIL_H
