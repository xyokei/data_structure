//
// Created by AutumnSigni on 2023/8/20.
//

#include "0_sq_queue.h"
#include <iostream>

using namespace std;

// 初始化
void initQueue(SqQueue &queue) {
    queue.front = queue.rear = 0;
}

// 判空
bool isEmpty(SqQueue queue) {
    return queue.rear - queue.front == 0;
}

// 入队
bool enQueue(SqQueue &queue, int x) {
    if (queue.rear == MaxSize) {
        return false;
    }

    queue.data[++queue.rear] = x;
    return true;
}

// 出队
bool deQueue(SqQueue &queue, int &x) {
    if (queue.front == queue.rear) {
        return false;
    }
    return queue.data[queue.front++];
}

// 读头
bool getHead(SqQueue queue, int &x) {
    if (queue.front == queue.rear) {
        return false;
    }
    x = queue.data[queue.front];
    return true;
}

void printQueue(SqQueue queue) {
    int i = 1;
    cout << "队列长：" << queue.front - queue.rear << endl;
    cout << "[";
    while (queue.front != queue.rear) {
        if (i % 7 == 0) {
            cout << queue.data[queue.front++] << '\t';
        }
        i++;
    }
}