#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <fstream>
#include "contact.h"


//load file and save it 
void Contact::load(string file_name) {
    FILE* fp = fopen(file_name.c_str(), "r");

    char* line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fp) != EOF) {
        persons[total_num++] = str2person(trim(line));
    }

    free(line);
    fclose(fp);
}

//print file
void Contact::print() {
    for (int i = 0; i < total_num; i++) {
        printf("[%s][%04d%02d%02d][%s][%s]\n",
               persons[i].name,
               persons[i].dob.year, persons[i].dob.month, persons[i].dob.day,
               persons[i].email, persons[i].phone);
    }
}

//Converting a one-line string to a Person object 
Person Contact::str2person(char* line) {
    Person p1;
    char* token;
    int i = 0;

    token = strtok(line, ";"); //char* strtok(char* str, char* delimiters); split str delimiters
    while (token) { 
        switch (i++) { //each token will be save 0,1,2,3
            case 0: strcpy(p1.name, trim(token)); break;
            case 1: p1.dob = str2date(trim(token)); break;
            case 2: strcpy(p1.email, trim(token)); break;
            case 3: strcpy(p1.phone, trim(token)); break;
        }
        token = strtok(NULL, ";");
    }

    return p1;
}

//Converting strings to Date structures
Date Contact::str2date(char* str) {
    Date date;
    char temp[10];

    strncpy(temp, str, 4); temp[4] = 0; //year
    date.year = atoi(temp);

    strncpy(temp, str + 4, 2); temp[2] = 0; //month
    date.month = atoi(temp);

    strncpy(temp, str + 6, 2); temp[2] = 0; //day
    date.day = atoi(temp);

    return date;
}

// Space removal function before and after string
char* Contact::trim(char* s) {
    char* ptr;
    if (!s) return NULL;
    while (isspace(*s)) s++; //remove front space
    for (ptr = s + strlen(s) - 1; (ptr >= s) && isspace(*ptr); --ptr);
    *(ptr + 1) = '\0'; //remove back space
    return s;
}