#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Contact{
public:
    string name;
    string birthday;
    string email;
    string phone_number;

    void print() const{
        cout << name << ";" << birthday << ";" << email << ";" << phone_number<< endl;
    }
};

class ContactManager{
private:
    Contact contacts[1000]; //max people 1000
    int count = 0 ; //present save person
public:
    void load(const string& filename);
    void save(const string& filename);
    void insert(const Contact& c);
    void remove(const string& name);
    void retrieveName(const string& name);
    void retrieveEmail(const string& email);
    void sortName();
    void sortBirthday();
    void print();
};