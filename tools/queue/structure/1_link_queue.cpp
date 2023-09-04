//
// Created by AutumnSigni on 2023/8/20.
//

#include "1_link_queue.h"
#include <iostream>

using namespace std;

void initQueue(LinkQueue &queue) {
    queue->front = queue->rear = (QueueNode *) malloc(sizeof(QueueNode));
    queue->front = queue->rear = nullptr;
}

// 判空
bool isEmpty(LinkQueue queue) {
    if (queue->rear == queue->front) return true;
    else return false;
}

// 入队
bool enQueue(LinkQueue &queue, int x) {
    QueueNode *q = (QueueNode *) malloc(sizeof(QueueNode));
    q->data = x;
    q->next = nullptr;
    queue->rear->next = q;
    queue->rear = q;
}

// 出队
bool deQueue(LinkQueue &queue, int &x) {
    if (queue->rear == queue->front) return false;
    QueueNode *p = queue->front;
    x = p->data;
    queue->front->next = p->next;
    if (queue->rear == p) {
        queue->rear == queue->front;
    }
    free(p);
    return true;
}

// 读头
bool getHead(LinkQueue queue, int &x) {
    if (queue->rear == queue->front) return false;
    x = queue->front->data;
    return true;
}

// 打印
void printQueue(LinkQueue queue) {
    if (queue->rear == queue->front) cout << "空队";
    int i = 1;
    cout << "队列长：" << queue->front - queue->rear << endl;
    cout << "[";
    QueueNode *p = queue->front;
    while (p->next != queue->rear) {
        if (i % 7 == 0) {
            cout << p->data << endl;
        }
        cout << p->data << ",\t";
        i++;
    }
    cout << p->next->data << "]" << endl;
}