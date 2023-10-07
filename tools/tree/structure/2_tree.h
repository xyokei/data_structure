//
// Created by AutumnSigni on 2023/9/6.
//

#include <vector>
using namespace std;
#ifndef CHAPTER4_STRING_2_TREE_H
#define CHAPTER4_STRING_2_TREE_H

#define ElemType int
#define Max_Size 50

// 3种表示方法
// 双亲表示法
// 孩子表示法
// 孩子兄弟表示法

// 为了做题方便，均用孩子表示法的静态写法做题
struct tree{
    ElemType data;
    vector<int> child; //所有子节点的下标，当然也可以用 int child[Max_Size] 存放下标，但是vector是变长数组，节省空间
    int layer;//存放层数
}Tree[Max_Size];
// 如果把数据域去掉，即为 图的领接表法的结构体

// 树和森林的转换？应该不会考算法写的吧，只是出选择和判断
// 给定一颗树，其二叉树唯一
// 转换规则：左孩子右兄弟，每个结点 二叉树的每个节点左指针指向对应树节点的第一个孩子，右指针指向对应树节点的兄弟，根永远没有右
// 森林转换和树类似，先将每个森林转换成树，然后再转成二叉树
// 森林 树 二叉树 转换唯一，画几个图就会了，不难

// DFS，先根遍历
void preOrder(int root);
void postOrder();
// BFS
void layerOrder(int root);


// typedef struct {
//     ElemType data;
//     int parent;
// }PTNode;
// typedef struct{
//     PTNode nodes[Max_Size];
//     int n;
// }PTree;

typedef struct CSNode{
    ElemType data;
    struct CSNode *firstchild,*nextsibling;
}CSNode, *CSTree;

#endif //CHAPTER4_STRING_2_TREE_H
