//
// Created by AutumnSigni on 2023/6/25.
//
//线性表 - 单链表 - 不带头节点

// 定义
// 基本： 增(节点前增，节点后增)  只写前增
//       删
//       查（按位查，按值查）只写按位
// 附加：判空，表长，输出格式 只写输出
//       前插法建立表，后插法建立表

#include <iostream>

using namespace std;

// 定义
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 定义
// 基本： 增( 只写前增 ）
//       删 只写按位
//       查 只写按位
// 附加： 输出格式 只写输出
//       前插法建立表，后插法建立表

// 插(节点前插，节点后插) 按位插
bool insertBefore(LinkList &list, LNode *p, int data);

bool insertAfter(LNode *p, int data);

bool insertById(LinkList &list, int i, int data);

bool deleteAt(LinkList &list, int i);

LNode *getElem(LinkList list, int i);

int getLength(LinkList list);

void printList(LinkList list);

//       前插法建立表，后插法建立表
LinkList headCreateListPre(LinkList &list, int data[], int len);

LinkList headCreateListAfter(LinkList &list, int data[], int len);


bool insertBefore(LinkList &list, LNode *p, int data) {
    auto *s = (LinkList) malloc(sizeof(LNode));
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

/**
 * 和带头节点的一样
 * @param p
 * @param data
 * @return
 */
bool insertAfter(LNode *p, int data) {
    LNode *s = (LinkList) malloc(sizeof(LNode));
    s->data = data;
    s->next = p->next;
    p->next = s;
    return true;
}

bool insertById(LinkList &list, int i, int data) {
    LNode *p = getElem(list, i);
    return insertBefore(list, p, data);
}

bool deleteAt(LinkList &list, int i) {
    if (i < 1) {
        return false;
    }
    if (i == 1) {
        list = list->next;
    } else {
        LNode *s = getElem(list, i - 1);
        s->next = s->next->next;
    }
    return true;
}

int getLength(LinkList list) {
    if (list == nullptr) {
        return -1;
    }
    int i = 1;
    while (list->next != nullptr) {
        i++;
    }
    return i;
}

bool isEmpty(LinkList list) {
    return list == nullptr;
}

LNode *getElem(LinkList list, int i) {
    int j = 1;
    LNode *p = list;
    if (i < 1)
        return nullptr;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

void printList(LinkList list) {
    LNode *p = list;
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
LinkList headCreateListPre(LinkList &list, int data[], int len) {
    LNode *s;
    list = nullptr;
    for (int i = 0; i < len; ++i) {
        s = (LinkList) malloc(sizeof(LNode));
        s->data = data[i];
        s->next = list;
        list = s;
    }
    return list;
}

LinkList headCreateListAfter(LinkList &list, int data[], int len) {
    LNode *s, *rear;
    list = (LinkList) malloc(sizeof(LNode));
    list->data = data[0];
    list->next = nullptr;
    rear = list;
    for (int i = 1; i < len; ++i) {
        s = (LinkList) malloc(sizeof(LNode));
        s->data = data[i];
        s->next = rear->next;
        rear->next = s;
        rear = s;
    }
    return list;
}

int main() {
    int len = 20;
    int data[len];
    for (int i = 0; i < len; ++i) {
        data[i] = i + 1;
    }
    LinkList listPre, listAfter;

    headCreateListPre(listPre, data, len);
    printList(listPre);
    deleteAt(listPre, 1);
    printList(listPre);
    deleteAt(listPre, 3);
    printList(listPre);
    LNode *p = getElem(listPre, 1);
    cout << p->data << endl;
    insertBefore(listPre, p, 21);
    printList(listPre);
    p = getElem(listPre, 19);
    cout << p->data << endl;
    insertAfter(p, 22);
    printList(listPre);

    headCreateListAfter(listAfter, data,len);
    printList(listAfter);
}