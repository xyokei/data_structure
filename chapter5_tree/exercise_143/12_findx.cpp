//
// Created by AutumnSigni on 2023/11/24.
//
#include <iostream>
#include <vector>

using namespace std;

// 二叉树节点的定义
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 查找值为x的结点，并打印祖先值
bool findX(TreeNode* root, int x, vector<int>& ancestors) {
    if (!root) {
        return false;
    }

    // 如果找到值为x的结点
    if (root->data == x) {
        // 打印祖先值
        for (int ancestor : ancestors) {
            cout << ancestor << " ";
        }
        cout << endl;
        return true;
    }

    // 在左子树中查找
    ancestors.push_back(root->data);
    if (findX(root->left, x, ancestors)) {
        return true;
    }
    ancestors.pop_back();  // 回溯

    // 在右子树中查找
    ancestors.push_back(root->data);
    if (findX(root->right, x, ancestors)) {
        return true;
    }
    ancestors.pop_back();  // 回溯

    return false;
}

int main() {
    // 示例：构建一个二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int x = 5;

    // 查找值为x的结点，并打印祖先值
    vector<int> ancestors;
    if (!findX(root, x, ancestors)) {
        cout << "未找到值为 " << x << " 的结点" << endl;
    }

    return 0;
}
