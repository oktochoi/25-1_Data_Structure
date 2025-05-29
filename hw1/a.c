#include <stdio.h> 
#include <limits.h> 

//input: file
//output find min number in file

void findSmallNumber(char *filename);

int main(){

    findSmallNumber("file1.txt");

    findSmallNumber("file2.txt");

    findSmallNumber("file3.txt");


    return 0;
}

void findSmallNumber(char *filename){
    printf("Input filename: %s\n", filename);

    FILE *fp = fopen(filename, "r");

    int temp;
    int min = INT_MAX; // To remove exception use: INT_MAX

    
    //!feof(fp)로 했을때 문제점 파일 끝에 도달해야 true가 되므로, 실패한 fscanf 이후 한번 더 루프를 돔
    while(fscanf(fp,"%d",&temp) == 1){
        if(temp < min){
            min = temp;
        }
    }

    fclose(fp); //  deallocation 

    printf("The smallest number is %d\n\n",min); //output
}