#include <iostream>
#include "stack.h"

//Input Create a size 5 stack Push 1 and 3 and output Pop and remove 3 Output again

using namespace std;

int main() {
    Stack *stack = new Stack(5);
    stack->Push(1);
    stack->Push(3);
    stack->Print();

    cout << "Pop: " << stack->Pop() << endl;
    stack->Print();

    delete stack;

    return 0;
}