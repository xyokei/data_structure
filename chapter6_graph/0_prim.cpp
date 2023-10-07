//
// Created by AutumnSigni on 2023/10/4.
//

//最小生成树，无向带权连通图，带权路径之和最小
#include <iostream>

using namespace std;
#define max_v 6
#define inf 0x3fffffff //有符号的最大整数

// 思想
// 顶点集合V 任取一个顶点，做根节点加入集合S，
// 1、每次从V-S(V中不含S的顶点)中选择与集合S距离最近（即权值最小）的一个顶点加入S
//
// 2、重复1，直至V-S为空集，即V=S

//
// 伪代码：
// void prim(G,T)  {
//      令树为空集,设G中顶点集合为V ,树的顶点集合U
//      将G中任一顶点加入到T
//      while(V-U不是空集)
//           (u,v)是u属于U与 v属于V-U且权值最小的边
//           边归入树
//           顶点归入树
//

/**
 * 实现：
 * 用 bool 数组表示集合 V已经被加入（即是否访问），全为true即循环结束
 * 用int 数组 d[] 存放顶点Vi与 集合S最短距离
 *
 * 时间复杂度 O(n^2) n就是顶点个数
 * 空间复杂度 O(n)
 */
int graph[max_v][max_v];
bool vis[max_v] = {false}; //顶点是否访问
int d[max_v]; //对应下标到达集合S的最短路径长度，即对应下标所连边的最小权的边的权值
int pre[max_v]; //对应下边的前置点值
int n, m; //顶点边数

int prim() {
    //初始设定任意顶点不可达
    for (int i = 0; i < n; ++i) { //c++函数 fill(d,d+max_v,inf)
        d[i] = inf;}
    d[0] = 0;//0号顶点到达自身顶点距离为0
    int ans = 0; //所求的带权路径之和最小，即结果
    for (int i = 0; i < n; ++i) {
        int u = -1, min = inf;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && d[j] < min) { //未访问顶点中，距离最小的，一开始肯定是 0
                u = j;
                min = d[j];
            }
        }
        if (u == -1) return -1;//找不到的时候，即存在不连通的点，无最小生成树
        vis[u] = true; //设置访问
        ans += d[u];
        // 访问过程，将该点的所有边枚举，
        // 第一轮访问点0 d[v]的值更新成0 4 inf inf 1 2
        // 第二轮访问点4 d[v]的值更新成0 4 inf 4 1 2
        // 第三轮访问点5 d[v]的值更新成0 3 5 4 1 2
        // 第四轮访问点1 d[v]的值不需要更新
        // 第四轮访问点3
        // 第五轮访问点2
        for (int v = 0; v < n; ++v) { //邻接矩阵判断邻接结点只能遍历所有结点
            //未访问 且 u能到达v  且 以u为中介点可以使 v 离集合S更近
            if (!vis[v] && graph[u][v] != inf && graph[u][v] < d[v]) {///
                d[v] = graph[u][v];/// 边归入树
                pre[v] = u; //v的前置点  顶点归入树
            }
        }
    }
    return ans;
}

int main() {
    int u, v, w;
    cin >> n >> m;
    fill(graph[0], graph[0] + max_v * max_v, inf);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        graph[u][v] = graph[v][u] = w; //无向图
    }
    int ans = prim();
    cout << ans << endl;
    for (int i = 0; i < n; ++i) {
        cout << d[i] << ' ';
    }
    cout<<endl;
    for (int i = 0; i < n; ++i) {
        cout << pre[i] << ' ';
    }
}