#include <stdio.h>
#include <string.h> 
#include <ctype.h> 

void upDown(char* word);

//input: any sentences
//output: if islower -> uppercase || uppercase -> lowercase

int main(){

    char word[100]; //input sentence

    printf("input word\n");
    fgets(word, sizeof(word), stdin); 

    upDown(word);
    printf("%s",word);

    return 0;
}

void upDown(char* word){
    for(int i =0; i<strlen(word); i++){
        if(isalpha(word[i])){ //when isalpha
            if(isupper(word[i])){ //if is upper make to lower
                word[i] = tolower(word[i]);
            }else{//if is lower make to upper
                word[i] = toupper(word[i]);
            }
        }
    }
}