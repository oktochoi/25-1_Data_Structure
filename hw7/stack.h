#include <string>
using namespace std;

struct Node { 
    string name;
    int id;
    string email;
    Node* next; //next node 

    Node(const string& name, int id, const string& email, Node* next = nullptr) // constructor and Member initializer list
        : name(name), id(id), email(email), next(next) {}
};

class Stack {
private:
    Node* topNode;

public:
    Stack();
    ~Stack();

    void push(const string& name, int id, const string& email);
    bool pop(string& name, int& id, string& email);
    bool isEmpty() const;
};
