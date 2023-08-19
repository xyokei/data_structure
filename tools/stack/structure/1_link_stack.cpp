//
// Created by AutumnSigni on 2023/8/20.
//

#include "1_link_stack.h"
#include <iostream>

using namespace std;

#define null nullptr

// 初始化
void initStack(LinkStack &s) {
    s = (StackNode *) malloc(sizeof(StackNode));
    s->next = null;
}

// 判空
bool isEmpty(LinkStack s) {
    return s->next == null;
}

// 进栈
bool push(LinkStack &s, int v) {
    auto *node = (LinkStack) malloc(sizeof(StackNode));
    node->data = v;
    node->next = s->next;
    s->next = node;
    return true;
}

//出栈
bool pop(LinkStack &s, int &v) {
    if (s->next == null) return false;
    v = s->next->data;
    s->next = s->next->next;
    return true;
}

//读取栈顶元素
bool getTop(LinkStack s, int &v) {
    if (s->next == null) return false;
    v = s->next->data;
    return true;
}

void print(LinkStack s) {
    StackNode *p = s->next;
    if (isEmpty(s)) {
        cout << "空栈" << endl;
        return;
    }
    int i = 0;
    cout << "链栈：" << endl << "[";
    while (p != null) {
        if (i != 0 && i % 7 == 0) cout << endl << ' ';
        cout << p->data << ',' << '\t';
        p = p->next;
        i++;
        //判断p是不是最后一个节点
        //p == nullptr 是当表只有一个节点
        //p ->next ==  nullptr 是当表大于1个节点时，p为最后一个节点
        if (p == null || p->next == null) {
            break;
        }
    }
    cout << p->data << ']' << endl;
}