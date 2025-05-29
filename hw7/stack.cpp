#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack() : topNode(nullptr) {} //constructor 

Stack::~Stack() { // Destructor
    while (topNode != nullptr) { 
        Node* temp = topNode;
        topNode = topNode->next; 
        delete temp;
    }
}

//Pass the current topNode to the next node
void Stack::push(const string& name, int id, const string& email) {
    topNode = new Node(name, id, email, topNode);
}

//pop
bool Stack::pop(string& name, int& id, string& email) {
    if (isEmpty()) return false;

    Node* temp = topNode;
    name = topNode->name;
    id = topNode->id;
    email = topNode->email;
    topNode = topNode->next;

    delete temp;
    return true;
}

//isEmpty
bool Stack::isEmpty() const {
    return topNode == nullptr;
}
