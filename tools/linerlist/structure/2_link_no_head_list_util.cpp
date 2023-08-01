//
// Created by AutumnSigni on 2023/7/31.
//单链表 -- 无头结点

#include "2_link_no_head_list_util.h"
#include <iostream>
using namespace std;

bool insertBefore(NoHeadLinkList &list, NoHeadNode *p, int data) {
    auto *s = (NoHeadLinkList) malloc(sizeof(NoHeadNode));
    if (list == nullptr) return false;
    if (list == p) {
        s->data = data;
        s->next = p;
        list = s;
    } else {
        s->data = p->data;
        s->next = p->next;
        p->next=s;
        p->data = data;
    }
    return true;
}

NoHeadNode *getElem(NoHeadLinkList list, int i) {
    int j = 1;
    NoHeadNode *p = list;
    if (i < 1)
        return nullptr;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}


/**
 * 和带头节点的一样
 * @param p
 * @param data
 * @return
 */
bool insertAfter(NoHeadNode *p, int data) {
    NoHeadNode *s = (NoHeadLinkList) malloc(sizeof(NoHeadNode));
    s->data = data;
    s->next = p->next;
    p->next = s;
    return true;
}

bool insertById(NoHeadLinkList &list, int i, int data) {
    NoHeadNode *p = getElem(list, i);
    return insertBefore(list, p, data);
}

bool deleteAt(NoHeadLinkList &list, int i) {
    if (i < 1) {
        return false;
    }
    if (i == 1) {
        list = list->next;
    } else {
        NoHeadNode *s = getElem(list, i - 1);
        s->next = s->next->next;
    }
    return true;
}

int getLength(NoHeadLinkList list) {
    if (list == nullptr) {
        return -1;
    }
    int i = 1;
    while (list->next != nullptr) {
        i++;
    }
    return i;
}

bool isEmpty(NoHeadLinkList list) {
    return list == nullptr;
}

void printList(NoHeadLinkList list) {
    NoHeadNode *p = list;
    if (isEmpty(list)) {
        cout << "空表" << endl;
        return;
    }
    int i = 0;
    cout << "单链表：" << endl << "[";
    while (p != nullptr) {
        if (i != 0 && i % 7 == 0) cout << endl << ' ';
        cout << p->data << ',' << '\t';
        p = p->next;
        i++;
        //判断p是不是最后一个节点
        //p == nullptr 是当表只有一个节点
        //p ->next ==  nullptr 是当表大于1个节点时，p为最后一个节点
        if (p == nullptr || p->next == nullptr) {
            break;
        }
    }
    cout << p->data << ']' << endl;
}

//       前插法建立表，后插法建立表
NoHeadLinkList headCreateListPre(NoHeadLinkList &list, int data[], int len) {
    NoHeadNode *s;
    list = nullptr;
    for (int i = 0; i < len; ++i) {
        s = (NoHeadLinkList) malloc(sizeof(NoHeadNode));
        s->data = data[i];
        s->next = list;
        list = s;
    }
    return list;
}

NoHeadLinkList headCreateListAfter(NoHeadLinkList &list, int data[], int len) {
    NoHeadNode *s, *rear;
    list = (NoHeadLinkList) malloc(sizeof(NoHeadNode));
    list->data = data[0];
    list->next = nullptr;
    rear = list;
    for (int i = 1; i < len; ++i) {
        s = (NoHeadLinkList) malloc(sizeof(NoHeadNode));
        s->data = data[i];
        s->next = rear->next;
        rear->next = s;
        rear = s;
    }
    return list;
}