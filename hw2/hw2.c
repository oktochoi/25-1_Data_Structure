#include <stdio.h>
#include <string.h>
#include <ctype.h>

//input 2 sentences
//output: number of A~9

void count(char* sentence, int alpha[], int num[]);
void printnum(int alpha[], int num[]);

int main(){

    int alpha[26] = {0};
    int num[10] = {0};
    char sentence1[50];
    char sentence2[50];

    printf("Input sentence1: ");
    fgets(sentence1, sizeof(sentence1), stdin);

    printf("Input sentence2: ");
    fgets(sentence2, sizeof(sentence2), stdin);

    count(sentence1, alpha, num);
    count(sentence2, alpha, num);

    printnum(alpha, num);

    return 0;
}

void count(char* sentence, int alpha[], int num[]){
    
    for(int i=0; i<strlen(sentence); i++){
        if(isalpha(sentence[i])){
            alpha[toupper(sentence[i])-'A']++; //ifalpha toupper and -'A' and save it
        }else if(isdigit(sentence[i])){ //else -> number -'0' and save it 
            num[sentence[i]-'0']++;
        }
    }
}

void printnum(int alpha[], int num[]){

    //print alpha and number
    for(int i=0; i<26; i++){
        printf("%c:%d\n",'A'+i,alpha[i]);
    }

    for(int i=0; i<10; i++){
        printf("%c:%d\n",'0'+i,num[i]);
    }
}
