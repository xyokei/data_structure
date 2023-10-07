//
// Created by AutumnSigni on 2023/9/4.
//

#include "0_bit_tree.h"
#include <iostream>
#include <queue>
using namespace std;

// 查找值为x 并修改成newData的结点
void modify(int root, ElemType x, ElemType newData){
    if (root ==-1) return;
    if (StaticBitNode[root].data == x){
        StaticBitNode[root].data =newData;
    }
    modify(StaticBitNode[root].lchild,x,newData);
    modify(StaticBitNode[root].rchild,x,newData);
}

// 插入
void insert(int &root, ElemType x){ //引用参数
    if (root == -1) {
        root = newNode(x);//结点直接新建
        return;
    }
    if (x >1){
        insert(StaticBitNode[root].lchild,x);
    } else{
        insert(StaticBitNode[root].rchild,x);
    }
}

// 创建 用数组 创建
int create(ElemType data[], int n){
    int root = -1;
    for (int i = 0; i < n; ++i) {
        insert(root,data[i]);
    }
    return root;
}

// 新建结点
int newNode(int x){
    StaticBitNode[index].data = x;
    StaticBitNode[index].lchild =-1;
    StaticBitNode[index].rchild =-1;
    return index++;
}

// 先序
void preOrder(int root){
    if (root == -1)return;
    cout << StaticBitNode[root].data << " ";
    preOrder(StaticBitNode[root].lchild);
    preOrder(StaticBitNode[root].rchild);
}

// 中序
void inOrder(int root){
    if (root == -1)return;
    inOrder(StaticBitNode[root].lchild);
    cout << StaticBitNode[root].data << " ";
    inOrder(StaticBitNode[root].rchild);
}

// 后序
void postOrder(int root){
    if (root == -1)return;
    postOrder(StaticBitNode[root].lchild);
    postOrder(StaticBitNode[root].rchild);
    cout << StaticBitNode[root].data << " ";
}

// 层序
void layerOrder(int root){
    queue<ElemType> q;// 保存的是结点地址 因为存放一个node时 队列是保存副本的，遇到想要修改数据时 修改队列对原结点无作用。
    // 涉及结点 层数修改 所以要保存地址，
    StaticBitNode[root].layer = 1;
    q.push(root);
    while (!q.empty()) {
        ElemType now = q.front();
        q.pop();
        cout << StaticBitNode[root].data << " ";
        if (StaticBitNode[root].lchild != -1) {
            StaticBitNode[StaticBitNode[now].lchild].layer =StaticBitNode[now].layer  + 1;  //加层
            q.push(StaticBitNode[root].lchild); //左子树非空
        }
        if (StaticBitNode[root].rchild != -1) {
            StaticBitNode[StaticBitNode[now].rchild].layer =StaticBitNode[now].layer  + 1;  //加层
            q.push(StaticBitNode[root].rchild); //左子树非空
        }
    }
}