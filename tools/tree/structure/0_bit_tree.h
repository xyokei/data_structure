//
// Created by AutumnSigni on 2023/9/4.
//

#ifndef CHAPTER4_STRING_0_BIT_TREE_H
#define CHAPTER4_STRING_0_BIT_TREE_H
#define ElemType int
#define Max_Size 50

struct node{
    ElemType data;
    int lchild;
    int rchild;
    int layer;
}StaticBitNode[Max_Size];

int index;

// 查找值为x 并修改成newData的结点
void modify(int root, ElemType x, ElemType newData);

// 插入
void insert(int &root, ElemType x);

// 创建 用数组 创建
int create(ElemType data[], int n);

// 新建结点
int newNode(int x);

// 先序
void preOrder(int root);

// 中序
void inOrder(int root);

// 后序
void postOrder(int root);

// 层序
void layerOrder(int root);

#endif //CHAPTER4_STRING_0_BIT_TREE_H
