#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

int *inter(int a){
    int i;
    int *inteiro = (int*)calloc(a,sizeof(int));

    for (i = 0; i < a; i++){
        inteiro[i]= rand() % 101;
    }

    return  inteiro;
}

char *chart(int b){
    int i;
    char *chacter = (char*)calloc(b,sizeof(char));

    for (i = 0; i < b; i++){
        chacter[i]= 65 + rand() % 26;
    }

    return chacter;
}

float *floa(int c){
    int i;
    float *flo = (float*)calloc(c, sizeof(char));

    for (i = 0; i < c; i++){
        float aux = rand() % 100;
        flo[i]= ((rand() % 100)/aux) ;
    }

    return flo;
}

int **mat(int d, int e){

    int i, j;
    int **mat = (int**)calloc(d, sizeof(int));

    for (i = 0; i < d; i++){
        mat[i] = (int*)calloc(e, sizeof(int));

        for (j = 0; j < e; j++){  
            mat[i][j]= rand() % 100;
        } 
    }

    return mat;
}

int main(){
    srand(time(NULL));
    int a, b, c, d, e, i, j;

scanf("%d", &a);
scanf("%d", &b);
scanf("%d", &c);
scanf("%d", &d);
scanf("%d", &e);

int *v = inter(a); 

for (i = 0; i < a; i++){
  printf (" %d", v[i]);
}

printf("\n \n");


char *cha = chart(b);
for (i = 0; i < b; i++){
  printf (" %c ", cha[i]);
}

printf("\n \n");

float *f = floa(c);
for (i = 0; i < c; i++){
  printf (" %f ", f[i]);
}

printf("\n \n");

int **m = mat(d,e);

for (i = 0; i < d; i++){
    for ( j= 0; j < e; j++){
        printf (" %d\t", m[i][j]);
    }
    printf("\n");
}

printf("\n");

free(v);
free(cha);
free(f);
free(m);

return 0;
}