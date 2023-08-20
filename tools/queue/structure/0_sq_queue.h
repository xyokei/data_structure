//
// Created by AutumnSigni on 2023/8/20.
//

#ifndef CHAPTER3_STACKANDQUEUE_0_SQ_QUEUE_H
#define CHAPTER3_STACKANDQUEUE_0_SQ_QUEUE_H

#define MaxSize 50
typedef struct {
    int data[MaxSize];
    int front, rear;
} SqQueue;


// 初始化
void initQueue(SqQueue &queue);

// 判空
bool isEmpty(SqQueue queue);

// 入队
bool enQueue(SqQueue &queue, int x);

// 出队
bool deQueue(SqQueue &queue, int &x);

// 读头
bool getHead(SqQueue queue, int &x);

// 打印
void printQueue(SqQueue queue);

#endif //CHAPTER3_STACKANDQUEUE_0_SQ_QUEUE_H
