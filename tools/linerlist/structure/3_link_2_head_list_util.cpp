//
// Created by AutumnSigni on 2023/7/31.
//双链表 -- 有头结点

#include "3_link_2_head_list_util.h"
#include <iostream>

using namespace std;

void initList(DoubleList &list) {
    list = (DoubleNode *) malloc(sizeof(DoubleNode));
    list->next = nullptr;
    list->prior = nullptr;
    //list->data = 0;//不懂要不要初始化
}

/**
 * 节点后插
 * @param list
 * @param p
 * @param data
 * @return
 */
bool insertLinklist(DoubleList &list, DoubleNode *p, int data) {
    if (isEmpty(list)) {
        return false;
    }
    auto node = (DoubleNode *) malloc(sizeof(DoubleNode));
    node->data = data;
    //断节点
    node->next = p->next;
    p->next->prior = node;
    node->prior = p;
    p->next = node;
    return true;
}

bool deleteLinklist(DoubleList &list, DoubleNode *p) {
    if (list == p) {
        return false;
    }
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return true;
}

DoubleNode *getElem(DoubleList list, int i) {
    if (i < 1) { return nullptr; }
    int j = 1;
    DoubleNode *p = list->next;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

bool isEmpty(DoubleList list) {
    return list->next == nullptr;
}

void printList(DoubleList list) {
    DoubleNode *p = list->next;
    if (isEmpty(list)) {
        cout << "空表" << endl;
        return;
    }
    int i = 0;
    cout << "双链表：" << endl << "[";
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
    // 测试prior
    // i = 0;
    // cout << "双链表：prior 输出" << endl << "[";
    // while (p->prior != nullptr) {
    //     if (i != 0 && i % 7 == 0) cout << endl << ' ';
    //     cout << p->data << ',' << '\t';
    //     p = p->prior;
    //     i++;
    //     //判断p是不是最后一个节点
    //     //p == nullptr 是当表只有一个节点
    //     //p ->next ==  nullptr 是当表大于1个节点时，p为最后一个节点
    //     if (p == nullptr || p->prior == list) {
    //         break;
    //     }
    // }
    // cout << p->data << ']' << endl;
}

/**
 * 前插法建立单链表
 * @param list
 * @param data 建立数据
 * @param len 数据长度
 * @return
 */
DoubleList headCreateListPre(DoubleList &list, int data[], int len) {
    DoubleNode *s;
    list = (DoubleList) malloc(sizeof(DoubleNode));
    list->next = nullptr;
    // 处理第一个结点，不然list->next->prior 无值
    s = (DoubleList) malloc(sizeof(DoubleNode));
    s->data = data[0];
    s->freq = 0;
    s->prior = list;
    s->next = nullptr;
    list->next = s;

    for (int i = 1; i < len; ++i) {
        s = (DoubleList) malloc(sizeof(DoubleNode));
        s->data = data[i];
        s->freq = 0;
        list->next->prior = s;
        s->next = list->next;
        s->prior = list;
        list->next = s;
    }
    return list;
}

DoubleList headCreateListAfter(DoubleList &list, int data[], int len) {
    DoubleNode *s, *rear;
    list = (DoubleList) malloc(sizeof(DoubleNode));
    list->next = nullptr;
    list->prior = nullptr;
    rear = list;
    for (int i = 0; i < len; ++i) {
        s = (DoubleNode *) malloc(sizeof(DoubleList));
        s->data = data[i];
        s->freq = 0;
        s->next = rear->next;
        s->prior = rear;
        rear->next = s;
        rear = s;
    }
    return list;
}
