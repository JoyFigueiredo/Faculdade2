#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char* parametro1 = argv[1]; //1 parametro arquivo1.txt
    char* parametro2 = argv[2]; 	

    if (argc < 3){
        printf("Não foi digitado corretamente!");
        return -1;
    }

    FILE* texto = fopen( argv[1], "r" );
    int chave = atoi(argv[2]);

    if(texto == NULL){
        printf("não leu nada");
    }

    char vetorLinhas[256], vetorAux[256] ;

    char c; 
    int i =0, aux, j=0; 

    while((c = fgetc(texto)) != EOF && c != '\n') {
        vetorLinhas[i] = c;
        i++;
    }
    FILE* f; 
    f = fopen("ciffrada.txt","w");

    for(i =0 ; i< strlen(vetorLinhas); i++){ //122 = z 96 antes do a 
       if(vetorLinhas[i]!=32){
            aux = vetorLinhas[i] + chave;

            if(aux > 122){
                vetorAux[i] = (96 + aux) - 122;
            }else{
                vetorAux[i] = aux;
            }
            fputc(vetorAux[i], f);
        }
    }

    fclose(texto);
  return 0;

}