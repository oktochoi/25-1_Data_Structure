#ifndef STACK_H
#define STACK_H

typedef int Element; //using typedef to int,

class Stack {
private:
    int top;
    int max_size;
    Element* stack;

public:
    Stack(int max_stack_size); //generator
    ~Stack(); //remover

    void Push(Element item); //push
    Element Pop();  //pop
    bool IsFullS() const; //isfull
    bool IsEmptyS() const; //isempty
    void Print();  //print all
};

#endif
