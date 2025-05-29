#include <iostream>
#include <fstream>
#include <sstream>
#include "stack.h"
using namespace std;

//Read a file and print the lines in the reverse order. 

int main() {
    string filename;
    cout << "Enter input file name: ";
    getline(cin, filename);

    //This is a class that helps you bring things from a file and input them into a program.
    ifstream infile(filename); //ifstream = input file stream 
    /*
    Opens the file with the name specified in filename in read mode.

    If the file is successfully opened, data can be read from it through the infile object.

    If the file cannot be opened (e.g., the file does not exist, or there is insufficient permission), the infile object is in the failed state.
    */

    Stack stack;
    string line;

    // read oneline and push
    while (getline(infile, line)) {
        istringstream iss(line); //divide file, to line
        string name, id_str, email;

        // format: name, id, email 
        if (getline(iss, name, ',') &&
            getline(iss, id_str, ',') &&
            getline(iss, email)) {

            // trim
            auto trim = [](string& s) {
                size_t start = s.find_first_not_of(" \t");
                size_t end = s.find_last_not_of(" \t");
                if (start == string::npos) s = "";
                else s = s.substr(start, end - start + 1);
            };

            trim(name);
            trim(id_str);
            trim(email);

            int id = stoi(id_str); //stoi : string to integer 

            stack.push(name, id, email); //push
        } //and repeat
    }

    infile.close(); // close file

    // pop in stack and print reverse (id, name, email )
    string name, email;
    int id;

    while (stack.pop(name, id, email)) {
        cout << id << ", " << name << ", " << email << endl;
    }

    return 0;
}
