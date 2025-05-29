#include "BST.h"
using namespace std;

//constructor 
BST::BST() {
    root = nullptr;
}

//Destructor
BST::~BST() {
    clear(root);
}

//recall itself and delete node
void BST::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

//public functions to call insert functions
void BST::insert(const string& key, const string& value) { 
    root = insert(root, key, value); 
}

Node* BST::insert(Node* node, const string& key, const string& value) {
    if (!node) return new Node(key, value);
    if (key < node->key)
        node->left = insert(node->left, key, value); // key < node -> key left
    else if (key > node->key)
        node->right = insert(node->right, key, value); //key > node -> key -> right
    return node; // key == node->key → duplicate
}

//public functions to call find functions
string BST::find(const string& key) const {
    return find(root, key);  
}

string BST::find(Node* node, const string& key) const {
    if (!node) return ""; //Not Found
    if (key == node->key) //Found
        return node->value;
    else if (key < node->key) //go left and recall find functions
        return find(node->left, key);
    else
        return find(node->right, key);//go right and recall find functions
}
