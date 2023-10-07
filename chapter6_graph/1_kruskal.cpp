//
// Created by AutumnSigni on 2023/10/6.
//

//边贪心算法

//思想：初始设定每个顶点都是一个连通分量，图集G(V,E),树集T(U,TE) 设顶点数n,边数 e，新树T
//      初始设置 U = V,此时TE为空，
//      按照边从小到大顺序依次考察E的边，(循环)
//         若此边属于T的两个不同连通分量，此边并入TE
//         否则 舍弃此边，防止造成回路
//         若此时T中只有一个连通分量，则跳出循环，即 te的边数 = u - 1(顶点数减一)

//伪代码
// void kruskal(G, T) {
//     边权从小到大排序
//     for(从小到大的所有边枚举)
//         if(测试边的两个顶点属于不同的连通分量) {
//            此边加入 T
//            最小生成树 边数 +1
//            if(U -1 == 边数) 跳出循环
//
//  时间复杂度O(ElogE)，综合prim看，prim不看边只看顶点，因此边多的选prim
//  边少的选kruskal

// 实现
// 两个问题，判断两个边属于不同分量，用并查集 的查
// 将测试边加入T 用并查集的并
#include <iostream>
#include "algorithm"

using namespace std;
#define max_v 6
#define max_e 100
bool vis[max_v] = {false};
int d[max_v];
int pre[max_v];
int father[max_v];

struct edge {
    int u, v;
    int cost;
} E[max_e];

bool cmp(edge a, edge b) {
    return a.cost < b.cost;
}
int findFather(int x) {
    int a = x;
    while (x != father[x]) { //循环获得自己的父节点
        x = father[x];
    }
    // 此时 x 变成父节点
    while (a!=father[a]){//再走一遍修改每个结点的父节点值
        int z = a; //保存此时a的值
        a = father[a]; //为了下次循环
        father[z] =x; //将a的父节点修改成x;
    }
    return x;
}
/**
 * 直接求最短路径之和
 * @param n 顶点数
 * @param m 边数
 * @return
 */
int kruskal(int n, int m) { //n 顶点数 m 边数
    int ans = 0, num_edge = 0;
    for (int i = 0; i < n; ++i) { //顶点编号从0开始，若从1 修改
        father[i] = i;
    }
    sort(E, E + m, cmp);
    for (int i = 0; i < m; ++i) {
        int faU = findFather(E[i].u);   //faU 是u元素所在的根结点
        int faV = findFather(E[i].v);   //faV 是v元素所在的根结点
        if (faU != faV) {         //不在同一集合
            father[faU] = faV; //将faA的父节点 指向 faB，变faB是faA的父节点
            ans+=E[i].cost;
            num_edge++;
            if (num_edge == n - 1) break;
        }
    }
    if (num_edge != n-1) return -1; //不连通
    else return ans;
}

int main(){
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin>>E[i].u>>E[i].v>>E[i].cost;
    }
    int ans = kruskal(n,m);
    cout<<ans<<endl;
    return 0;
}