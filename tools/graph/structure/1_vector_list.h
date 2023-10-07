//
// Created by AutumnSigni on 2023/10/4.
//

#ifndef ALGORITHM_1_VECTOR_LIST_H
#define ALGORITHM_1_VECTOR_LIST_H

typedef char vertexType;
typedef int edgeType;
typedef struct arcNode {
    int adj_v;    //弧指向的顶点
    struct arcNode *next;  //指向下一条弧的指针
} ArcNode;

typedef struct vNode {
    vertexType data;    //顶点数据
    arcNode *first;     //该顶点指向的第一条弧指针
} vNode, AdjList[max_size];   //顶点数组

typedef struct {
    AdjList vertices;  //领接表
    int v_num, arc_num;
} List_Graph;
// List_Graph graph;

// 算法实现
//顶点编号是数字直接 vector<int> adj[N]; N是顶点数量，adj[i].0的值表示第i个顶点的第一条边连的顶点
// adj[u]存放从u能到达的所有顶点
// 记录有向边的信息
typedef struct graph_Node {
    int v; //边的终点编号
    int w; //边的权值
    graph_Node(int _v, int _w) : v(_v), w(_w) {}
} graph_Node;
// vector<Graph_Node> adj[N],顶点数量N，adj[i].push_back(graph_Node(3,4))
// push_back添加 pop_back 删除，size()长度
#endif //ALGORITHM_1_VECTOR_LIST_H
