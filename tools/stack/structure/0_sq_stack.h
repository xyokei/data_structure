//
// Created by AutumnSigni on 2023/8/20.
//

#ifndef CHAPTER2_LINERLIST_0_SQ_STACK_H
#define CHAPTER2_LINERLIST_0_SQ_STACK_H

#define MaxSize 50

typedef struct SqStack{
    int data[MaxSize];
    int top;
}SqStack;

void initStack(SqStack &s);
// 判空
bool isEmpty(SqStack s);
// 进栈
bool push(SqStack &s,int v);

//出栈
bool pop(SqStack &s,int &v);

//读取栈顶元素
bool getTop(SqStack s,int &v);

//打印
void print(SqStack s);

#endif //CHAPTER2_LINERLIST_0_SQ_STACK_H
