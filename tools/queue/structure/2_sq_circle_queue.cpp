//
// Created by AutumnSigni on 2023/8/20.
//

#include "2_sq_circle_queue.h"
#include <iostream>

using namespace std;

// 初始化
void initQueue(SqCircleQueue &queue) {
    queue.front = queue.rear = 0;
}

// 判空
bool isEmpty(SqCircleQueue queue) {
    return queue.rear - queue.front == 0;
}

// 入队
bool enQueue(SqCircleQueue &queue, ElemType x) {
    if ((queue.rear + 1) % MaxSize == queue.front) {
        return false;
    }
    queue.data[queue.rear] = x;
    queue.rear = (queue.rear + 1) % MaxSize;  //牺牲一个单元区分队空 队满
    return true;
}

// 出队
bool deQueue(SqCircleQueue &queue, ElemType &x) {
    if (queue.front == queue.rear) {
        return false;
    }
    return queue.data[queue.front++];
}

// 读头
bool getHead(SqCircleQueue queue, ElemType &x) {
    if (queue.front == queue.rear) {
        return false;
    }
    x = queue.data[queue.front];
    queue.front = (queue.front + 1) % MaxSize;  //牺牲一个单元区分队空 队满
    return true;
}

void printQueue(SqCircleQueue queue) {
    int i = 1;
    int len;
    if (queue.front < queue.rear) {
        len = queue.rear - queue.front + 1;
    } else {
        len = MaxSize - queue.front + queue.rear + 1;
    }
    cout << "队列长：" << len << endl;
    while (queue.front != queue.rear) {
        if (i % 7 == 0) {
            cout << queue.data[queue.front++] << '\t';
        }
        i++;
    }
    cout << endl;
}