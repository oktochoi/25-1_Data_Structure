#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include "BST.h"

using namespace std;

// 단어 추출 보조 함수 (단어+구두점 분리 유지)
string stripPunctuation(const string& word, string& punct) {
    int len = word.length();
    int i = len - 1;
    while (i >= 0 && ispunct(word[i])) {
        punct = word[i] + punct;
        i--;
    }
    return word.substr(0, i + 1);
}

int main() {
    //1. input file
    string textFileName, mapFileName;
    cout << "Enter text file name: ";
    cin >> textFileName;
    cout << "Enter map file name: ";
    cin >> mapFileName;

    BST bst;

    // 2. 맵 파일 로딩 및 BST 구성
    ifstream mapFile(mapFileName);
    if (!mapFile) {
        cerr << "Cannot open map file." << endl;
        return 1;
    }

    string line;
    while (getline(mapFile, line)) {
        size_t colon = line.find(':');
        if (colon != string::npos) {
            string key = line.substr(0, colon);
            string value = line.substr(colon + 1);
            // Trim spaces
            key.erase(0, key.find_first_not_of(" \t"));
            key.erase(key.find_last_not_of(" \t") + 1);
            value.erase(0, value.find_first_not_of(" \t"));
            value.erase(value.find_last_not_of(" \t") + 1);
            bst.insert(key, value);
        }
    }
    mapFile.close();

    // 3. 텍스트 파일 읽고 바꿔서 출력
    ifstream textFile(textFileName);
    if (!textFile) {
        cerr << "Cannot open text file." << endl;
        return 1;
    }

    while (getline(textFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            string punct = "";
            string pure = stripPunctuation(word, punct);
            string replacement = bst.find(pure);
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
