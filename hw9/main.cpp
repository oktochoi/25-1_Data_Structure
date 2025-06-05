#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include "BST.h"

using namespace std;

//divide punctuation from word and save it in punct
string stripPunctuation(const string& word, string& punct) {
    int i;
    for (i = word.length() - 1; i >= 0; --i) {
        if (ispunct(word[i]))
            punct = word[i] + punct;  
        else
            break; 
    }
    return word.substr(0, i + 1);
}

int main() {

    //1. input file name
    string textFileName, mapFileName;
    cout << "Enter text file name: ";
    cin >> textFileName;
    cout << "Enter map file name: ";
    cin >> mapFileName;

    BST bst;

    // 2. Read Map file, insert key:value
    ifstream mapFile(mapFileName);

    if (!mapFile) {
        cerr << "Cannot open map file." << endl;
        return 1;
    }

    string line;
    while (getline(mapFile, line)) {
        size_t colon = line.find(':'); //find(':') returns the index of the first occurrence of the ':' character in the string.
        if (colon != string::npos) { //npos The character you are looking for is not in the string
            string key = line.substr(0, colon);
            string value = line.substr(colon + 1);
            // Trim spaces
            key.erase(0, key.find_first_not_of(" \t")); //key.find_first_not_of(" \t") → " " or "\t" return first index of char
            key.erase(key.find_last_not_of(" \t") + 1); //erase : remove part of string
            value.erase(0, value.find_first_not_of(" \t"));
            value.erase(value.find_last_not_of(" \t") + 1);
            //insert BST
            bst.insert(key, value);
        }
    }
    mapFile.close();

    // 3. read textfile and print

    ifstream textFile(textFileName);
    if (!textFile) {
        cerr << "Cannot open text file." << endl;
        return 1;
    }

    while (getline(textFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) { //iss >> word -> save word divide into space, tab, \n
            string punct = "";
            string pure = stripPunctuation(word, punct); //save pure word without and punct
            string replacement = bst.find(pure); // if there is value return true
            if (!replacement.empty())
                cout << replacement << punct << " ";
            else
                cout << word << " ";
        }
        cout << endl;
    }

    textFile.close();
    return 0;
}
