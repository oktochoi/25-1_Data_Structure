#include <iostream>
#include "contact.h"
using namespace std;

//load, save, insert, delete, retrieve, sort, print (you can implement them as member functions of class)

int main() {
    string filename;
    cout << "Input filename: ";
    cin >> filename;

    ContactManager cm;

    while (true) {
        cout << "1 : load  2 : save  3 : insert  4 : delete  5 : retrieve_name  6 : retrieve_email 7 : sort_name  8 : sort_birthday  9 : print_all  10 : quit" << endl;
        cout << "optioins: ";

        string op;
        cin >> op;
        cin.ignore(); 

        if (op == "1") { //load
            cm.load(filename);
        } else if (op == "2") { //save
            cm.save(filename);
        } else if (op == "3") { //insert
            Contact newContact;
            cout << "Input name: ";
            getline(cin, newContact.name);
            cout << "Input birthday (YYYYMMDD): ";
            getline(cin, newContact.birthday);
            cout << "Input email: ";
            getline(cin, newContact.email);
            cout << "Input phone_number: ";
            getline(cin, newContact.phone_number);  
            cm.insert(newContact);
        } else if (op == "4") { //delete
            string name;
            cout << "Input name: ";
            getline(cin, name);
            cm.remove(name);
        } else if (op == "5") {//search by name
            string name;
            cout << "Input name: ";
            getline(cin, name);
            cm.retrieveName(name);
        } else if (op == "6") {//search by email
            string email;
            cout << "Input email: ";
            getline(cin, email);
            cm.retrieveEmail(email);
        } else if (op == "7") {//sort by name
            cm.sortName();
        } else if (op == "8") {//sort by birthday
            cm.sortBirthday();
        } else if (op == "9") {//print all
            cm.print();
        } else if (op == "10") {
            break;
        } else {
            cout << "Wrong input. Please enter a number between 1 and 10." << endl;
        }
    }

    return 0;
}
