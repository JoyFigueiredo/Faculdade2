#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<ctype.h>

int main(){
    int tam , i, j=0, k;

    scanf("%d", &tam);

    char c[tam],copiaC[tam];

    scanf("%tam[^\n]", c);

    for (i = 0; i < tam; i++){
        c[i] = tolower(c[i]);
    }

    /*
    for(i = 0; i < strlen(c); i++){
        if(c[i] != "!" && c[i] != "?" && c[i] != " " && c[i] != ".")

        //copiaC[j++] = c[i];
    }
*/
    //copiaC[j] = '\0';

    //printf("Original: %s\n Copia:%s\n", c, copiaC);

    strcpy(copiaC, c);

    strrev(copiaC);

    k = strcmp(c, copiaC);
/*
    tam = strlen(copiaC);
    tam--;
    for(i = 0; i < strlen(copiaC); i++){
        if(copiaC[i] != copiaC[tam])
            k++;
        tam--;
    }
    */

    if(k == 0)
        printf("\n S\n");
    else
        printf("\n N \n");

    return 0;
}