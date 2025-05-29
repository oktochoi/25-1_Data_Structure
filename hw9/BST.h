#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

struct Node {
    string key;  //source word (search)
    string value;  //target word  (change)
    Node* left;
    Node* right;

    Node(string k, string v)
        : key(k), value(v), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, const string& key, const string& value); //insert function
    string find(Node* node, const string& key) const; //find key in node, if not return ""
    void clear(Node* node); //allocate memory

public:
    BST(); //constructor
    ~BST(); //destructor
    void insert(const string& key, const string& value); //call insert function
    string find(const string& key) const;  // call find function
};

#endif
