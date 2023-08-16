//
// Created by AutumnSigni on 2023/7/13.
//栈 -- 接口

# include "sq_stack_util.h"
# include "link_stack_util.h"
#ifndef SQ_UTIL_
#define SQ_UTIL_

template<typename T>
// 初始化
void initStack(T &s);
// 判空
template<typename T>
bool isEmpty(T s);

// 进栈
template<typename T>
bool push(T &s,int v);

//出栈
template<typename T>
bool pop(T &s,int &v);

//读取栈顶元素
template<typename T>
bool getTop(T s,int &v);

//栈销毁
template<typename T>
bool destroy(T &s);

//打印
template<typename T>
bool print(T &s);
#endif
