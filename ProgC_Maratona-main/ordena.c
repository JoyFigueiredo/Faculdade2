#include <stdio.h>
#include <string.h>
#define swap( a, b ) do{ int tmp = a; a = b; b = tmp; } while(0)

int vetor[10] = {2, 0, 5, 9, 3, 7, 1, 6, 4, 8};

// Swap vizualização 
/*
void swap(int *a, int *b){
    int temporario;
    temporario = *a;
    *a = *b;
    *b = temporario;
}  // uma bolha digamos.

*/
void ordena(int v[], int size){
    int aux = 0, i =0, j= 0;

    for (i = 0; i < (size - 1); i++){
        aux=i;
        for ( j = (i+1); j < size; j++){
            if(v[j]< v[aux]){
                aux =j;
            }
        }    
        if(i != aux){
            swap(v[i], v[aux]); //Troca de posição;
        }
        
    }
}

void imprime(int v[], int size){
    int i;
    for (i = 0; i < size; i++){
        printf("%d  ", v[i]);
    }
}

int main(){
    printf("Vetor Original: ");
    imprime(vetor, 10);

    ordena(vetor, 10);

    printf("Vetor Ordenado: ");
    imprime(vetor, 10);

    return 0;
}