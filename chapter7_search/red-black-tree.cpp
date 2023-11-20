//
// Created by AutumnSigni on 2023/11/3.
//
enum Color { RED, BLACK };

// 太难太难，肯定不考
struct Node {
    int data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;
};
class RedBlackTree {
public:
    RedBlackTree();
    void insert(int key);
    void remove(int key);
    void inOrderTraversal();

private:
    Node* root;
    void leftRotate(Node* x);
    void rightRotate(Node* y);
    void insertFixup(Node* z);
    void removeFixup(Node* x);
    Node* minimum(Node* node);
    Node* maximum(Node* node);
    void transplant(Node* u, Node* v);
    void inOrderTraversalHelper(Node* node);
};
