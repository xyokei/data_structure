//
// Created by AutumnSigni on 2023/7/31.
//

#include "5_link_cicle_2_head_list_util.h"
#include <iostream>

using namespace std;

void initList(CircleDList &list) {
    list = (CircleDNode *) malloc(sizeof(CircleDNode));
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
bool insertLinklist(CircleDList &list, CircleDNode *p, int data) {
    if (isEmpty(list)) {
        return false;
    }
    auto node = (CircleDNode *) malloc(sizeof(CircleDNode));
    node->data = data;
    //断节点
    node->next = p->next;
    p->next->prior = node;
    node->prior = p;
    p->next = node;
    return true;
}

bool deleteLinklist(CircleDList &list, CircleDNode *p) {
    if (list == p) {
        return false;
    }
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return true;
}

CircleDNode *getElem(CircleDList list, int i) {
    if (i < 1) { return nullptr; }
    int j = 1;
    CircleDNode *p = list->next;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

bool isEmpty(CircleDList list) {
    return list->next == list;
}

void printList(CircleDList list) {
    CircleDNode *p = list->next;
    if (isEmpty(list)) {
        cout << "空表" << endl;
        return;
    }
    int i = 0;
    cout << "双链表：" << endl << "[";
    while (p && p->next != list) {
        if (i != 0 && i % 7 == 0) cout << endl << ' ';
        cout << p->data << ',' << '\t';
        p = p->next;
        i++;
        //判断p是不是最后一个节点
        //p == nullptr 是当表只有一个节点
        //p ->next ==  nullptr 是当表大于1个节点时，p为最后一个节点
        if (p->next == list) {
            break;
        }
    }
    cout << p->data << ']' << endl;
    // // 测试prior
    // i = 0;
    // cout << "双链表：prior 输出" << endl << "[";
    // while (p->prior != list) {
    //     if (i != 0 && i % 7 == 0) cout << endl << ' ';
    //     cout << p->data << ',' << '\t';
    //     p = p->prior;
    //     i++;
    //     //判断p是不是最后一个节点
    //     //p == nullptr 是当表只有一个节点
    //     //p ->next ==  nullptr 是当表大于1个节点时，p为最后一个节点
    //     if (p->prior == list) {
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
CircleDList headCreateListPre(CircleDList &list, int data[], int len) {
    CircleDNode *s;
    list = (CircleDList) malloc(sizeof(CircleDNode));
    list->next = nullptr;
    // 处理第一个结点，不然list->next->prior 无值
    s = (CircleDList) malloc(sizeof(CircleDNode));
    s->data = data[0];
    s->prior = list;
    s->next = list;
    list->next = s;
    list->prior = s;
    for (int i = 1; i < len; ++i) {
        s = (CircleDList) malloc(sizeof(CircleDNode));
        s->data = data[i];
        list->next->prior = s;
        s->next = list->next;
        s->prior = list;
        list->next = s;
    }
    return list;
}

CircleDList headCreateListAfter(CircleDList &list, int data[], int len) {
    CircleDNode *s, *rear;
    list = (CircleDNode *) malloc(sizeof(CircleList));
    list->next = list;
    list->prior = list;
    rear = list;
    for (int i = 0; i < len; ++i) {
        s = (CircleDNode *) malloc(sizeof(CircleList));
        s->data = data[i];
        s->next = rear->next;
        s->prior = rear;
        list->prior = s;
        rear->next = s;
        rear = s;

    }
    return list;
}