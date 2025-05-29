#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//a program that reads a matrix from a file and adds, multiplies, and changes rows with each input

float** make2dArray(int h, int w);
float** read_matrix(const char* filename, int* h, int* w);
float** add_matrix(float** a, int h1, int w1, float** b, int h2, int w2);
float** mul_matrix(float** a, int ah, int aw, float** b, int bh, int bw); 
void print_matrix(float** mat, int h, int w);
float** transpose_matrix(float** a, int ah, int aw);
void free2dArray(float** arr, int h);

int main(){
    char options;
    char file1[100], file2[100];

    printf("What operation do you want? (‘a’, ‘m’, ‘t’)");
//1) Read an operation character,
    scanf(" %c",&options);
    
    //input multiple txt.files
    if(options =='a' || options == 'm'){ //when add and multiple choice
        printf("Input files names:");
        scanf("%s",file1);
        scanf("%s",file2);

        int ah, aw, bh, bw;
        float** a = read_matrix(file1, &ah, &aw);
        float** b = read_matrix(file2, &bh, &bw);

        float** res = NULL;
        if (options == 'a') {
            res = add_matrix(a, ah, aw, b, bh, bw);
        }else if (options == 'm') {
            res = mul_matrix(a, ah, aw, b, bh, bw);
        }

        if(res == NULL){
            printf("Matrix dimensions mismatch\n");
        }else{
            int rh = ah;
            int rw = (options == 'a') ? aw : bw; //if add result of width will be
            print_matrix(res, rh, rw);
            free2dArray(res, rh);
        }

        free2dArray(a, ah);
        free2dArray(b, bh);

    }else if (options == 't'){//transpose matrix,one input
        printf("Input file name:\n");
        scanf("%s", file1);

        int h,w;
        float** a = read_matrix(file1,&h,&w);
        float** result = transpose_matrix(a,h,w);

        print_matrix(result, w, h);
        
        free2dArray(a, h);
        free2dArray(result, w);
    }else{
        printf("Invalid operation.\n");
    }

    return 0;
}

//malloc to array
float** make2dArray(int h, int w) {
    float** arr = (float**)malloc(h * sizeof(float*));
    for(int i=0; i<h; i++){
        arr[i] = (float*)malloc(w * sizeof(float));
    }
    return arr;
}

//loat matrix
float** read_matrix(const char* filename, int* h, int* w) {
    FILE* fp = fopen(filename, "r");

    fscanf(fp, "%d %d", h, w);
    float** mat = make2dArray(*h, *w);
    for (int i = 0; i < *h; i++) {
        for (int j = 0; j < *w; j++) {
            fscanf(fp, "%f", &mat[i][j]);
        }
    }
    fclose(fp);
    return mat;
}

//add_matrix
float** add_matrix(float** a, int ah, int aw, float** b, int bh, int bw) {
    if (ah != bh || aw != bw) return NULL; // condition of add_matrix
    float** res = make2dArray(ah, aw);
    for (int i = 0; i < ah; i++) {
        for (int j = 0; j < aw; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
    return res;
}

//mul_matrix
float** mul_matrix(float** a, int ah, int aw, float** b, int bh, int bw) {
    if (aw != bh) return NULL; // condition of multiple_matrix
    float** res = make2dArray(ah, bw);
    for (int i = 0; i < ah; i++) {
        for (int j = 0; j < bw; j++) {
            res[i][j] = 0;
            for (int k = 0; k < aw; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

// transpose_martrix
float** transpose_matrix(float** a, int ah, int aw) {
    float** res = make2dArray(aw, ah);
    for (int i = 0; i < ah; i++) {
        for (int j = 0; j < aw; j++) {
            res[j][i] = a[i][j];
        }
    }
    return res;
}


//print_matrix
void print_matrix(float** mat, int h, int w) {
    printf("%d %d\n", h, w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%.1f ", mat[i][j]);
        }
        printf("\n");
    }
}

//free_array
void free2dArray(float** arr, int h) {
    for (int i = 0; i < h; i++) {
        free(arr[i]);
    }
    free(arr);
}   