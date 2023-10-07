//
// Created by AutumnSigni on 2023/9/6.
//

#include "2_tree.h"
#include <iostream>
#include <queue>

using namespace std;

// DFS，先根遍历
void preOrder(int root) {
    cout << Tree[root].data;
    for (int i = 0; i < Tree[root].child.size(); ++i) {
        preOrder(Tree[root].child[i]);
    }
}

void postOrder();

// BFS
void layerOrder(int root) {
    queue<int> q;
    q.push(root);
    Tree[root].layer = 0;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        cout << Tree[front].data << " ";
        for (int i = 0; i < Tree[front].child.size(); ++i) {
            int child = Tree[front].child[i];
            Tree[child].layer = Tree[front].layer + 1;
            q.push(child);
        }
    }
}