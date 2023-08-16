//
// Created by AutumnSigni on 2023/7/31.
// 顺序表

#ifndef CHAPTER3_STACKANDQUEUE_0_SQ_SINGLE_LIST_UTIL_H
#define CHAPTER3_STACKANDQUEUE_0_SQ_SINGLE_LIST_UTIL_H

// 定义
typedef struct SqList {
    int *data;
    int length;
    int MaxSize;
}
SqList;

// 创建
void initList(SqList &sqList);

// 删除
void DestroyList(SqList &sqList);

// 增
bool insertList(SqList &sqList, int i, int value);

// 删
int listDelete(SqList &sqList, int i);

// 按位查
int getElem(SqList sqList, int i);

// 按值查
int locateValue(SqList sqList, int value);

// 判空
bool isEmpty(SqList sqList);

// 表长
int getLength(SqList sqList);

// 扩容方法
SqList extendList(SqList sqList);

//输出格式
void printList(SqList sqList);

#endif //CHAPTER3_STACKANDQUEUE_0_SQ_SINGLE_LIST_UTIL_H
