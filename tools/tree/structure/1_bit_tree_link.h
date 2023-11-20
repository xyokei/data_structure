//
// Created by AutumnSigni on 2023/9/4.
//


#ifndef CHAPTER4_STRING_1_BIT_TREE_LINK_H
#define CHAPTER4_STRING_1_BIT_TREE_LINK_H

#define ElemType int
#define NULL nullptr

//二叉树的链式存储
/**
 *概念
 *  递归定义
 *
 *相关术语
 * m = 2 （m 表示 度）
 * --S = 2ⁿ-1 （n表层数）
 * --S 奇数时
 * --叶子结点 = 2ⁿ⁻¹
 * --分支结点 = 2ⁿ⁻¹ - 1
 * --叶子结点 = 分支结点 + 1
 * --S 偶数时
 * --叶子结点 = 2ⁿ⁻¹ - 2
 * --分支结点 = 2ⁿ⁻¹
 * --度为2的分支结点 = 2ⁿ⁻¹ - 3
 * --叶子结点 = 度为2的分支结点 + 1 这个重要
 * i <= ceil[S/2] ？分支 ： 叶子（这个是三元表达式）
 * 若 m=1的结点 唯一，则此结点序号 2ⁿ⁻¹ - 2
 * 二叉排序树
 *   大小顺序 左 根 右 ，先序遍历顺序输出 各子树也是二叉排序树
 *其他性质随机应变
**/
typedef struct BitNode {
    ElemType data;
    struct BitNode *lchild, *rchild;
    int ltag,rtag;//线索化用
    int layer; //层次遍历用
    int height;//AVL树用
} BitNode, *BitTree;

// 查找值为x 并修改成newData的结点
void modify(BitTree root, ElemType x, ElemType newData);

// 插入 flag = 1 BST插入，删除
// 插入 flag = 2 AVL树插入，删除
void insert_BST(BitTree &root, ElemType x);
void insert_AVL(BitTree &root, ElemType x);
void deleteNode_BST(BitTree &root, ElemType x);
void deleteNode_AVL(BitTree &root, ElemType x);

// 创建 用数组 创建
BitNode *create(ElemType data[], int n);

// 通过先序中序序列简历二叉树
BitNode *createByPreAndIn(int pre[],int preL, int preR, int in[],int inL, int inR);
BitNode *createByPreAndIn(int pre[],int preL, int preR, int in[],int inL, int inR);

// 通过后序中序序列简历二叉树
BitNode *createByPostAndIn(int post[],int postL, int postR, int in[],int inL, int inR);

// 新建结点
BitNode *newNode(int v);

// 先序
void preOrder(BitTree root);

// 中序
void inOrder(BitTree root);
void inOrder(BitTree root,bool flag);

// 后序
void postOrder(BitTree root);

// 层序
void layerOrder(BitTree root);

// 线索化
void createThread(BitTree root);


//遍历非递归
void inOrder2(BitTree root);
void preOrder2(BitTree root);
void postOrder2(BitTree root);
#endif //CHAPTER4_STRING_1_BIT_TREE_LINK_H
