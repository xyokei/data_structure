//
// Created by AutumnSigni on 2023/8/20.
//

#ifndef CHAPTER3_STACKANDQUEUE_2_SQ_CIRCLE_QUEUE_H
#define CHAPTER3_STACKANDQUEUE_2_SQ_CIRCLE_QUEUE_H

#define MaxSize 50
#define ElemType char


typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqCircleQueue;
// 初始化
void initQueue(SqCircleQueue &queue);

// 判空
bool isEmpty(SqCircleQueue queue);

// 入队
bool enQueue(SqCircleQueue &queue, ElemType x);

// 出队
bool deQueue(SqCircleQueue &queue, ElemType &x);

// 读头
bool getHead(SqCircleQueue queue, ElemType &x);

// 打印
void printQueue(SqCircleQueue queue);

#endif //CHAPTER3_STACKANDQUEUE_2_SQ_CIRCLE_QUEUE_H
