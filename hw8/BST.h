#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

// define BST node
struct Node {
    int key; 
    string value; 
    Node* left;
    Node* right;

    //constructor
    Node(int k, string val) : key(k), value(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    void inorder(Node* node);  //recrusive 
    Node* insert(Node* node, int key, string value, bool& success); //insert recrusive 
    Node* remove(Node* node, int key, bool& success); //remove recrusive
    Node* findMin(Node* node); //find minimum key node

public:
    BST(); //constructor
    ~BST(); //destructor
    bool insert(int key, string value); //insert
    bool remove(int key); //remove, success -> true, 
    void inorder();
    void clear(Node* node); //remove all node
};

#endif
