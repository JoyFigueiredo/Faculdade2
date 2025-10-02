#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    srand(time(NULL)); 

    int i;
    int vetor[100]; 

    for(i=0; i < 100 ; i++ ) {
        vetor[i] = 1 + (rand() %100);
    }

    FILE *arq;
    arq = fopen("Arq.dat", "wb");
    fwrite (vetor, sizeof(int), 100, arq );

return 0;
}