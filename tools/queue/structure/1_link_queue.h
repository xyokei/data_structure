//
// Created by AutumnSigni on 2023/8/20.
//

#ifndef CHAPTER3_STACKANDQUEUE_1_LINK_QUEUE_H
#define CHAPTER3_STACKANDQUEUE_1_LINK_QUEUE_H

#define MaxSize 50
typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} *LinkQueue;

// 初始化
void initQueue(LinkQueue &queue);

// 判空
bool isEmpty(LinkQueue queue);

// 入队
bool enQueue(LinkQueue &queue, int x);

// 出队
bool deQueue(LinkQueue &queue, int &x);

// 读头
bool getHead(LinkQueue queue, int &x);

// 打印
void printQueue(LinkQueue queue);

#endif //CHAPTER3_STACKANDQUEUE_1_LINK_QUEUE_H
