#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

struct Node {
    int key;
    string value;
    Node* left;
    Node* right;

    Node(int k, string val) : key(k), value(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    void inorder(Node* node);
    Node* insert(Node* node, int key, string value, bool& success);
    Node* remove(Node* node, int key, bool& success);
    Node* findMin(Node* node);

public:
    BST();
    ~BST();
    bool insert(int key, string value);
    bool remove(int key);
    void inorder();
    void clear(Node* node);
};

#endif
