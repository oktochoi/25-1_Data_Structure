#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//input: file
//output: result of sum of numbers in file
double sum(char *filename);

int main() {
    char filename[100];
    double total;

    printf("Input filename: ");
    scanf("%s", filename);

    total = sum(filename);

    printf("The sum is %.2f\n", total);

    return 0;
}

double sum(char *filename) {
    FILE *fp = fopen(filename, "r");

    char ch; 
    char number[50]; //space to save continuous number
    int i = 0; //index
    double sum = 0.0; //sum

    while ((ch = fgetc(fp)) != EOF) { 
        if (isdigit(ch) || ch == '.') {// if digit or . save in number[i]
            number[i++] = ch;
        } else { // if there is number in array convert float and add to sum
            if (i > 0) {
                number[i] = '\0'; //don't initialize array so we need to spcify where is end
                sum += atof(number);
                i = 0; //reset i
            }
        }
    }

    fclose(fp);
    return sum;
}
