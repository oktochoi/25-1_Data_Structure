#include "contact.h"

//load people and divide into ;
void ContactManager::load(const string& filename){
    ifstream file(filename);
    string line;
    count = 0;

    while(getline(file, line) && count < 1000){
        istringstream iss(line);
        getline(iss, contacts[count].name, ';');
        getline(iss, contacts[count].birthday, ';');
        getline(iss, contacts[count].email, ';');        
        getline(iss, contacts[count].phone_number);
        count++;
    }
    file.close();
}
//remake file ofstream
void ContactManager::save(const string& filename) {
    ofstream file(filename);
    for (int i = 0; i < count; i++) {
        file << contacts[i].name << ";"
             << contacts[i].birthday << ";"
             << contacts[i].email << ";"
             << contacts[i].phone_number << endl;
    }
    file.close();
}
//make new contact and save it
void ContactManager::insert(const Contact& c){
    contacts[count++] = c;
}
//input name if name is in contact remove and pull number to front
void ContactManager::remove(const string& name){
    for(int i =0; i<count; i++){
        if(contacts[i].name == name){
            for(int j = i; j<count-1; j++){
                contacts[j] = contacts[j+1];
            }
            count --;
            cout << "remove " << name << endl;
            return;
        }
    }cout << "Not Found" << endl;
}
//search name
void ContactManager::retrieveName(const string& name){
    for(int i=0; i< count; i++){
        if(contacts[i].name == name){
            contacts[i].print();
            return;
        }
    }cout << "Not Found " << name << endl;
}
//search email
void ContactManager::retrieveEmail(const string& email){
    for(int i=0; i< count; i++){
        if(contacts[i].email == email){
            contacts[i].print();
            return;
        }
    }cout << "Not Found " << email << endl;
}
//sort by name : using insertation sort
void ContactManager::sortName(){
    for(int i = 1; i<count; i++){
        Contact temp = contacts[i];
        int j = i-1;
        while(j>=0 && contacts[j].name > temp.name){
            contacts[j+1] = contacts[j];
            j--;
        }
        contacts[j+1] = temp;
    }
}
//sort by birthday using insertation sort
void ContactManager::sortBirthday(){
    for(int i =1; i<count; i++){
        Contact temp = contacts[i];
        int j = i-1;
        while(j>=0 && contacts[j].birthday > temp.birthday){
            contacts[j+1] = contacts[j];
            j--;
        }
        contacts[j+1] = temp;
    }
}
//print all;
void ContactManager::print(){
    for(int i =0; i<count; i++){
        cout << contacts[i].name << ";"
             << contacts[i].birthday << ";"
             << contacts[i].email << ";"
             << contacts[i].phone_number << endl;
    }
}