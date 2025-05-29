#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack(int max_stack_size) { //generator
    top = -1;  //initalize top
    max_size = max_stack_size; 
    stack = new Element[max_size]; //use new keyword to make in heap
}

Stack::~Stack() {
    delete[] stack; // remove dynamic memory
}

void Stack::Push(Element item) {
    if (IsFullS())  //if stack is full
        cout << "Stack is full" << endl;
    else 
        stack[++top] = item;
}

Element Stack::Pop() {
    if (IsEmptyS()) {  //if stack is empty
        cout << "Stack is empty" << endl;
        return (Element)0;
    } else {
        return stack[top--];
    }
}

bool Stack::IsFullS() const {
    return (top == max_size - 1);
}

bool Stack::IsEmptyS() const {
    return (top == -1);
}

void Stack::Print() { //print values in stack below to up
    cout << "Stack: ";
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}
