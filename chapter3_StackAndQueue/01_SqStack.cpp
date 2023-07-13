//
// Created by AutumnSigni on 2023/7/12.
//
//栈 - 顺序栈

#include <iostream>
using namespace std;

#define MaxSize 50

typedef struct Node{
    int data[MaxSize];
    int top;
}SqStack;

// 初始化
void initStack(SqStack &s){
    s.top = -1;
}
// 判空
bool isEmpty(SqStack s){
    return s.top == -1;
}

// 进栈
bool push(SqStack &s,int v){
    if (s.top == MaxSize -1){
        return false;
    }
    s.data[++s.top] = v ;
    return true;
}

//出栈
bool pop(SqStack &s,int &v){
    if(s.top == -1){
        return false;
    }
    v = s.data[s.top--];
    return true;
}
int main(){
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};
    SqStack stack;
    initStack(stack);
    for (int i = 0; i < 20; ++i) {
        push(stack, data[i]);
    }
    printf("[");
    int x;
    for (int i = 0; i < 20; ++i) {
        if (pop(stack, x)) {
            printf("%d, ", x);
        }
    }
    printf("] \r\n");
    return 0;
}

