//
// Created by AutumnSigni on 2023/11/24.
//
#include <iostream>
#include <queue>

using namespace std;

// 二叉树节点的定义
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 非递归算法求二叉树高度
int getHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    int height = 0;
    while (!q.empty()) {
        int levelSize = q.size();  // 当前层的节点数

        // 将当前层的节点出队，并将下一层的节点入队
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();

            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }

        height++;  // 每遍历完一层，高度加1
    }

    return height;
}

int main() {
    // 示例：构建一个二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 调用非递归算法求二叉树高度
    int result = getHeight(root);

    // 输出结果
    cout << "二叉树的高度为: " << result << endl;

    return 0;
}
