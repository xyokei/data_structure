//
// Created by AutumnSigni on 2023/10/4.
//

#include <iostream>
#include <queue>
#include "graph/graph_util.h"
#define max_size 10

using namespace std;
vector<int> adj[max_size];
bool inq[max_size] ={false};
int n = 6;//顶点数量

/**
 *任取一个顶点，访问该顶点的下一个顶点
 * @param i
 */
void DFS(int u){//要知道深度，要加参数int depth
    cout<<u<<' ';
    for (int j = 0; j < adj[u].size(); ++j) {
        //从u 出发到达的所有顶点v遍历
        int v = adj[u][j];
        if (!inq[v]){//该顶点未被访问
            cout<< v<<' ';
            DFS(v); //递归 深度 价格参数 depth+1
        }
    }
}
void DFSTrave(){
    for (int i = 0; i < n; ++i) {
        if (!inq[i]){//该顶点未被访问
            DFS(i);
        }
    }
}