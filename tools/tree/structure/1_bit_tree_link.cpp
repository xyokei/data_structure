//
// Created by AutumnSigni on 2023/9/4.
//

#include "1_bit_tree_link.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/**
 * 查找值为x 并修改成newData的结点
 * @param root 根节点
 * @param x 旧值
 * @param newData 新值
 */
void modify(BitTree root, ElemType x, ElemType newData) {
    if (root == nullptr) {
        return;
    }
    if (root->data == x) {
        root->data = newData;
    }
    // 左子树递归
    modify(root->lchild, x, newData);
    // 右子树递归
    modify(root->rchild, x, newData);

}

// 插入
void insert_BST(BitTree &root, ElemType x) {
    if (root == nullptr) {
        root = newNode(x);
        return;
    }
    if (x == root->data) {
        return;
    } else if (x < root->data) {
        insert_BST(root->lchild, x);
    } else {
        insert_BST(root->rchild, x);
    }
}

BitNode *findMax(BitNode *root) {
    while (root->rchild != NULL) {
        root = root->rchild;
    }
    return root;
}

BitNode *findMin(BitNode *root) {
    while (root->lchild != NULL) {
        root = root->lchild;
    }
    return root;
}

/**
 *
 * @param root
 * @param x
 */
void deleteNode_BST(BitTree &root, ElemType x) {
    //简单写法，当前结点 与 x 值比较得3种情况
    if (root == nullptr) return;
    if (root->data == x) {
        if (root->lchild == NULL && root->rchild == NULL) {
            root = NULL; //直接置空，父节点就找不到它了，
        } else if (root->lchild != NULL) {//优先左子树不空去替换，即先替换前驱,这样删会造成树越来越高
            BitNode *pre = findMax(root->lchild);//取左子树最右下结点，即前驱
            root->data = pre->data;      //当前结点的值替换成 前驱
            deleteNode_BST(root->lchild, pre->data); //递归删除左子树下的 "前驱"
        } else if (root->rchild != NULL) {
            BitNode *next = findMin(root->rchild);//取右子树最左下结点，即后继
            root->data = next->data;  //替换
            deleteNode_BST(root->lchild, next->data);//递归删除左子树下的 "后继"
        }
    } else if (root->data > x) {//比当前结点小 进左子树删除
        deleteNode_BST(root->lchild, x);
    } else {
        deleteNode_BST(root->rchild, x);//比当前结点大 进右子树删除
    }
}

// 当树中没有height时，求高度
int getMaxHeight(BitNode *root) {
    if (root == nullptr) return 0;//叶子结点高度 0
    int leftHeight = getMaxHeight(root->lchild);
    int rightHeight = getMaxHeight(root->rchild);
    return max(leftHeight, rightHeight) + 1;
}

// 求树高 此方法根节点的高度就是树的高度，为AVL专门写的
// 即每个height有值了
int getHeight(BitNode *root) {
    if (root == NULL) return 0;
    return root->height;
}

// 求平衡因子，间接用高度求，因为无法直接记录平衡因子
int getBalanceFactor(BitNode *root) {
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(BitNode *root) {
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

// 左旋
void L(BitNode *&root) {//设root 为A结点
    BitNode *temp = root->rchild;  //设右孩子为B，即让B成为根结点
    root->rchild = temp->lchild; //B的左子树成为A的右子树
    temp->lchild = root; // A成为B的左子树
    updateHeight(root); //更新A的高度
    updateHeight(temp);//更新B高度
    root = temp; //根结点设成 B
}

//右旋 与左旋是互逆操作，
void R(BitNode *&root) {//设root 为B结点
    BitNode *temp = root->lchild;  //设左孩子为A，即让A成为根结点
    root->lchild = temp->rchild; //A的右子树成为B的左子树
    temp->rchild = root; // B成为A的右子树
    updateHeight(root); //更新B的高度
    updateHeight(temp);//更新A高度
    root = temp; //根结点设成 B
}

// 插入
void insert_AVL(BitTree &root, ElemType x) {
    if (root == nullptr) {
        root = newNode(x);
        return;
    }
    if (x < root->data) { //默认数据即是权值
        insert_AVL(root->lchild, x);//插到左子树
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->lchild) == 1) { //LL型
                R(root);
            } else if (getBalanceFactor(root->lchild) == -1) {//LR型
                L(root->lchild);
                R(root);
            }
        }
    } else {
        insert_AVL(root->rchild, x);//插到右子树
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->lchild) == -1) { //RR型
                L(root);
            } else if (getBalanceFactor(root->lchild) == 1) {//RL型
                R(root->lchild);
                L(root);
            }
        }
    }
}

// 创建 用数组 创建
BitNode *create(ElemType data[], int n) {
    BitNode *root = nullptr;
    for (int i = 0; i < n; ++i) {
        insert_BST(root, data[i]);
    }
    return root;
}

// 通过先序中序序列遍历二叉树
/**
 * 1.先序序列定根
 * 2.中序序列定左右子树
 *
 * 先序序列第一个值是子树根节点，其对应在中序序列位置的左边就是该结点的左子树，右边就是右子树
 * @param pre 先序序列
 * @param preL 当前序列左下标
 * @param preR 当前序列右下标
 * @param in 中序序列
 * @param inL 当前序列左下标
 * @param inR 当前序列右下标
 * @return
 */
BitNode *createByPreAndIn(int pre[], int preL, int preR, int in[], int inL, int inR) {
    if (preL > preR) return nullptr;
    BitNode *root = new BitNode;
    root->data = pre[preL]; //第一个当前子树就是根结点
    int i;//i 中序序列中与先序序列根节点值相同的序列位置
    for (i = inL; i < inR; ++i) {
        if (in[i] == pre[preL]) {
            break;
        }
    }
    int numLeft = i - inL; //左子树结点个数 来定左序列区间
    root->lchild = createByPreAndIn(pre, preL + 1, preL + numLeft, in, inL, i - 1);//左子树递归构建，
    root->rchild = createByPreAndIn(pre, preL + numLeft + 1, preR, in, i + 1, inR);//右子树递归构建
    return root;
}
// 通过后序中序序列建立二叉树
/**
 * 1.后序定子树根
 * 2.中序定左右子树序列
 * @param post
 * @param postL
 * @param postR
 * @param in
 * @param inL
 * @param inR
 * @return
 */
BitNode *createByPostAndIn(int post[], int postL, int postR, int in[], int inL, int inR) {
    if (postL > postR) return nullptr;
    BitNode *root = new BitNode;
    root->data = post[postR]; //第一个当前子树就是根结点
    int i;//i 中序序列中与先序序列根节点值相同的序列位置
    for (i = inL; i < inR; ++i) {
        if (in[i] == post[postR]) {
            break;
        }
    }
    int numLeft = i - inL; //左子树结点个数 来定左序列区间
    root->lchild = createByPreAndIn(post, postL, postL + numLeft - 1, in, inL, i - 1);//左子树递归构建，
    root->rchild = createByPreAndIn(post, postL + numLeft, postR - 1, in, i + 1, inR);//右子树递归构建
    return root;
}

// 新建结点
BitNode *newNode(int v) {
    BitNode *node = new BitNode;//这是c++写法
    // BitNode *node1 =(BitNode*)malloc(sizeof(BitTree)); //这是c 写法
    node->data = v;
    node->height = 1;
    node->lchild = node->rchild = NULL;
    return node;
}

// 先序
void preOrder(BitTree root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preOrder(root->lchild);
    preOrder(root->rchild);

}

// 中序
void inOrder(BitTree root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->lchild);
    cout << root->data << " ";
    inOrder(root->rchild);
}

// 后序
void postOrder(BitTree root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->lchild);
    postOrder(root->rchild);
    cout << root->data << " ";
}

// 层序
void layerOrder(BitTree root) {
    queue<BitNode *> q;// 保存的是结点地址 因为存放一个node时 队列是保存副本的，遇到想要修改数据时 修改队列对原结点无作用。
    // 涉及结点 层数修改 所以要保存地址，
    root->layer = 1;
    q.push(root);

    while (!q.empty()) {
        BitNode *now = q.front();
        q.pop();
        cout << now->data << " ";
        if (now->lchild != nullptr) {
            now->lchild->layer = now->layer + 1;  //加层
            q.push(now->lchild); //左子树非空
        }
        if (now->rchild != nullptr) {
            now->rchild->layer = now->layer + 1;
            q.push(now->rchild); //右子树非空
        }
    }
}

void inThread(BitNode *&p, BitNode *&pre) {
    if (p == nullptr) {
        return;
    }
    inThread(p->lchild, pre);  //中序遍历
    // visit 部分
    if (p->lchild == nullptr) {  //当前结点左子树空 建立前驱线索
        p->lchild = pre;       //第一个访问的结点时 pre 为空
        p->ltag = 1;             //更新标志位
    }
    if (pre != nullptr && pre->rchild == nullptr) { //前驱结点的右子树为空，建立前驱的后继
        pre->rchild = p;       //建立后继，至于为什么不能建立当前结点的后继，是因为当前结点后面还没访问
        pre->ltag = 1;
    }
    pre = p;   //更新pre
    inThread(p->rchild, pre); //中序遍历
}

// 线索化
void createThread(BitTree root) {
    BitNode *pre = nullptr;
    if (root != nullptr) {
        inThread(root, pre);
        pre->rchild = nullptr;  //处理最后一个结点
        pre->ltag = 1;
    }
}

BitNode *firstNode(BitNode *p) {
    while (p->ltag == 0) p = p->lchild; //第一个结点，最左下结点
    return p;
}

BitNode *nextNode(BitNode *p) {
    if (p->rtag == 0) return firstNode(p->rchild); //右子树的最左下结点
    else return p->rchild; //直接返回后继
}

void inOrder(BitNode *root, bool flag) {
    for (BitNode *p = firstNode(root); p != nullptr; p = nextNode(p)) {
        cout << p->data << " ";
    }
}

//遍历非递归
void inOrder2(BitTree root) {
    stack<BitNode *> s;
    BitNode *p = root;
    while (p || s.empty()) {
        while (p) {
            s.push(p);
            p = p->lchild;
        }
        p = s.top();
        //visit p
        s.pop();
        p = p->rchild;
    }

}

void preOrder2(BitTree root) {
    if (!root) return;
    stack<BitNode *> s;
    s.push(root);
    while (!s.empty()) {
        BitNode *node = s.top();
        // visit(node);
        s.pop();
        if (node->rchild) s.push(node->rchild);
        if (node->lchild) s.push(node->lchild);
    }
}

void postOrder2(BitTree root) {
    if (!root) return;
    stack<BitNode *> s1,s2;
    s1.push(root);
    while (!s1.empty()) {
        BitNode *node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->lchild) s1.push(node->lchild);
        if (node->rchild) s1.push(node->rchild);
    }
    while (!s2.empty()) {
        // visit s2.top
        s2.pop();
    }
}

// 先序线索化
void preThread(BitNode *&p, BitNode *&pre) {
    if (p == nullptr) {
        return;
    }
    if (p->lchild == nullptr) {
        p->lchild = pre;
        p->ltag = 1;
    }
    if (pre != nullptr && pre->rchild == nullptr) {
        pre->rchild = p;
        pre->rtag = 1;
    }
    pre = p;
    if (p->ltag == 0) {  // 避免重复线索化
        preThread(p->lchild, pre);
    }
    if (p->rtag == 0) {
        preThread(p->rchild, pre);
    }
}

void createPreThread(BitNode *root) {
    BitNode *pre = nullptr;
    if (root != nullptr) {
        preThread(root, pre);
    }
}

//后序线索化
void postThread(BitNode *&p, BitNode *&pre) {
    if (p == nullptr) {
        return;
    }
    postThread(p->lchild, pre);
    postThread(p->rchild, pre);
    if (p->lchild == nullptr) {
        p->lchild = pre;
        p->ltag = 1;
    }
    if (pre != nullptr && pre->rchild == nullptr) {
        pre->rchild = p;
        pre->rtag = 1;
    }
    pre = p;
}

void createPostThread(BitNode *root) {
    BitNode *pre = nullptr;
    if (root != nullptr) {
        postThread(root, pre);
    }
}