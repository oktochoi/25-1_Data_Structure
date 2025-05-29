#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

int main() {
    BST tree;
    string command;
    int key;
    string value;

    while (true) {
        cout << "> ";
        cin >> command;

        if (command == "a") {
            cin >> key >> value;
            if (!tree.insert(key, value))
                cout << key << " is already in the tree" << endl;
        } else if (command == "d") {
            cin >> key;
            if (!tree.remove(key))
                cout << key << " is not in the tree" << endl;
        } else if (command == "p") {
            tree.inorder();
        } else if (command == "q") {
            break;
        } else {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}
