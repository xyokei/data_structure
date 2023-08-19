//
// Created by AutumnSigni on 2023/8/20.
//

#ifndef CHAPTER2_LINERLIST_1_LINK_STACK_H
#define CHAPTER2_LINERLIST_1_LINK_STACK_H

typedef struct StackNode{
    int data;
    StackNode *next;
}StackNode, *LinkStack;

// 初始化
void initStack(LinkStack &s);

// 判空
bool isEmpty(LinkStack s);

// 进栈
bool push(LinkStack &s, int v);

//出栈
bool pop(LinkStack &s, int &v);

//读取栈顶元素
bool getTop(LinkStack s, int &v);

void print(LinkStack s);

#endif //CHAPTER2_LINERLIST_1_LINK_STACK_H
