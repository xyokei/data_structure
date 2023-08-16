//
// Created by AutumnSigni on 2023/7/31.
//单链表 -- 有头结点

#include "1_link_single_list_util.h"
#include <iostream>
using namespace std;

/**
 * 初始化一个带头结点的链表
 * @return 头结点
 */
bool initList(SingleList &list) {
    list = (SingleNode *) malloc(sizeof(SingleNode));
    if (list == nullptr) { //未申请到空间判断
        return false;
    }
    list->next = nullptr;
    return true;
}

/**
 * 销毁表
 * @param list
 */
void destroyList(SingleList &list) {
    SingleNode *p = list->next;
    SingleNode *next;
    while (p != nullptr) {
        next = p->next;
        free(p);
        p = next;
    }
}

/**
 * 前插法，采用后插法思想
 * @param p
 * @param data
 * @return
 */
bool insertBefore(SingleNode *p, int data) {
    if (p != nullptr) {
        auto *node = (SingleNode *) malloc(sizeof(SingleNode));
        //交换数据
        node->data = p->data;
        p->data = data;
        //交换结点
        node->next = p->next;
        p->next = node;
        return true;
    }

    return false;
}

/**
 * 后插法
 * @param list
 * @param p
 * @param data
 * @return
 */
bool insertAfter(SingleNode *p, int data) {
    auto *node = (SingleList) malloc(sizeof(SingleNode));
    node->data = data;
    node->next = p->next;
    p->next = node;
    return true;
}

/**
 *指定位置插人数据，即前插法
 * @param list
 * @param i
 * @param data
 * @return false:插入位置不合法
 */
bool insertById(SingleList &list, int i, int data) {
    auto *p = getElem(list, i);
    if (p == nullptr) {
        return false;
    }
    return insertBefore(p, data);
}

// 删（按位删，按节点删）
/**
 *
 * @param list 感觉不用带地址符号，因为删除总删除不了头节点
 * @param i
 * @return
 * 没有有偷梁换柱的方法，是因为尾节点不好处理
 */
bool deleteAt(SingleList &list, int i) {
    auto *p = getElem(list, i);
    if (p == nullptr) {
        return false;
    }
    SingleNode *q = list;
    while (q->next != p) {
        q++;
    }
    q->next = p->next;
    free(p);
    return true;
}

bool deleteNode(SingleList &list, SingleNode *p) {
    if (p == list || p == nullptr) {
        return false;
    }
    SingleNode *q = list;
    while (q->next != p) {
        q++;
    }
    q->next = p->next;
    free(p);
    return true;
}

/**
 * 按位查
 * @param list
 * @param i
 * @return 第i个结点，若表长小于位序，返回nullptr
 */
SingleNode *getElem(SingleList list, int i) {
    int j = 1;
    SingleNode *p = list->next;
    if (i < 1)
        return nullptr;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

/**
 * 按值查结点
 * @param list
 * @param value
 * @return 结点，未查到返回nullptr
 */
SingleNode *locateValue(SingleList list, int value) {
    SingleNode *p = list->next;
    while (p != nullptr && p->data != value) {
        p = p->next;
    }
    return p;
    // 我写的
    // while (p != nullptr) {
    //     if (p->data == value) return p;
    //     p = p->next;
    // }
    // return nullptr;
}

// 附加：判空，表长，输出格式
bool isEmpty(SingleList list) {
    return list->next == nullptr;
}

int getLength(SingleList list) {
    int i = 0;
    while (list->next != nullptr) {
        i++;
    }
    return i;
}

/**
 * 前插法建立单链表
 * @param list
 * @param data 建立数据
 * @param len 数据长度
 * @return
 */
SingleList headCreateListPre(SingleList &list, int data[], int len) {
    SingleNode *s;
    list = (SingleList) malloc(sizeof(SingleNode));
    list->next= nullptr; //不置空输出的时候有bug，无限循环
    for (int i = 0; i < len; ++i) {
        s = (SingleList) malloc(sizeof(SingleNode));
        s->data = data[i];
        s->next = list->next;
        list->next = s;
    }
    return list;
}

/**
 * 后插法建立表
 * @param list
 * @param data
 * @param len
 * @return
 */
SingleList headCreateListAfter(SingleList &list, const int data[],int len){
    SingleNode *s,*rear;
    list = (SingleList) malloc(sizeof(SingleNode));
    list->next= nullptr;
    rear = list;
    for (int i = 0; i < len; ++i) {
        s = (SingleList)malloc(sizeof(SingleNode));
        s->data= data[i];
        s->next = nullptr; //出bug了，最后一个指针要置空
        rear->next = s;
        rear = s;
    }
    return list;
}

void printList(SingleList list) {
    SingleNode *p = list->next;
    if (isEmpty(list)) {
        cout << "空表" << endl;
        return;
    }
    int i = 0;
    cout << "单链表：" << endl << "[";
    while (p != nullptr) {
        if (i!=0 && i % 7 == 0) cout << endl <<' ';
        cout << p->data<< ',' << '\t';
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
