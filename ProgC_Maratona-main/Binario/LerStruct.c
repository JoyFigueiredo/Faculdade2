#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Aluno{
    char nome[100];
    int idade;
    float nota;
}A;

int main(){

    A *v;
    int a =-1;
    FILE *arq;
    arq = fopen("Alunos.dat", "rb");

    while (a < 0 || a > 4){
        printf("Digite um valor de 0 - 4: ");
        scanf("%d", &a);
    }

    fseek(arq, (a) * sizeof(A), SEEK_SET);
    fread(v, sizeof(A), 1, arq);

    printf("Nome: %s\n", v->nome);
    printf("Idade: %d\n", v->idade);
    printf("Nota: %.2f\n", v->nota);

    fclose(arq);
    return 0;
}