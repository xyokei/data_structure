//
// Created by AutumnSigni on 2023/8/20.
//

#ifndef CHAPTER2_LINERLIST_0_SQ_STACK_H
#define CHAPTER2_LINERLIST_0_SQ_STACK_H

#define MaxSize 50
#define ElemType char

typedef struct SqStack{
    ElemType data[MaxSize];
    int top;
}SqStack;

void initStack(SqStack &s);
// 判空
bool isEmpty(SqStack s);
// 进栈
bool push(SqStack &s,ElemType v);

//出栈
bool pop(SqStack &s,ElemType &v);

//读取栈顶元素
bool getTop(SqStack s,ElemType &v);

//打印
void print(SqStack s);

#endif //CHAPTER2_LINERLIST_0_SQ_STACK_H
