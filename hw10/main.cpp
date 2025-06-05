#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
using namespace std;

/*
This system Given a text file, find 5 most frequent words and their frequency.
*/


// I use Insertion Sort Because it's most words are 2048, Insertion sort is good to use when data does not have many information
// and it's implementation is not hard

#define NUM 5 //number of most frequent word

//remove punctuation in words
string removePunctuation(const string& word) {
    string clean = "";
    for(char c : word){
        if(!ispunct(c)) clean += c;
    }
    return clean;
}

//make upperCase
string toUpperCase(string &word){
    for(int i =0; i<word.length(); i++){
        word[i] = toupper(word[i]);
    }
    return word;
}

//make lowercase
string toLowerCase(string &word){
    for(int i =0; i<word.length(); i++){
        word[i] = tolower(word[i]);
    }
    return word;
}

//inserting sort
void printMax(string arr[], int num_arr[], int count){
    for(int i=1; i<count; i++){
        string word = arr[i];
        int num = num_arr[i];
        
        int j = i-1;
        //when number is lower or alpha is lower go right
        while(j>=0 && (num_arr[j] < num || (num_arr[j] == num) && arr[j] > word)){
            arr[j+1] = arr[j];
            num_arr[j+1] = num_arr[j];
            j--;
        }
        arr[j+1] = word;
        num_arr[j+1] = num;
    }
}

int main(){
    string filename;
    cout << "input file name: ";
    cin >> filename;
    ifstream file(filename); 
    
    string line;
    string word;
    string arr[2048]; //max 2048 words
    int num_arr[2048] = {0};
    int count = 0;

    while(getline(file,line)){
        istringstream iss(line);

        while(iss >> word){
            word = toLowerCase(word);
            word = removePunctuation(word);
            bool isduplicated = false;
            for(int i=0; i<count; i++){
                if(arr[i] == word){ // if duplicated don't append but increase number
                    isduplicated = true;
                    num_arr[i] ++;
                    break;
                }
            }if(!isduplicated){ //if not duplicated append word in list
                arr[count] = word;
                num_arr[count] ++;
                count ++;
            }
        }
    }

    printMax(arr,num_arr,count); //sort

    //print
    for(int i=0; i<NUM; i++){
        cout << toUpperCase(arr[i]) << ": " << num_arr[i] << endl;
    }   


    return 0;
}