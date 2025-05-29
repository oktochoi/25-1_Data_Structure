#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

/*
This system implements a Binary Search Tree (BST) to manage key-value pairs. 
It supports operations such as inserting a node, removing a node, and printing all nodes in order. 
The tree maintains sorted order based on the integer key of each node.
*/

int main() {
    BST tree;
    string command;
    int key;
    string value;

    while (true) {
        cout << "> ";
        cin >> command;

        if (command == "a") { //insert, if returns false -> duplicate
            cin >> key >> value;
            if (!tree.insert(key, value)) 
                cout << key << " is already in the tree" << endl;
        } else if (command == "d") { //remove, if returns false -> there is no value
            cin >> key;
            if (!tree.remove(key))
                cout << key << " is not in the tree" << endl;
        } else if (command == "p") {//print (in inorder)
            tree.inorder();
        } else if (command == "q") {//quit
            break;
        } else {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}
