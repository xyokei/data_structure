//
// Created by AutumnSigni on 2023/8/20.
//

#include "0_sq_stack.h"
#include <iostream>

using namespace std;
// 初始化
void initStack(SqStack &s){
    s.top = -1;
}
// 判空
bool isEmpty(SqStack s){
    return s.top == -1;
}

// 进栈
bool push(SqStack &s,ElemType v){
    if (s.top == MaxSize -1){
        return false;
    }
    s.data[++s.top] = v ;
    return true;
}

//出栈
bool pop(SqStack &s,ElemType &v){
    if(s.top == -1){
        return false;
    }
    v = s.data[s.top--];
    return true;
}

//读取栈顶元素
bool getTop(SqStack s,ElemType &v){
    if(s.top == -1){
        return false;
    }
    v = s.data[s.top];
    return true;
}

//打印
void print(SqStack s) {
    if (s.top == -1){
        cout << "空栈"<< endl;
        return;
    }
    cout << "顺序栈："<< endl;
    cout << "栈长为：" << s.top + 1 << endl;
    cout << '[';
    int j = 0;
    for (int i = s.top; i > 0; --i,++j) {
        if (i!= s.top && i % 7 == 0) {
            cout << s.data[i] << "\n" << " ";
            continue;
        }
        cout << s.data[i] << ',' << '\t';
        //printf("%d,",seqList.data[i]);
    }
    cout << s.data[0] << ']'<<endl;
}