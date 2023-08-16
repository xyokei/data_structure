//
// Created by AutumnSigni on 2023/7/13.
//栈 -- 链式存储 定义

#ifndef LINK_STACK_H
#define LINK_STACK_H

typedef struct StackNode{
    int data;
    StackNode *next;
}StackNode, *LinkStack;

#endif //LINK_STACK_H
