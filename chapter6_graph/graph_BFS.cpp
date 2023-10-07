//
// Created by AutumnSigni on 2023/10/4.
//

#include <iostream>
#include <queue>
#include "graph/graph_util.h"
#include "int_random.h"

#define size 10

using namespace std;
// 变量定义，不想传参数，用全局
int graph[max_size][max_size];
int n = 6; //顶点数
bool inq[max_size] = {false};
queue<int> q;

/**
 *思想
 * 设定辅助队列
 * 任取一个顶点入队，访问从该顶点直接到达的其他顶点，并依次入队
 * 从队中在取一个顶点，访问该顶点直接到达的其他顶点，并依次入队
 * 重复直至队列空遍历结束
 * @param u
 */
void BFS(int u) {
    cout << u << ' '; //访问顶点
    inq[u] = true;  //顶点是否访问
    q.push(u); //访问的顶点入队
    while (!q.empty()) {
        u = q.front();//取队首
        q.pop(); //出队，访问该顶点的邻接结点
        for (int i = 0; i < n; ++i) {//此处与邻接表不同
            //是邻接结点 且 未访问的
            if (graph[u][i] != 0 && !inq[u]) {
                cout << i << ' '; //访问
                q.push(i);
                inq[u] = true; //设定已访问
            }
        }
    }
}

void BFSTrave() {
    for (int i = 0; i < n; ++i) {
        if (!inq[i]) {
            BFS(i);
        }
    }
}
void print(){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<graph[i][j]<<' ';
        }
        cout<<endl;
    }
}
int main() {
    //不用初始化，未赋值的自动取0;
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         graph[i][j] = 0;
    //     }
    // }
    //压缩存储，对称阵
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;
    graph[2][4] = 1;
    graph[2][1] = 1;
    graph[2][0] = 1;
    graph[3][1] = 1;
    graph[3][4] = 1;
    graph[3][5] = 1;
    graph[4][1] = 1;
    graph[4][2] = 1;
    graph[4][3] = 1;
    graph[4][5] = 1;
    graph[5][3] = 1;
    graph[5][4] = 1;
    BFSTrave();
}