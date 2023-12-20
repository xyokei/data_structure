//
// Created by AutumnSigni on 2023/12/10.
//
#include <stdio.h>

#define MAX_KEYS 4

struct BTreeNode {
    int num_keys;
    int keys[MAX_KEYS - 1];
    struct BTreeNode* children[MAX_KEYS];
    int is_leaf;
};

typedef struct BTreeNode BTreeNode;

// 在B树中查找键的函数
BTreeNode* search(BTreeNode* root, int key) {
    int i = 0;
    while (i < root->num_keys && key > root->keys[i]) {
        i++;
    }

    // 如果找到了键，返回当前节点
    if (i < root->num_keys && key == root->keys[i]) {
        return root;
    }

    // 如果是叶子节点，说明键不存在
    if (root->is_leaf) {
        return NULL;
    } else {
        // 递归查找子节点
        return search(root->children[i], key);
    }
}

int main() {
    // 创建一个简单的B树作为示例
    BTreeNode node1 = {3, {1, 3, 5}, {NULL, NULL, NULL}, 1}; // 叶子节点
    BTreeNode node2 = {2, {7, 9}, {NULL, NULL, NULL}, 1}; // 叶子节点
    BTreeNode root = {2, {4, 6}, {&node1, &node2, NULL}, 0}; // 非叶子节点，根节点

    // 在B树中查找键 5
    int key_to_search = 5;
    BTreeNode* result = search(&root, key_to_search);

    // 输出查找结果
    if (result != NULL) {
        printf("Key %d found in B tree.\n", key_to_search);
    } else {
        printf("Key %d not found in B tree.\n", key_to_search);
    }

    return 0;
}
