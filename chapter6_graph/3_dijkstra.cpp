//
// Created by AutumnSigni on 2023/10/5.
//

#include <iostream>

using namespace std;
#define max_v 6
#define inf 0x3fffffff //有符号的最大整数

// 思想：要求单源最短路径，则需要给定一个点 即源点
// 设定d[]存放下标顶点到达 源点 的最短路径长度
// 集合S存放已找到最短路径点 初始只有源点
// 1、每次从V-S(V中不含S的顶点)中选择与 源点 距离最小（即权值最小）的一个顶点记为u 加入S
//    此时u到 源点距离为 d[u]
// 2、以u为中介点 遍历所有u能到达的顶点v
//       若源点到v的距离d[v] 比 d[u] + g[u][v] 大 -> 源点到u点的最短路径 + u到v的路径
//         更新d[v] = d[u]+g[u][v],
// 3、直至 S包含所有顶点结束

// 伪代码
// dijkstra(g,d[],S){
//     for(顶点数){
//        u = d[u]最小的还未被访问的顶点的标号
//        把u标记访问
//        for(从u能到达的所有顶点v){ //开始访问
//            if(v未访问 且 以u 为中介点 使得源点到v的距离更小){
//               d[v] = d[u] +g[u][v]
//            }
//        }
//     }
//  }

// 时间复杂度O(顶点的2次方) 和prim算法一样，并无本质区别
// 单源最短路径 即有向图权值最小，无向图也可以用，也可以用BFS算
// 负权值不适用
bool vis[max_v] = {false}; //等同于S集合，true就是已加入
int d[max_v]; //源点到对应下标点的最短距离
int pre[max_v]; //记录该点的前置点，即中转点是哪一个
int n = 6; //顶点数

void dijkstra(int s, int **graph) {
    fill(d, d + max_v, inf);//初始所有点都不可达
    d[s] = 0;//起点为s，即源点

    for (int i = 0; i < n; ++i) {
        int u = -1, min = inf;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && d[j] < min) {
                u = i;
                min = d[i];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; ++v) {
            //d[v] 表示 源点 到 v的最短距离，d[u]+g[u][v],源点到u点的最短路径 + u到v的路径
            if (!vis[v] && graph[u][v] != inf && d[u]+graph[u][v]<d[v]){
                d[v] = d[u]+graph[u][v]; //最短距离
                pre[v]=u; //记录到达v的前面一个结点的值
            }
        }
    }
}