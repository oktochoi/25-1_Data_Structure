#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <algorithm>
using namespace std;

#define NUM 5
#define MAX_WORDS 2048

// remove punctuation in words
string removePunctuation(const string& word) {
    string clean = "";
    for (char c : word) {
        if (!ispunct(c)) clean += c;
    }
    return clean;
}

// make lowercase
string toLowerCase(string word) {
    for (char &c : word) c = tolower(c);
    return word;
}

// make uppercase
string toUpperCase(string word) {
    for (char &c : word) c = toupper(c);
    return word;
}

// struct of word
struct WordFreq {
    string word;
    int freq;
};

// rule of sort
bool compare(const WordFreq &a, const WordFreq &b) {
    if (a.freq != b.freq)
        return a.freq > b.freq; // freq of word
    return a.word < b.word;     // alpha of word
}

int main() {
    string filename;
    cout << "input file name: ";
    cin >> filename;
    ifstream file(filename);

    WordFreq arr[MAX_WORDS];
    int count = 0;
    string line, word;

    while (getline(file, line)) {
        istringstream iss(line);
        while (iss >> word) {
            word = toLowerCase(removePunctuation(word));
            if (word.empty()) continue;

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (arr[i].word == word) {
                    arr[i].freq++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                arr[count].word = word;
                arr[count].freq = 1;
                count++;
            }
        }
    }

    // sort -> compare is a rule for sort,
    sort(arr, arr + count, compare);

    // print 5 number
    for (int i = 0; i < min(NUM, count); i++) {
        cout << toUpperCase(arr[i].word) << ": " << arr[i].freq << endl;
    }

    return 0;
}
