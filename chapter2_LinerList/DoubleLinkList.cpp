//
// Created by AutumnSigni on 2023/6/28.
//
//线性表 - 双链表 -有头结点

// 定义
// 基本： 增(节点前增，节点后增)  只写前增
//       删
//       查（按位查，按值查）只写按位
// 附加：判空，表长，输出格式 只写输出
//       前插法建立表，后插法建立表

#include <iostream>

using namespace std;

typedef struct DNode {
    int data;
    DNode *prior, *next;
} DNode, *LinkList;

void initList(LinkList &list);

bool insertLinklist(LinkList &list, DNode *p, int data);

bool deleteLinklist(LinkList &list, DNode *p);

DNode *getElem(LinkList list, int i);

bool isEmpty(LinkList list);

void printList(LinkList list);
LinkList headCreateListPre(LinkList &list, int data[], int len);


void initList(LinkList &list) {
    list = (DNode *) malloc(sizeof(DNode));
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
bool insertLinklist(LinkList &list, DNode *p, int data) {
    if (isEmpty(list)) {
        return false;
    }
    auto node = (DNode *) malloc(sizeof(DNode));
    node->data = data;
    //断节点
    node->next = p->next;
    p->next->prior = node;
    node->prior = p;
    p->next = node;
    return true;
}

bool deleteLinklist(LinkList &list, DNode *p) {
    if (list == p) {
        return false;
    }
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return true;
}

DNode *getElem(LinkList list, int i) {
    if (i < 1) { return nullptr; }
    int j = 1;
    DNode *p = list->next;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

bool isEmpty(LinkList list) {
    return list->next == nullptr;
}

void printList(LinkList list) {
    DNode *p = list->next;
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
    i = 0;
    cout << "双链表：prior 输出" << endl << "[";
    while (p->prior != nullptr) {
        if (i != 0 && i % 7 == 0) cout << endl << ' ';
        cout << p->data << ',' << '\t';
        p = p->prior;
        i++;
        //判断p是不是最后一个节点
        //p == nullptr 是当表只有一个节点
        //p ->next ==  nullptr 是当表大于1个节点时，p为最后一个节点
        if (p == nullptr || p->prior == list) {
            break;
        }
    }
    cout << p->data << ']' << endl;
}

/**
 * 前插法建立单链表
 * @param list
 * @param data 建立数据
 * @param len 数据长度
 * @return
 */
LinkList headCreateListPre(LinkList &list, int data[], int len) {
    DNode *s;
    list = (LinkList) malloc(sizeof(DNode));
    list->next= nullptr;
    // 处理第一个结点，不然list->next->prior 无值
    s= (LinkList) malloc(sizeof(DNode));
    s->data = data[0];
    s->prior=list;
    s->next = nullptr;
    list->next = s;

    for (int i = 1; i < len; ++i) {
        s = (LinkList) malloc(sizeof(DNode));
        s->data = data[i];
        list->next->prior = s;
        s->next = list->next;
        s->prior = list;
        list->next = s;
    }
    return list;
}

int main() {
    int len = 20;
    int data[len];
    for (int i = 0; i < len; ++i) {
        data[i] = i+1;
    }
    LinkList listPre;
    initList(listPre);
    headCreateListPre(listPre,data,len);
    printList(listPre);

    DNode *s = getElem(listPre,10);
    cout<<"第10个结点值："<<s->data<<endl;
    insertLinklist(listPre,s,44);
    printList(listPre);
    s= getElem(listPre,2);
    deleteLinklist(listPre,s);
    printList(listPre);
}



