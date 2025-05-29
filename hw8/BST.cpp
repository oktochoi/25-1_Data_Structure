#include "BST.h"
#include <iostream>
using namespace std;

//constructor
BST::BST() {
    root = nullptr;
}

//destructor
BST::~BST() {
    clear(root);
}

//recrusive deallocate memory
void BST::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

//call private insert function
bool BST::insert(int key, string value) {
    bool success = true;
    root = insert(root, key, value, success);
    return success;
}

//insert function
Node* BST::insert(Node* node, int key, string value, bool& success) {
    
    if(!node) //space is Empty
        return new Node(key, value);

    if(key == node->key) { //if duplicate return false
        success = false;
        return node;
    }else if (key < node->key) { //move to left subtree
        node->left = insert(node->left, key, value, success);
    }else { //move to right subtree
        node->right = insert(node->right, key, value, success);
    }

    return node;
}

//call private remove function
bool BST::remove(int key) {
    bool success = false;
    root = remove(root, key, success);
    return success;
}

Node* BST::remove(Node* node, int key, bool& success) {
    if (!node) 
        return nullptr;

    if (key < node->key) { //move to left subtree
        node->left = remove(node->left, key, success);
    } else if (key > node->key) {//move to right subtree
        node->right = remove(node->right, key, success);
    } else {
        success = true; //find node 
        // Case 1: No child
        if (!node->left && !node->right) {
            delete node;
            return nullptr;
        }
        // Case 2: One child
        else if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        // Case 3: Two children right node is be a root
        else {
            Node* temp = findMin(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = remove(node->right, temp->key, success); // remove min node from right
        }
    }

    return node;
}

//findmin move left continue
Node* BST::findMin(Node* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

//call private inoder function
void BST::inorder() {
    inorder(root);
    cout << endl;
}

// print left -> present -> right node
void BST::inorder(Node* node) {
    if (node) {
        inorder(node->left);
        cout << "(" << node->key << ", " << node->value << ") ";
        inorder(node->right);
    }
}
