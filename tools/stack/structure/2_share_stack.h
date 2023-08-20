//
// Created by AutumnSigni on 2023/8/20.
//

#ifndef CHAPTER3_STACKANDQUEUE_2_SHARE_STACK_H
#define CHAPTER3_STACKANDQUEUE_2_SHARE_STACK_H

#define MaxSize 100

typedef struct ShareStack{
    int data[MaxSize];
    int top[2];
}ShareStack;
void initStack(ShareStack &s);
// 判空
bool isEmpty(ShareStack s);
// 进栈
bool push(ShareStack &s,int i,int x);

//出栈
bool pop(ShareStack &s,int &v);

//读取栈顶元素
bool getTop(ShareStack s,int &v);

//打印
void print(ShareStack s);


#endif //CHAPTER3_STACKANDQUEUE_2_SHARE_STACK_H
