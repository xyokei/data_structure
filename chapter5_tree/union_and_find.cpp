//
// Created by AutumnSigni on 2023/9/28.
//

#include <iostream>

using namespace std;

#define N 50

int father[N]; //一维数组表示并查集

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

void unionSet(int a, int b) {
    int faA = findFather(a);   //faA 是a元素所在的根结点
    int faB = findFather(b);   //faB 是b元素所在的根结点
    if (faA != faB) {         //不在同一集合
        father[faA] = faB; //将faA的父节点 指向 faB，变faB是faA的父节点
    }
}

void pathCompress(int x) {
    int a = findFather(x); //保存父节点
    while (x != father[x]) { //再走一遍修改每个结点的父节点值
        int temp = x; //x 会背覆盖
        x = father[x];
        father[temp] = a;
    }
}
void initSet() {
    for (int i = 0; i < N; ++i) {
        father[i] = i;//初始化并查集，初始值可设-1，一开始每个元素都是一个独立集合
    }
}